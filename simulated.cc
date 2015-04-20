/*===================================================================*/
/* C program for distribution from the Combinatorial Object Server.  */
/* Generate permutations by transposing adjacent elements            */
/* via the Steinhaus-Johnson-Trotter algorithm. This is              */
/* the same version used in the book "Combinatorial Generation."     */
/* Both the permutation (in one-line notation) and the positions     */
/* being transposed (as a 2-cycle) are output.                       */
/* The program can be modified, translated to other languages, etc., */
/* so long as proper acknowledgement is given (author and source).   */
/* Programmer: Frank Ruskey, 1995.                                   */
/* The latest version of this program may be found at the site       */
/* http://sue.uvic.ca/~cos/inf/perm/PermInfo.html                    */
/*===================================================================*/
#include <iostream>
#include <stdio.h>
#include <mysql.h>
#include <stdlib.h>
#include "session.h"
#include "room.h"
#include "author.h"
#include "functions.h"
#include "paper.h"
#include "sqlHelpers.h"

using namespace std;

int permutations[100], inv_perm[100];      /* The permutation and its inverse */
int dir[100];             /* The directions of each element  */

//PRE: num_sessions is defined as the number of the sessions that are going to be held
//     sessions[] is defined as the array of session IDs
//     num_authors is defined as the number of authors to be at the conference
//     authors[] is defined as the array of author IDs
//POST: Goes through the Johnson Trotter algorithm's array of permutations to 
//      send to the data base all possible permutations of sessions with authors 
//      changing in each permutation. Displays the number of conflicts with each 
//      permutation that may exist.
void printPerm(int num_sessions, session sessions[], int num_authors, author authors[]) {
  int count = 0;
  int check = 0;
  int conflicts = 0;
  int r_authors[num_authors];
  int r_sessions[num_authors]; //must be num_authors because the sessions are repeated for permute
  int permutationNum = getPermutationCount()+1;
  for (int i = 1; i <= num_authors; ++i) {
    if(i % num_sessions == 0) {
      count = 0;
    } else {
      count++;
    }
      cout << "Session " << sessions[count].getSessionID() << ": ";
      printf( "%d ", permutations[i]);
      check = permutations[i] - 1;
      r_authors[check] = permutations[i] - 1;
      r_sessions[count] = sessions[count].getSessionID();
      storePermutation(permutationNum,sessions[count].getSessionID(),permutations[i]);
      for(int q = 0; q < num_sessions; q++) {
	if(sessions[count].getSessionID() == authors[check].getUnavailableSessions()[q]) {
	  //ASSERT: The current session is in conflict with the current author.

	  conflicts++;
	}
      }
      cout << endl;
  }
  cout << "Conflicts for this permutation: " << conflicts << endl;
  cout << endl;
  storeConflicts (permutationNum, conflicts);
}

//PRE: counter is defined as where we are within the iterations
//     direct is the direction of the iteration we are going in
//POST: We have moved an iteration of the Johnson Trotter Algorithm
void move( int counter, int direct) {
  int curr_perm; //The current permutation
  curr_perm = permutations[inv_perm[counter]+direct];
  permutations[inv_perm[counter]] = curr_perm;
  permutations[inv_perm[counter]+direct] = counter;
  inv_perm[curr_perm] = inv_perm[counter];
  inv_perm[counter] = inv_perm[counter]+direct;
}

//PRE: n is a counter for where we are within the iterations of Johnson Trotter, when n
//     has become larger than the num_authors we know that we should print all the 
//     permutations
//     num_sessions is defined as the number of the sessions that are going to be held
//     sessions[] is defined as the array of session IDs
//     num_authors is defined as the number of authors to be at the conference
//     authors[] is defined as the array of author IDs     
//POST: Goes throught the permutations of the Johnson Trotter alogrithm. When n has become larger,
//      i.e. we have seen all possible permutations, we must send all permutations to the data base.
void permute(int n, int num_sessions, session sessions[],int num_authors, author authors[]) {
  int i;
  if (n > num_authors) {
    //ASSERT: n is larger than the number of authors, we need to print our permutations

    printPerm(num_sessions,sessions,num_authors,authors);
  }
  else {
    //ASSERT: n is smaller than the number of authors, we must continue to create permutations

      permute(n+1,num_sessions,sessions,num_authors,authors);
      for (int i = 1; i <= n-1; ++i) {
	  move(n,dir[n]);
	  permute(n+1,num_sessions,sessions,num_authors,authors);
	}
      dir[n] = -dir[n];
    } 
}

int main() {
  int total_time; //The total time, in minutes, that sessions may
		  //fill. I.e. 30 hours for 30 sessions(1 per hour).
  int num_rooms; //The amount of rooms available.
  int num_authors; //The number of authors to be present.
  int num_papers; //The amount of papers to be presented.
  int num_sessions; //The number of sessions that can be
		    //held.

  num_rooms = getRows("rooms");
  room rooms[num_rooms];
  fill_rooms(rooms,num_rooms);
  
  print_rooms(rooms,num_rooms);
  //ASSERT: Rooms created
    
  num_sessions = getRows("sessions");
  session sessions[num_sessions];
  fill_sessions(sessions,num_sessions,rooms,num_rooms);

  print_sessions(sessions,num_sessions);
  //ASSERT: Sessions created

  num_authors = getRows ("authors");
  author authors[num_authors];
  fill_authors(authors,num_authors,sessions,num_sessions);

  print_authors(authors,num_authors);
  //ASSERT: Authors created

  num_papers = getPapers("papers_authors");
  paper papers[num_papers];
  fill_papers(papers,num_papers,authors,num_authors);
  
  print_papers(papers,num_papers);
  //ASSERT: Papers created

  for (int i = 1; i <= num_authors; ++i) {
    dir[i] = -1; permutations[i] = i;
    inv_perm[i] = i;
  }
  clearTables();
  permute(1,num_sessions,sessions,num_authors,authors);
  printf("\n");
}
