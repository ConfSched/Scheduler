#include <iostream>
#include <mysql.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include "paper.h"
#include "room.h"
#include "author.h"
#include "session.h"
#include "config.h"

using namespace std;

// SQL Helper Functions

//Pre:  *con contains an error message
//Post:  The error message has been sent to the console
void dispSqlError(MYSQL *con)
{
  cerr << "About to display an error" << endl;
  fprintf(stderr, "%s\n", mysql_error(con));
  mysql_close(con);
  cerr << "Closing the connection" << endl;
  exit(1);
}

//Pre:  myCon is a MYSQL objec
//Post:  myCon is a valid connection to the database or an appropriate
//      error has been displayed
MYSQL * connect (MYSQL *myCon) {
  bool connectedStatus=true;
  myCon = mysql_init(NULL);
  if (myCon == NULL) {
    connectedStatus=false;
//    cerr << "myCon init  = NULL" << endl;
  }
  const char* serverLocation = serverAddress;
  const char* serverUser = username;
  const char* serverPass = password;
  const char* databaseName = dbName;
  if (mysql_real_connect(myCon, serverLocation, serverUser, serverPass, databaseName,
            0, NULL, 0) == NULL){
    dispSqlError(myCon);
    connectedStatus=false;
//    cerr << "myCon real connect = NULL" << endl;
  }
//  cerr << "Connected Status = " << connectedStatus << endl;
  return myCon;//(connectedStatus);
}

//Pre:
//Post:  returns the number of rows in the specified table
int getRows (const char* tableName) {
  int RV;
  const char* query = "SELECT * FROM ";
  char* queryName = new char[strlen(tableName)+strlen(query)+1];
  strcpy (queryName, query);
  strcat (queryName, tableName);
//  cerr << "about to connect (getRows)" << endl;
//  cerr << tableName << endl;
  MYSQL *myCon = connect(myCon);
  if (myCon != NULL){
//    cerr << "getRows:  got a connection to " << tableName << endl;
//    cerr << "Query = *" << queryName << "*" << endl;
//    cerr << mysql_query(myCon, queryName);
    if (mysql_query(myCon, queryName)) dispSqlError(myCon);
    else {
//      cerr << "getRows:  Ran the query, storing result" << endl;
      MYSQL_RES *result = mysql_store_result(myCon);
      if (result == NULL) dispSqlError(myCon);
      else RV = mysql_num_rows(result);
    }
  }
//  else cerr << "Failed to connect to SQL database" << endl;
  return (RV);
}

//PRE
//POST:  RV is the number of distinct paper IDs in the specified table
int getPapers (const char* tableName) {
  int RV = 0;
  const char * query = "SELECT DISTINCT paper_id FROM ";
  char* queryName = new char[strlen(tableName)+strlen(query)+1];
  strcpy (queryName, query);
  strcat (queryName, tableName);
  MYSQL *myCon = connect(myCon);
  if (myCon!=NULL) {
    if (mysql_query(myCon, queryName)) dispSqlError(myCon);
    else {
      MYSQL_RES *result = mysql_store_result(myCon);
      if (result == NULL) dispSqlError(myCon);
      else RV = mysql_num_rows(result);
    }
  }
  return (RV);
}

//PRE
//POST:  RV is the ID of the specified paper
int getPaperID (int paperNum) {
  int RV = 0;
  const char * query = "SELECT DISTINCT paper_id FROM papers_authors";
  MYSQL *myCon=connect(myCon);
  if (myCon!=NULL){
    if (mysql_query(myCon, query)) dispSqlError(myCon);
    else {
      MYSQL_RES *result = mysql_store_result(myCon);
      if (result == NULL) dispSqlError(myCon);
      else if (mysql_num_rows(result)>paperNum) {
        MYSQL_ROW row;
        for (int i=0; i<=paperNum; i++) row = mysql_fetch_row(result);
        RV = atoi(row[0]);
      }
      else RV = -1;
    }
  }
  return (RV);
}

//PRE
//POST RV is the ID for the room number in the 'rooms' table
int getRoomID (int roomNum) {
  int RV = 0;
  MYSQL *myCon=connect(myCon);
  if (myCon!=NULL) {
    const char * query = "SELECT * FROM rooms";
//    cerr << "After char * query before if" << endl;
    if (mysql_query(myCon, query)) {
//      cerr <<"in if" << endl;
      dispSqlError(myCon); 
    }
    else {
//      cerr << "start else" << endl;
      MYSQL_RES *result = mysql_store_result(myCon);
//      cerr << "before nested if" << endl;
      if (result == NULL) {
        dispSqlError(myCon);
//        cerr << "After nested if" << endl;
      }
      else if (mysql_num_rows(result)>roomNum) {
//        cerr << "start nested else" << endl;
        MYSQL_ROW row;
        for (int i=0; i<=roomNum; i++) row = mysql_fetch_row(result);
        RV = atoi(row[0]);
      }
      else RV = -1;
      }
    return (RV);
  }
}

/*
//PRE
//POST:  RV is the paper ID for the provided paper number 
int getPaperSession (int paperNum, MYSQL *myCon) {
  int RV = 0;
  const char * query = "SELECT * from sessionpaper WHERE paper_id = ";
  char* pNumStr;
  sprintf (pNumStr, "%d", paperNum);
  char* fullQuery = new char[strlen(query)+strlen(pNumStr)+1];
  strcpy (fullQuery, query);
  strcat (fullQuery, pNumStr);
  if (mysql_query(myCon, fullQuery)) dispSqlError(myCon);
  else {
    MYSQL_RES *result = mysql_store_result(myCon);
    if (result == NULL) dispSqlError(myCon);
    else {
      MYSQL_ROW row;
      RV = atoi(row[1]);
    }
  }
  return (RV);
}*/

//PRE authorNum is the number of the author to retrieve
//POST RV is the ID of the specified author
int getAuthorID (int authorNum) {
  int RV = 0;
  const char * query = "SELECT DISTINCT id FROM authors";
//  cerr <<"getAuthorID: about to connect.  authorNum = " << authorNum << endl;
  MYSQL *myCon=connect(myCon);
  if (myCon!=NULL){
//    cerr << "getAuthorID: connected, myCon != NULL" << endl;
    if (mysql_query(myCon, query)) dispSqlError(myCon);
    else {
//      cerr << "getAuthorID: ran the query" << endl;
      MYSQL_RES *result = mysql_store_result(myCon);
      if (result == NULL) dispSqlError(myCon);
      else if (mysql_num_rows(result)>authorNum) {
//        cerr << "getAuthorID: stored query result" << endl;
        MYSQL_ROW row;
        for (int i=0; i<=authorNum; i++) row = mysql_fetch_row(result);
        RV = atoi(row[0]);
//        cerr << "getAuthorID: RV = " << RV << endl;
      }
      else RV = -1;
    }
  }
//  cerr << "getAuthorID: Done, returning " << RV << " to calling function for authorNum " << authorNum << endl;
  return (RV);
}




int getAuthorPaper (int authorNum, int paperNum) {
  int RV = 0;
  const char * query =  "SELECT author_id from papers_authors WHERE paper_id = ";
  char pNumStr[1000] = {0};
  sprintf (pNumStr, "%d",  paperNum);
  char* fullQuery = new char[strlen(query)+strlen(pNumStr)+1];
  strcpy (fullQuery, query);
  strcat (fullQuery, pNumStr);
  MYSQL *myCon=connect(myCon);
  if (myCon!=NULL) {
    if (mysql_query(myCon, fullQuery)) dispSqlError(myCon);
    else {
      MYSQL_RES *result = mysql_store_result(myCon);
      if (result == NULL) dispSqlError(myCon);
      else if (mysql_num_rows(result)>authorNum) {
        MYSQL_ROW row;
        for (int i=0; i<=authorNum; i++) row = mysql_fetch_row(result);
        RV = atoi(row[0]);
      }
    }
  }
  return (RV);
}

int getSessionID (int sessionNum) {
  int RV = 0;
  const char * query = "SELECT * from sessions";
  MYSQL *myCon=connect(myCon);
  if (myCon!=NULL){
    if (mysql_query(myCon, query)) dispSqlError(myCon);
    else {
      MYSQL_RES *result = mysql_store_result(myCon);
      if (result == NULL) dispSqlError(myCon);
      else {
        MYSQL_ROW row;
        for (int i=0; i<=sessionNum; i++) row = mysql_fetch_row(result);
        RV = atoi(row[0]);
      }
    }
  }
  return (RV);
} 

int getAuthorConflict (int conflictNum, int authorNum) {
  int RV = 0;
  const char * query = "SELECT * from authors_sessions_constraints where author_id = ";
  char* NumStr;
  sprintf (NumStr, "%d", authorNum);
  char* fullQuery = new char[strlen(query)+strlen(NumStr)+1];
  strcpy (fullQuery, query);
  strcat (fullQuery, NumStr);
  //cerr << "getting conflict " << conflictNum << " for author " << authorNum;
  //cerr << " using query : " << fullQuery << endl;
  MYSQL *myCon=connect(myCon);
  if (myCon!=NULL) {
    if (mysql_query(myCon, fullQuery)) dispSqlError(myCon);
    else {
      MYSQL_RES *result = mysql_store_result(myCon);
      if (result == NULL) dispSqlError(myCon);
      else if (mysql_num_rows(result)>conflictNum) {
        MYSQL_ROW row;
        for (int i=0; i<=conflictNum; i++) row = mysql_fetch_row(result);
        RV = atoi(row[2]);
      }
    }
  }
  //cerr << "getAuthorConflict:  author " << authorNum;
  //cerr << " has a conflict with session " << RV << endl;
  return (RV);
}

//PRE
//POST:  RV is the number of rows in the permutations table of confsched
int getPermutationCount () {
  int RV = -1;
  const char * query = "SELECT distinct permutation_id from permutations";
  MYSQL *myCon = connect(myCon);
  if (myCon!=NULL) {
    if (mysql_query(myCon, query)) dispSqlError(myCon);
    else {
      MYSQL_RES *result = mysql_store_result(myCon);
      if (result == NULL) dispSqlError(myCon);
      else RV = mysql_num_rows(result);
    }
  }
  return (RV);
}


//PRE: permID, sessionID, authorID are positive integers
//POST:  A row has been added to permutations containing the input data
void storePermutation (int permID, int sessionID, int authorID) {
  const char * query = "INSERT INTO permutations (permutation_id, session, author) VALUES (";
  char permIDStr[1000] = {0};
  char sessionIDStr[1000] = {0};
  char authorIDStr[1000] = {0};
  sprintf (permIDStr, "%d, ",  permID);
  sprintf (sessionIDStr, "%d, ", sessionID);
  sprintf (authorIDStr, "%d)", authorID);
  char* fullQuery = new char[strlen(query)+strlen(permIDStr)+strlen(sessionIDStr)+strlen(authorIDStr)+1];
  strcpy (fullQuery, query);
  strcat (fullQuery, permIDStr);
  strcat (fullQuery, sessionIDStr);
  strcat (fullQuery, authorIDStr);
//  cerr << "storePermutation: Query = *" << fullQuery << "*" << endl;
  //cerr << "getting conflict " << conflictNum << " for author " << authorNum;
  //cerr << " using query : " << fullQuery << endl;
  MYSQL *myCon=connect(myCon);
  if (myCon!=NULL) mysql_query(myCon, fullQuery);
}

//PRE: permID and conflictCount are positive integers
//POST: a row has been added to conflicts indicating the number of conflicts for the provided permutation id
void storeConflicts (int permID, int conflictCount) {
  const char * query = "INSERT INTO conflicts (permutation_id, num_conflicts) VALUES (";
  char permIDStr[1000] = {0};
  char conflictStr[1000] = {0};
  sprintf (permIDStr, "%d, ",  permID);
  sprintf (conflictStr, "%d)", conflictCount);
  char* fullQuery = new char[strlen(query)+strlen(permIDStr)+strlen(conflictStr)+1];
  strcpy (fullQuery, query);
  strcat (fullQuery, permIDStr);
  strcat (fullQuery, conflictStr);
//  cerr << "storeConflicts: Query = *" << fullQuery << "*" << endl;
  MYSQL *myCon=connect(myCon);
  if (myCon!=NULL) mysql_query(myCon, fullQuery);
}

//PRE:
//POST:  permutations and conflicts have been dropped and recreated in  the database
void clearTables() {
  MYSQL *myCon=connect(myCon);
  if (myCon!=NULL) {
    const char * query = "DROP table conflicts";
    mysql_query (myCon, query);
    query = "DROP table permutations";
    mysql_query (myCon, query);
    query = "CREATE TABLE conflicts (permutation_id INT UNSIGNED NOT NULL PRIMARY KEY, num_conflicts int(10) UNSIGNED)";
    mysql_query (myCon, query);
    query = "CREATE TABLE permutations (permutation_id INT UNSIGNED NOT NULL, session INT UNSIGNED NOT NULL, author INT UNSIGNED NOT NULL, PRIMARY KEY (permutation_id,session,author))";
    mysql_query (myCon, query);
}}
