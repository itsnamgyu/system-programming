#include "parser.h"

/*
 * This module is provides a clean interface to interpret commands
 * (ParsedCommand's) and run the appropriate function to execute that command.
 * 
 * Usage
 * Create a new Interpreter and add interpretable operations (OperationNode's)
 * to that Interpreter. Each operation has an operation string, the number
 * of arguments for that operation, and the function to call to execute that
 * operation.
 *
 * IMPORTANT: The signature of the function must be
 * int f(FILE *out, char *arg0, ..., char *argN);
 * * This will not be explicitly checked during complication nor run-time.
 *
 * Once you've set up the Interpreter, you can let the Interpreter interpret 
 * the user's command (converted to ParsedCommand). Just call the function
 * interpret(Interpreter ip, ParsedCommand pc), and the appropriate function
 * will be called with the user's arguments.
 */

typedef struct _OperationNode {
	char operation[OPERATION_LENGTH];
	int argument_count;
	void *function;
	struct _OperationNode *link;
} OperationNode;
/*
 * Linked-list node for storing the interpretable operations. Note that
 * the module treats the same operation with different number of arguments
 * as separate 'Operation's.
 */

typedef struct _Interpreter {
	OperationNode *head;
	FILE *output_stream;
} Interpreter;

Interpreter *new_interpreter(FILE *out);

void free_interpreter(Interpreter *ip);

void add_operation(Interpreter *ip, char *operation, 
		           int argument_count void *function);

int interpret(Interpreter *ip, ParsedCommand pc);
