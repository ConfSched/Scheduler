#ifndef INCLUDED_session
#define INCLUDED_session
#include "room.h"

class session {
 public:
  
  int session_id; //The of the session.
  int session_room; //The room of the session
  int sessionPapers[256]; //The papers of this session
  
  // =========================================
  // Constructors
  // =========================================
  session();

  // =========================================
  // Modifier Functions
  // =========================================  

  //Pre: id is defined
  //Post: The id of the session needs to be defined.
  void setID(int id);

  //Pre: room_id is defined as the room of the session
  //     rooms is defined as the set of available rooms
  //Post: room of this session is defined
  void setRoom(int room_id);
  
  //Pre: paper_id,paper_counter have both been defined
  //Post: The papers have been associated with this session
  void setSessionPapers(int paper_id, int paper_counter);
  
  // =========================================
  // Accessor Functions
  // =========================================
  
  //Pre: 
  //Post: gets the current ID of this session
  int getSessionID() const;

  //Pre: 
  //Post: gets the room of this session
  int getSessionRoom() const;

  //Pre: 
  //Post: gets the papers associated with this session
  int * getSessionPapers();

  //Pre: 
  //Post:  prints the session values
  void print() const;
};
#endif
