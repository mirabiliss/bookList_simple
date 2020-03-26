#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "Node.h"

// initialises list with an element and makes head & tail point to it
void initList(Node** head, Node** tail, Book* _book) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (!newNode) {
		exit(1);
	}

	newNode->book = _book;
	newNode->prev = NULL;
	newNode->next = NULL;

	*head = newNode;
	*tail = newNode;
}

// adds new element at the end of the list
void push_back(Node** head, Node** tail, Book* _book) {
	if (*head == NULL && *tail == NULL) {
		initList(head, tail, _book);
		return;
	}

	Node* new_node = (Node*)malloc(sizeof(Node));
	if (!new_node) {
		exit(1);
		return;
	}
	new_node->book = _book;
	new_node->next = NULL;
	new_node->prev = *tail;

	(*tail)->next = new_node;
	*tail = new_node;
}

// pushes a new element to the list sorted by author's surname
void push_sorted_by_surname(Node** head, Node** tail, Book* _book) {
	if (*head == NULL && *tail == NULL) {
		initList(head, tail, _book);
		return;
	}

	Node* newNode = (Node*)malloc(sizeof(Node));
	if (!newNode) {
		exit(1);
	}
	newNode->book = _book;

	// finding after which element is new to be pushed
	Node* curr = *head;
	while (1) {
		if (curr) {
			if (strcmp(curr->book->author->surname, newNode->book->author->surname) > 0 || !curr->next) {
				break;
			}
		}
		if (curr)
			curr = curr->next;
	}

	newNode->next = curr->next;
	newNode->prev = curr;
	if (curr->next) {
		curr->next->prev = newNode;
	}
	else {
		*tail = newNode;
	}
	curr->next = newNode;
}

// reads and adds all books from source file to the list
void get_books(Node** head, Node** tail) {
	FILE* source;
	fopen_s(&source, "source.txt", "r");

	if (!source) {
		return;
	}
	while (!feof(source)) {
		Book* new_book = (Book*)malloc(sizeof(Book));
		if (new_book) {
			new_book->author = (Author*)malloc(sizeof(Author));
			new_book->author->name = (char*)malloc(35);
			new_book->author->surname = (char*)malloc(35);
			new_book->title = (char*)malloc(35);

			fscanf(source, "%s %s %s %d %d %d", new_book->author->name, \
				new_book->author->surname, new_book->title, &new_book->year, \
				&new_book->pages, &new_book->cost);
			push_back(head, tail, new_book);
		}
	}
	fclose(source);
}

// scans data about book from console and addes it at the end of the list
void get_book_from_console(Node** head, Node** tail) {
	Book* new_book = (Book*)malloc(sizeof(Book));
	if (new_book) {
		new_book->author = (Author*)malloc(sizeof(Author));
		new_book->author->name = (char*)malloc(35);
		new_book->author->surname = (char*)malloc(35);
		new_book->title = (char*)malloc(256);

		printf("- Enter author's name and surname, \
				\n- then title of the book, \
				\n- year of it's publishment, \
				\n- number of pages and price. In given order. \
				\nIf name, surname or title contain more than one word - \
enter them by separating with '_' or '-' if needed.\n");

		scanf("%s %s %s %d %d %d", new_book->author->name, \
			new_book->author->surname, new_book->title, &new_book->year, \
			& new_book->pages, &new_book->cost);

		//printf("enter author's name: ");
		//setName(new_book->author); 
		//printf("enter author's surname: ");
		//setSurname(new_book->author);
		//printf("enter book's title: ");
		//setTitle(new_book);
		//printf("enter book's year of publishment: ");
		//setYear(new_book);
		//printf("enter number of book's pages: ");
		//setPages(new_book);
		//printf("enter book's price: ");
		//setCost(new_book);

		push_back(head, tail, new_book);
	}
	else {
		printf("error allocating memory.\n");
	}
}

// displays the list to output file
void displayList(Node** head) {
	FILE* output;
	fopen_s(&output, "output.txt", "w");

	Node* it = *head;
	while (it) {
		fprintf(output, "%s %s: '%s' %dy. %dp. %d$\n", it->book->author->name, it->book->author->surname, \
			it->book->title, it->book->year, it->book->pages, it->book->cost);
		fprintf(output, "--------------------------------------------------------\n");
		it = it->next;
	}

	fclose(output);
}

void swap_nodes(Node** first, Node** second) {
	Node* tmp = *first;
	*first = *second;
	*second = tmp;
}

void swap_books(Book** first, Book** second) {
	Book* tmp = *first;
	*first = *second;
	*second = tmp;
}

// sorts list by authors' surnames in alphabet order 
void bubble_sort_by_surname(Node** head) {
	if (!(*head)) {
		exit(2);
	}

	for (Node* iptr = *head; iptr->next != NULL; iptr = iptr->next) {
		for (Node* jptr = iptr->next; jptr != NULL; jptr = jptr->next) {
			if (strcmp(iptr->book->author->surname, jptr->book->author->surname) > 0) {
				Book* tmp = iptr->book;
				iptr->book = jptr->book;
				jptr->book = tmp;
			}
		}
	}
}

// sorts list by authors' names in alphabet order 
void bubble_sort_by_name(Node** head) {
	if (!(*head)) {
		exit(2);
	}

	for (Node* iptr = *head; iptr->next != NULL; iptr = iptr->next) {
		for (Node* jptr = iptr->next; jptr != NULL; jptr = jptr->next) {
			if (strcmp(iptr->book->author->name, jptr->book->author->name) > 0) {
				Book* tmp = iptr->book;
				iptr->book = jptr->book;
				jptr->book = tmp;
			}
		}
	}
}

// sorts list by books' titles in alphabet order 
void bubble_sort_by_title(Node** head) {
	if (!(*head)) {
		exit(2);
	}

	for (Node* iptr = *head; iptr->next != NULL; iptr = iptr->next) {
		for (Node* jptr = iptr->next; jptr != NULL; jptr = jptr->next) {
			if (strcmp(iptr->book->title, jptr->book->title) > 0) {
				Book* tmp = iptr->book;
				iptr->book = jptr->book;
				jptr->book = tmp;
			}
		}
	}
}

// sorts list by books' year of publishment
void bubble_sort_by_year(Node** head) {
	if (!(*head)) {
		exit(2);
	}

	for (Node* iptr = *head; iptr->next != NULL; iptr = iptr->next) {
		for (Node* jptr = iptr->next; jptr != NULL; jptr = jptr->next) {
			if ((iptr->book->year) > (iptr->next->book->year)) {
				Book* tmp = iptr->book;
				iptr->book = jptr->book;
				jptr->book = tmp;
			}
		}
	}
}

// sorts list by number of books' pages
void bubble_sort_by_pages(Node** head) {
	if (!(*head)) {
		exit(2);
	}

	for (Node* iptr = *head; iptr->next != NULL; iptr = iptr->next) {
		for (Node* jptr = iptr->next; jptr != NULL; jptr = jptr->next) {
			if ((iptr->book->pages) > (iptr->next->book->pages)) {
				Book* tmp = iptr->book;
				iptr->book = jptr->book;
				jptr->book = tmp;
			}
		}
	}
}


// sorts list by increasing of books' cost
void bubble_sort_by_cost(Node** head) {
	if (!(*head)) {
		exit(2);
	}

	for (Node* iptr = *head; iptr->next != NULL; iptr = iptr->next) {
		for (Node* jptr = iptr->next; jptr != NULL; jptr = jptr->next) {
			if ((iptr->book->cost) > (iptr->next->book->cost)) {
				Book* tmp = iptr->book;
				iptr->book = jptr->book;
				jptr->book = tmp;
			}
		}
	}
}

void find_book(Node** head) {
	char* to_find = (char*)malloc(256);
	if (!to_find) {
		return;
	}

	printf("enter surname of the author, whose books you want to find: ");
	scanf("%s", to_find);
	int it = 0, bool = 0;
	while (to_find[it]) {
		to_find[it] = tolower(to_find[it]);
	}
	Node* curr = *head;
	printf("\n");

	while (curr != NULL) {
		if (strstr(curr->book->author->surname, to_find)) {
			bool = 1;
			displayBook(curr->book);
		}
		curr = curr->next;
	}
	if (!bool) {
		printf("no books of this author were found.\n");
	}
}

// choose what is to be done by clicking some characters
// change cost of books of nodes
// finish 'delete node'
