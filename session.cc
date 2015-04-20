#include "session.h"
#include "room.h"
#include <iostream>

using namespace std;

// =========================================
// Constructors
// =========================================
session::session() {}

// =========================================
// Modifier Functions
// =========================================  

//Pre: id is defined
//Post: The id of the session needs to be defined.
void session::setID(int id){
  session_id = id;
}

//Pre: room_id is defined as the room of the session
//     rooms is defined as the set of available rooms
//Post: room of this session is defined
void session::setRoom(int room_id){
  session_room = room_id;
}

//Pre: paper_id,paper_counter have both been defined
//Post: The papers have been associated with this session
void session::setSessionPapers(int paper_id, int paper_counter) {
  sessionPapers[paper_counter] =  paper_id;
}
  
// =========================================
// Accessors
// =========================================
  
//Pre: 
//Post: gets the current ID of this session
int session::getSessionID() const {
  return(session_id);
}

//Pre: 
//Post: gets the room of this session
int session::getSessionRoom() const {
  return(session_room);
}

//Pre: 
//Post: gets the papers associated with this session
int * session::getSessionPapers() {
  return(sessionPapers);  
}

//Pre: 
//Post:  prints the session values
void session::print() const {
  cout << "Session " << session_id << ": Room: " << session_room;
}
