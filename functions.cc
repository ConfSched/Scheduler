#include <iostream>
#include <mysql.h>
#include "sqlHelpers.h"
#include "paper.h"
#include "room.h"
#include "author.h"
#include "session.h"

using namespace std;

// =========================================
// Room Functions
// =========================================

//Pre: rooms[] and num_rooms are both defined 
//Post: The input has been taken in from the user and the rooms have
//      their information associated with them. 
void fill_rooms(room rooms[], int num_rooms) {
  bool waiting_input = true; //The bool to determine if the user is
			     //correct. 
  int room_size; //Number of people that can fit in a room.
  int room_id; //The id of the room.
  char input; //The user input on room equipment.
  //MYSQL *con;
  //con = mysql_init(NULL);
  //bool errorState=false;
  //connectDB (con, errorState);
  for (int i=0; i < num_rooms; i++) {
    room_id = getRoomID(i);
    rooms[i].setID(room_id);
  }
}

//Pre: rooms[] and num_rooms are both defined 
//Post: Prints the rooms with their information
void print_rooms(room rooms[], int num_rooms) {
  for(int i=0; i < num_rooms; i++) {
    rooms[i].print();
    cout << endl;
  }
} 

// =========================================
// Session Functions
// =========================================

//Pre: sessions[] and num_sessions are both defined 
//Post: The input has been taken in from the user and the sessions have
//      their information associated with them. 
void fill_sessions(session sessions[], int num_sessions,room rooms[],int num_rooms) {
  int session_id; //The ID of the session
  int room_id; //The room the session is located in
  bool waiting_input = true;
  for (int i=0; i < num_sessions; i++) {
    while(waiting_input) {
      session_id = getSessionID(i); /*SEG FAULT*/
      sessions[i].setID(session_id);
      room_id = getRoomID(i);
      for(int j=0; j < num_rooms; j++){
	if(rooms[j].getRoomID() == room_id) {
	  sessions[i].setRoom(room_id);
	  waiting_input = false;
	}
      }
    }
    waiting_input = true;
  }
}

//Pre: sessions[] and num_rooms are both defined 
//Post: Prints the sessions with their information
void print_sessions(session sessions[], int num_sessions) {
  for(int i=0; i < num_sessions; i++) {
    sessions[i].print();
    cout << endl;
  }
} 


// =========================================
// Author Functions
// =========================================

//Pre: authors[] and num_authors are both defined 
//Post: The input has been taken in from the user and the authors have
//      their information associated with them. 
void fill_authors(author authors[], int num_authors,session sessions[], int num_sessions) {
  //TODO: The authors cant be written John Guidry, have to be JohnGuidry
  //      Can be fixed using cin.ignore

  bool waiting_input = true; //The bool to determine if the user is
			     //correct. 
  int author_id; //The ID of the author
  string author_name; //The name of the author
  string author_email; //The email of the author
  int session_id;
  for (int i=0; i < num_authors; i++) {
    int session_counter = 0;
    author_id = getAuthorID(i);
    authors[i].setID(author_id);
    int count = 0;
    while(waiting_input) {
      session_id = getAuthorConflict(count,authors[i].getID());
      count++;
      for(int j=0; j < num_sessions; j++){
	if(sessions[j].getSessionID() == session_id) {
	  authors[i].setUnavailSessions(session_id,session_counter);
	  session_counter++;
	} else if (session_id == 0) {
	  authors[i].setUnavailSessions(0,session_counter);
	  waiting_input = false;
	}
      }
    }
    waiting_input = true;
  }
}

//Pre: authors[] and num_authors are both defined 
//Post: Prints the authors with their information
void print_authors(author authors[], int num_authors) {
  int * authorConflicts;
  for(int i=0; i < num_authors; i++) {
    authors[i].print();
    authorConflicts = authors[i].getUnavailableSessions();
    for(int j=0; j < 256; j++){
      if(authorConflicts[j] != 0) { 
	cout << "Unavailable Session: " << authorConflicts[j];
      } else {
	j = 256;
      }
      cout << endl;
    }
  }
} 

// =========================================
// Paper Functions
// =========================================

//Pre: papers[] is the papers associated with the authors, num_papers is the number of papers,
//     sessions[] are the current sessions, num_sessions is the number of sessions
//Post: input has been taking and the papers[] are now filled out with information
void fill_papers(paper papers[], int num_papers,author authors[], int num_authors) {
  //TODO: The paper titles cant be written Angry Computers, have to be AngryComputers  
  //       Can be fixed with cin.ignore

  bool waiting_input = true; //The bool to determine if the user is
			     //correct. 
  int paper_id; //The ID of the paper
  string paper_title; //The name of the author
  int author_id; //The ID of the author
  int session_id; //The ID of the session

  for (int i=0; i < num_papers; i++) {
    int author_counter = 0;
    paper_id = getPaperID(i);
    papers[i].setID(paper_id);
    int count = 0;
    while(waiting_input) {
      author_id = getAuthorPaper(count,papers[i].getID());
      count++;

      for(int j=0; j < num_authors; j++) {
	if(authors[j].getID() == author_id) {
	  papers[i].setPaperAuthors(author_id,author_counter);
	  author_counter++;
	} else if (author_id == 0) {
	  papers[i].setPaperAuthors(0,author_counter);
	  waiting_input = false;
	}
      }
    }
    waiting_input = true;
  }
}

//Pre: papers[] and num_papers are both defined
//Post: Prints the papers with their information
void print_papers(paper papers[], int num_papers) {
  int * paperAuthors;
  for(int i=0; i < num_papers; i++) {
    papers[i].print();
    paperAuthors = papers[i].getPaperAuthors();
    for(int j=0; j < 256; j++){
      if(paperAuthors[j] != 0) { 
	cout << "Paper Authors: " << paperAuthors[j];
      } else {
	j = 256;
      }
      cout << endl;
    }
  }
}

