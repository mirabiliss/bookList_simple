#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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
<<<<<<< HEAD
	while (1) {
=======
	if (strcmp(curr->book->author->surname, newNode->book->author->surname) > 0) {
		newNode->next = curr;
		newNode->prev = NULL;
		curr->prev = newNode;
		*head = newNode;
		return;
	}
	while (1){
>>>>>>> update
		if (curr) {
			if (strcmp(curr->book->author->surname, newNode->book->author->surname) > 0 || !curr->next) {
				break;
			}
		}
		curr = curr->next;
	}

	newNode->next = curr->next;
	newNode->prev = curr;
	if (curr->next) {
		curr->next->prev = newNode;
	}
<<<<<<< HEAD
=======
	else {
		*tail = newNode;
	}
>>>>>>> update
	curr->next = newNode;
}

void get_books(Node** head, Node** tail) {
	FILE* source;
	fopen_s(&source, "source.txt", "r");

	while (!feof(source)) {
		Book* new_book = (Book*)malloc(sizeof(Book));
		new_book->author = (Author*)malloc(sizeof(Author));
		new_book->author->name = (char*)malloc(35);
		new_book->author->surname = (char*)malloc(35);

		fscanf_s(source, "%s %s %s %d %d %d", new_book->author->name, \
			new_book->author->surname, new_book->title, &new_book->year, \
			&new_book->pages, &new_book->cost);
		push_back(&head, &tail, new_book);
	}
	fclose(source);
}

// displays the list to output file
void displayList(Node** head) {
	FILE* output;
	fopen_s(&output, "output.txt", "w");

	Node* it = *head;
	while (it) {
		fprintf(output, "%s %s: '%s' %dy. %dp. %d$\n", it->book->author->name, it->book->author->surname, \
				it->book->title, it->book->year, it->book->pages, it->book->cost);
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

// sorts list by authors' surnames in alphabet order (has to)
// same *head problem 
void bubble_sort_by_surname(Node** head) {
	if (!(*head)) {
		exit(2);
	}

	for (Node* iptr = *head; iptr->next != NULL; iptr = iptr->next) {
		for (Node* jptr = iptr->next; jptr != NULL; jptr = jptr->next) {
			if (strcmp(iptr->book->author->surname, jptr->book->author->surname) > 0) {
				//swap_books(&iptr->book, &iptr->next->book);
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

// sort by surname, year, pages, title
// choose what is to be done by clicking some characters
// reading from a file
// change cost of books of nodes
// finish 'delete node'