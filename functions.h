#ifndef INCLUDED_functions
#define INCLUDED_functions
#include "paper.h"

// =========================================
// Room Functions
// =========================================

//Pre: rooms[] and num_rooms are both defined 
//Post: The input has been taken in from the user and the rooms have
//      their information associated with them. 
void fill_rooms(room rooms[], int num_rooms);

//Pre: rooms[] and num_rooms are both defined 
//Post: Prints the rooms with their information
void print_rooms(room rooms[], int num_rooms);

// =========================================
// Session Functions
// =========================================

//Pre: sessions[] and num_sessions are both defined 
//Post: The input has been taken in from the user and the sessions have
//      their information associated with them. 
void fill_sessions(session sessions[], int num_sessions,room rooms[],int num_rooms);

//Pre: papers[] is the list of papers. sessions[] is the list of
//     sessions. num_sessions is the number of sessions. num_papers is
//     the number of papers
//Post: the sessions now have the associated papers set to them
//void set_session(paper papers[], session sessions[], int num_sessions, int num_papers);

//Pre: sessions[] and num_rooms are both defined 
//Post: Prints the sessions with their information
void print_sessions(session sessions[], int num_sessions); 

//Pre: sessions[] is defined as the sessions. num_sessions is defined
//     as the number of sessions
//Post: the sessions and their papers association have been printed
//     out 
//void print_session_papers(session sessions[], int num_sessions);

// =========================================
// Author Functions
// =========================================

//Pre: authors[] and num_authors are both defined 
//Post: The input has been taken in from the user and the authors have
//      their information associated with them. 
void fill_authors(author authors[], int num_authors, session sessions[], int num_sessions);

//Pre: authors[] and num_authors are both defined 
//Post: Prints the authors with their information
void print_authors(author authors[], int num_authors);

// =========================================
// Paper Functions
// =========================================

//Pre: papers[] is the papers associated with the authors, num_papers is the number of papers,
//     sessions[] are the current sessions, num_sessions is the number of sessions
//Post: input has been taking and the papers[] are now filled out with information
void fill_papers(paper papers[], int num_papers,author authors[], int num_authors);

//Pre: papers[] and num_papers are both defined
//Post: Prints the papers with their information
void print_papers(paper papers[], int num_papers);

#endif
