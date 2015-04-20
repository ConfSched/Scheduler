#ifndef INCLUDED_paper
#define INCLUDED_paper
#include <string>

using namespace std;

class paper {
 public:
  int id; // The id of the paper
  string title; //The title of the paper
  int paperAuthors[256]; //The authors of the paper
  int paperSession; //The session of this paper

  // =========================================
  // Constructors
  // =========================================
  paper();

  // =========================================
  // Modifier Functions
  // =========================================  

  //Pre: The id of the paper needs to be defined
  //Post: The id of the paper has been defined
  void setID(int paper_id);

  //Pre: The name of the paper has to be defined
  //Post: The name of the paper has been defined
  void setPaperTitle(string paper_title);

  //Pre: The email of the paper has to be defined
  //Post: The email of the paper has been defined
  void setPaperAuthors(int author_id, int author_counter);

  // Pre: session_id,session_counter of the paper has been defined
  // Post: paperSession is defined
  void setPaperSession(int session_id);
  
  // =========================================
  // Accessor Functions
  // =========================================
  
  //Pre: 
  //Post: The id of the paper has been defined and is returned.
  int getID() const;
  
  //Pre: 
  //Post: The name of the paper has been defined and and is returned.
  string getPaperTitle() const;

  //Pre: 
  //Post: The authors of the paper has been defined and is returned.
  int * getPaperAuthors();

  // Pre: 
  // Post: The session of the papers has been defined and is returned
  int getPaperSession();

  //Pre: 
  //Post: prints the paper values
  void print() const;
  
};
#endif
