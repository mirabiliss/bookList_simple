#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Node.h"
#include "List.h"

int main(void) {
	Node* head = NULL, * tail = NULL;
	char c = '*';

	while (1) {
		printf("- to initialize list with all books from the file, press 'a', \
				\n- to enter a new book manually, press 'm', \
				\n- to sort list by authors' names, press 'n'\
				\n- to sort list by authors' surnames, press 's'\
				\n- to sort list by books' titles, press 't' \
				\n- to sort list by books' years of publishment, press 'y' \
 				\n- to sort list by books' numbers of pages, press 'p' \
				\n- to sort list by books' prices, press 'c' \
				\n- to display the list to output file, press 'd'\
				\n- to exit, press 'e'\n\n");
		c = getchar();
		switch (c) {
		case 'a':
			get_books(&head, &tail);
			break;
		case 'm':
			get_book_from_console(&head, &tail);
			break;
		case 'n':
			bubble_sort_by_name(&head);
			break;
		case 's':
			bubble_sort_by_surname(&head);
			break;
		case 't':
			bubble_sort_by_title(&head);
			break;
		case 'y':
			bubble_sort_by_year(&head);
			break;
		case 'p':
			bubble_sort_by_pages(&head);
			break;
		case 'c':
			bubble_sort_by_cost(&head);
			break;
		case 'd':
			displayList(&head);
			break;
		case 'e':
			exit(0);
		default:
			printf("something went wrong. try again.\n\n");
			break;
		}
	}



	return 0;
}