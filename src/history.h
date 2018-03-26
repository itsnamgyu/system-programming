#include <stdio.h>

#define COMMAND_LENGTH 200

typedef struct _HistoryNode {
	struct _HistoryNode *next;
	char string[COMMAND_LENGTH];
	
} HistoryNode;

typedef struct _History {
	HistoryNode *head; // fake head
	HistoryNode *last;
} History;
/*	Description
 *	Stores command history as a linked-list
 */

History *new_history();
/*	Description
 *	Initiate memory for a valid history record
 */

void free_history(History *history);
/*	Description
 *  free memory and destroy history record
 */

void add_history(History *history, char *string);
/*	Description
 *  Add a previous command to a history record
 *
 *  Arguments
 *  char *string: the command string
 */

	
void fprint_history(FILE *out, History *history);
/*	Description
 *  Print the history to an output stream
 */

int has_history(History *history);
/*	Description
 *  Return whether there are any commands in the history record
 */
