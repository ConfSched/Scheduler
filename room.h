#ifndef INCLUDED_room
#define INCLUDED_room

class room {
 public:
  
  int room_size; //The amount of people that can fit in a room.
  bool room_equipment; //Determines if the room has equipment or not
  int room_id; //The id of the room
  //TODO: Time slot;
  
  // =========================================
  // Constructors
  // =========================================
  room();

  // =========================================
  // Modifier Functions
  // =========================================  

  //Pre: room_size is defined
  //Post: sets the size of a room of the room
  void setRoomSize(int size);

  //Pre: equipment is defined
  //Post: sets a bool value to if the room can have or has equipment 
  void setEquipment(bool equipment);

  //Pre: id is defined
  //Post: sets an id to the room
  void setID(int id);

  // =========================================
  // Accessor Functions
  // =========================================

  //Pre: 
  //Post: gets the room size of the room
  int getRoomSize() const;

  //Pre: 
  //Post: gets the bool value of equipment
  bool getEquipment() const;

  //Pre: 
  //Post: gets the id of the room 
  int getRoomID() const;

  //Pre: 
  //Post:  prints the room values
  void print() const;
};
#endif
