#include "author.h"
#include <iostream>

using namespace std;

// =========================================
// Constructors
// =========================================
author::author() {}

// =========================================
// Modifier Functions
// =========================================  

//Pre: The id of the author needs to be defined
//Post: The id of the author has been defined
void author::setID(int author_id) {
  id = author_id;
}

//Pre: The name of the author has to be defined
//Post: The name of the author has been defined
void author::setAuthorName(string author_name) {
  name = author_name;
}

//Pre: The email of the author has to be defined
//Post: The email of the author has been defined
void author::setAuthorEmail(string author_email) {
  email = author_email;
}

//Pre: The unavailable sessions of the author has to be defined
//Post: The unavailable sessions of the author is defined
void author::setUnavailSessions(int session_id,int session_counter) {
  authorSessionConflict[session_counter] = session_id;
}

// =========================================
// Accessor Functions
// =========================================

//Pre: 
//Post: The id of the author has been defined and is returned.
int author::getID() const{
  return(id);
}

//Pre: 
//Post: The name of the author has been defined and and is returned.
string author::getAuthorName() const{
  return(name);
}

//Pre: 
//Post: The email of the author has been defined and is returned.
string author::getAuthorEmail() const{
  return(email);
}

//Pre: 
//Post: The unavailable sessions of the author is defined and needs
//      to be returned. 
int * author::getUnavailableSessions() {
  return(authorSessionConflict);
}

//Pre: 
//Post: prints the author values
void author::print() const {
  cout << "Author " << id << ": "<< name << " Email: " << email << endl;
}
