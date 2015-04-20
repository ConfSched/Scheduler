#ifndef INCLUDED_sqlHelpers
#define INCLUDED_sqlHepers


// SQL Helper Functions

MYSQL * connect (MYSQL *con);

//Pre:  *con contains an error message
//Post:  The error message has been sent to the console
void dispSqlError(MYSQL *con);

//Pre:
//Post:  returns the number of rows in the specified table
int getRows (const char* tableName);

//PRE:
//POST:  RV is the associated ID of the provided roomNum
int getRoomID (int roomNum);

//PRE
//POST  RV is the associated ID of the provided sessionNum
int getSessionID (int sessionNum);

//PRE
//POST:  RV is the number of distinct paper IDs in the specified table
int getPapers (const char* tableName);

//PRE:  paperNum is a valid paper in the database
//POST:  RV is the associated paper ID
int getPaperID (int paperNum);


//PRE authorNum is the number of the author to retrieve
//POST RV is the ID of the specified author
int getAuthorID (int authorNum);

//PRE  authorNum is the number of the author to retrieve (sequential)
//  paperNum is the ID number of the paper to locate
//POST  RV is the nTH author ID on the referenced paper (or 0 if nonexistent)
int getAuthorPaper (int authorNum, int paperNum);

int getAuthorConflict (int conflictNum, int authorNum);


//PRE
//POST:  RV is the number of rows in the permutations table of confsched
int getPermutationCount ();


//PRE: permID, sessionID, authorID are positive integers
//POST:  A row has been added to permutations containing the input data
void storePermutation (int permID, int sessionID, int authorID);

//PRE: permID and conflictCount are positive integers
//POST: a row has been added to conflicts indicating the number of conflicts for the provided permutation id
void storeConflicts (int permID, int conflictCount);

//PRE: 
//POST:  permutations and conflicts have been dropped and recreated in  the database
void clearTables();


//Pre:  myCon is a MYSQL objec
//Post:  myCon is a valid connection to the database or an appropriate
//      error has been displayed
//void connectDB (MYSQL *myCon, bool errorStatus);


#endif
