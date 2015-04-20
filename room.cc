#include "room.h"
#include <iostream>

using namespace std;
  
// =========================================
// Constructors
// =========================================
room::room() {}

// =========================================
// Modifier Functions
// =========================================  

//Pre: room_size is defined
//Post: sets the size of a room of the room
void room::setRoomSize(int size){
  room_size = size;
}

//Pre: equipment is defined
//Post: sets a bool value to if the room can have or has equipment 
void room::setEquipment(bool equipment) {
  room_equipment = equipment;
}

//Pre: id is defined
//Post: sets an id to the room
void room::setID(int id) {
  room_id = id;
}

// =========================================
// Accessor Functions
// =========================================

//Pre: 
//Post: gets the room size of the room
int room::getRoomSize() const {
  return(room_size);
}

//Pre: 
//Post: gets the bool value of equipment
bool room::getEquipment() const {
  return(room_equipment);
}

//Pre: 
//Post: gets the id of the room 
int room::getRoomID() const {
  return(room_id);
}

//Pre: 
//Post:  prints the room values
void room::print() const {
  cout << "Room ID:  " << room_id << " | Room Size:  "<< room_size << " | Room Equipment: " << room_equipment;
}
