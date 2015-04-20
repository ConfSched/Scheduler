#include <iostream>
#include <mysql.h>

#include "session.h"
#include "room.h"
#include "author.h"
#include "functions.h"
#include "paper.h"

#define serverAddress localhost
#define username cjdresearch
#define password s3nrs@ch!
#define dbName confsched


using namespace std;

void dispSqlError(MYSQL *con)
{
  fprintf(stderr, "%s\n", mysql_error(con));
  mysql_close(con);
  exit(1);        
}

//Pre:
//Post:  returns the number of rows in the specified table
int getRows (MYSQL *myCon, const string & tableName) {
	if (mysql_query(myCon, "SELECT * FROM " + tableName)) 
    dispSqlError(myCon);
  MYSQL_RES *result = mysql_store_result(myCon);
	if (result == NULL) dispSqlError(myCon);
  int RV = mysql_num_rows(result);
  return (RV);
}

void connectDB (MYSQL *myCon) {
  myCon = mysql_init(NULL);
  if (con == NULL) fprintf(stderr, "mysql_init() failed\n");
  string serverLocation = serverAddress;
  string serverUser = username;
  string serverPass = password;
  string databaseName = dbName;  
	if (mysql_real_connect(con, serverLocation, serverUser, serverPass, databaseName,
            0, NULL, 0) == NULL) dispSqlError(myCon);
}  

int main() {
  int total_time; //The total time, in minutes, that sessions may
		  //fill. I.e. 30 hours for 30 sessions(1 per hour).
  int numRooms; //The amount of rooms available.
  int numAuthors; //The number of authors to be present.
  int numPapers; //The amount of papers to be presented.
  int numSessions; //The number of sessions that can be
		    //held. (total_time / num_rooms)
  
	MYSQL *con;
  connectDB (con);
  numSessions = getRows(con, "sessions");
  numRooms = getRows (con, "rooms");
  numPapers = getRows (con, "papers");
  numAuthors = getRows (con, "authors");

  room rooms[numRooms];
  fill_rooms (rooms, numRooms);
  print_rooms(rooms, numRooms);
  //ASSERT: Rooms created

  session sessions[numSessions];
  fill_sessions(sessions,numSessions,rooms,numRooms);
  print_sessions(sessions,numSessions);
  //ASSERT: Sessions created

  author authors[numAuthors];
  fill_authors(authors,numAuthors,sessions,numSessions);
  print_authors(authors,numAuthors);
  //ASSERT: Authors created

  paper papers[numPapers];
  fill_papers(papers,numPapers,authors,numAuthors);
  print_papers(papers,numPapers);
  //ASSERT: Papers created

  //TODO: DO SOME MAGIC

  set_session(papers,sessions,numSessions,numPapers);

  print_session_papers(sessions,numSessions);

}
