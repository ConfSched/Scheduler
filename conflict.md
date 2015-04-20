*** Conflict Planning ***

// session is the session you are attempting to add paper to
// paper is the paper you are adding to the session 
bool conflict(Session session, Paper paper) {
	array authors = paper->authors;
	foreach(author) {
		array authorSessionConflicts = paper->author->getUnavailableSessions();

		if (ConstraintAuthorConflict(session, authorSessionConflicts)) {
			return true;
		}
	}
	
	return false;
}

void compute_permutations(int * original, int * current, int * left_over, int * all_perms) {
	if (left_over->size() == 1) { // doubt this works, need to get how many elements in left_over
		// add int in left_over to current
		current[current->size()] = left_over[0]; // doubt this works, need to add to end
		// add current to all_perms
		all_perms[all_perms->size()] = current; // doubt this works, need to add current to end of all perms
		// remove from current
	}
	else {
		// loop over left_over
		for (int i = 0; i < left_over->size(); i++) {
			// add to current
			// call compute_permutations with new current
			compute_permutations(original,current,left_over,all_perms);
			// remove from current
		}
	}
}


/*** Not needed anymore ***/
// Returns true if adding paper to session would result in author being in two places at same time
bool NaturalAuthorConflict(Session session, Paper paper, array concurrentSessions) {
	foreach(concurrentSessions) {
		foreach(concurrentSessions->papers) {
			foreach(current->authors) {
				int author = current->id;
				foreach(paper->authors) {
					if (current->id == author) {
						return true; // found conflict
					}
				}
			}
		}
	}

	return false; // did not find conflict
}

// Returns true if adding paper to session would violate constraint specified by admin
bool ConstraintAuthorConflict(Session session, array authorSessionConflicts) {
	foreach(authorSessionConflicts) {
		if (current == session->id)
			return true;
	}

	return false;
}


On Web App:
After openconf, generate a table full of authors linked by email so that authors have a unique id