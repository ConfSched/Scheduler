//Pre: add_session is the session to be added, add_paper is the paper
//     paper to be added
//Post:	returns true if there is a conflict with the session and the
//      paper to be added
//      returns false otherwise
bool conflict(session add_session, paper add_paper) {
     session[] current_sessions = add_session.getCurrentSession();
     int authorConlict[256];

     return(NaturalAuthorConflict(add_session,add_paper,current_sessions) ||
            ConstraintAuthorConflict(add_session, authorConflictSessions);		
}

bool constraintAuthorConflict(session add_session, int[] authorConflict) {
     //TODO: get paper.getAuthorID
     //      get author.getUnAvailSession
     //      check if match to add_session, return false if non-match     
}

