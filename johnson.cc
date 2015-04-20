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
#include <stdio.h>
#include <iostream>

using namespace std;

int size;
int permutations[100], inv_perm[100];      /* The permutation and its inverse */
int dir[100];             /* The directions of each element  */
int num_sessions = 2;

void printPerm() {
int count = 0;
  /* uncomment if you want to print the index of each perm  */
  /*
    count = count + 1;
    printf( "[%8d] ", count );
  */
  for (int i=1; i <= size; ++i) {
    //printf("%d", permutations[i]);
    if(i % num_sessions == 0) {
      count = 0;
    } else {
      count++;
      }
      cout << "Session " << count << ": ";
      printf( "%d ", permutations[i]);
    }
}

void printTrans( int x, int y ) {
  printf( " (%d %d)", x, y );
  printf( "\n" );
}

void move( int x, int d ) {
  int z;
  printTrans(inv_perm[x],inv_perm[x]+d);
  z = permutations[inv_perm[x]+d];
  permutations[inv_perm[x]] = z;
  permutations[inv_perm[x]+d] = x;
  inv_perm[z] = inv_perm[x];
  inv_perm[x] = inv_perm[x]+d;
}

void permute(int n) {
  if (n > size)
    printPerm();
  else
    {
      permute(n+1);
      for (int i=1; i <= n-1; ++i) //must remain <=
	{
	  move(n,dir[n]);
	  permute(n+1);
	}
      dir[n] = -dir[n];
    } 
}

int main () {

 size = 3;
 //int array[] = {1,2,3};
  for (int i=1; i <=size; ++i)
    {
      dir[i] = -1; permutations[i] = i;
      inv_perm[i] = i;
    }
  permute(1);
  printf("\n");
}
