#include "paper.h"
#include <iostream>

using namespace std;

// =========================================
// Constructors
// =========================================
paper::paper() {}

// =========================================
// Modifier Functions
// =========================================  

//Pre: The id of the paper needs to be defined
//Post: The id of the paper has been defined
void paper::setID(int paper_id) {
  id = paper_id;
}

//Pre: The name of the paper has to be defined
//Post: The name of the paper has been defined
void paper::setPaperTitle(string paper_title) {
  title = paper_title;
}

//Pre: The author_id,authoer_counter of the paper has been defined
//Post: paperAuthors has been defined
void paper::setPaperAuthors(int author_id, int author_counter) {
  paperAuthors[author_counter] = author_id;
}

// Pre: session_id,session_counter of the paper has been defined
// Post: paperSession is defined
void paper::setPaperSession(int session_id) {
  paperSession = session_id;
}

// =========================================
// Accessor Functions
// =========================================

//Pre: 
//Post: The id of the paper has been defined and is returned.
int paper::getID() const{
  return(id);
}

//Pre: 
//Post: The name of the paper has been defined and and is returned.
string paper::getPaperTitle() const{
  return(title);
}

//Pre: 
//Post: The authors of the paper has been defined and is returned.
int * paper::getPaperAuthors() {
  return(paperAuthors);
}

// Pre: 
// Post: The session of the papers has been defined and is returned
int paper::getPaperSession() {
  return(paperSession);
} 

//Pre: 
//Post: prints the author values
void paper::print() const {
  cout << "Paper " << id << ": "<< title << endl;
  cout << "Session " << paperSession << endl;
}
