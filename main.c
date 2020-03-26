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
				\n- to find books of certain author, press 'f'\
				\n- to exit, press 'e'\n\n");
		c = getchar();
		getchar();

		if (c == 'a' || c == 'A') {
			get_books(&head, &tail);
		}
		else if (c == 'm' || c == 'M') {
			get_book_from_console(&head, &tail);
		}
		else if (c == 'n' || c == 'N') {
			bubble_sort_by_name(&head);
		}
		else if (c == 's' || c == 'S') {
			bubble_sort_by_surname(&head);
		}
		else if (c == 't' || c == 'T') {
			bubble_sort_by_title(&head);
		}
		else if (c == 'y' || c == 'Y') {
			bubble_sort_by_year(&head);
		}
		else if (c == 'p' || c == 'P') {
			bubble_sort_by_pages(&head);
		}
		else if (c == 'c' || c == 'C') {
			bubble_sort_by_cost(&head);
		}
		else if (c == 'd' || c == 'D') {
			displayList(&head);
		}
		else if (c == 'f' || c == 'F') {
			find_book(&head);
		}
		else if (c == 'r' || c == 'R') {
			// edit_book()
		}
		else if (c == 'e' || c == 'E') {
			exit(0);
		}
		else {
			printf("something went wrong. try again.\n\n");
		}
	}

	return 0;
}
