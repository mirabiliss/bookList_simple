#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Node.h"
#include "List.h"

int main(void) {
	Node* head = NULL, * tail = NULL;

	get_books(&head, &tail);
	displayList(&head);

	return 0;
}