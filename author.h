#ifndef INCLUDED_author
#define INCLUDED_author
#include <string>

using namespace std;

class author {
public:
  int id; //The id of the author
  string name; //The name of the author
  string email; //The email of the author
  int authorSessionConflict[256]; //The unavailable sessions of the author
  
  // =========================================
  // Constructors
  // =========================================
  author();

  // =========================================
  // Modifier Functions
  // =========================================  
  
  //Pre: The id of the author needs to be defined
  //Post: The id of the author has been defined
  void setID(int author_id);

  //Pre: The name of the author has to be defined
  //Post: The name of the author has been defined
  void setAuthorName(string author_name);

  //Pre: The email of the author has to be defined
  //Post: The email of the author has been defined
  void setAuthorEmail(string author_email);

  //Pre: The unavailable sessions of the author has to be defined
  //Post: The unavailable sessions of the author is defined
  void setUnavailSessions(int session_id, int session_counter);

  // =========================================
  // Accessor Functions
  // =========================================

  //Pre: 
  //Post: The id of the author has been defined and is returned.
  int getID() const;

  //Pre: 
  //Post: The name of the author has been defined and and is returned.
  string getAuthorName() const;

  //Pre: 
  //Post: The email of the author has been defined and is returned.
  string getAuthorEmail() const;

  //Pre: 
  //Post: The unavailable sessions of the author is defined and needs
  //      to be returned. 
  int * getUnavailableSessions();

  //Pre: 
  //Post:  prints the author values
  void print() const;
};
#endif
