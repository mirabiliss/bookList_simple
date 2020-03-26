#include "Node.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void setName(Author* a) {
	char* _name = "";
	scanf_s("%s", _name, 256);
	a->name = _name;
}

void setSurname(Author* a) {
	char* _surname = "";
	scanf_s("%s", _surname, 256);
	a->surname = _surname;
}



void setAuthor(Book* book) {
	setName(book->author);

	// check if valid
	if (book->author->name == "" || !(is_valid_string(book->author->name))) {
		printf("Invalid value assigned to 'name'. You may rewrite it (press 'r') or exit and delete this book: ");
		char c = getchar();
		if (c == 'r' || c =='R') {
			setName(book->author);
		}
		else {
			deleteBook(book);
		}
	}

	setSurname(book->author);
	// check if valid
	if (book->author->surname == "" || !(is_valid_string(book->author->surname))) {
		printf("Invalid value assigned to 'surname'. You may rewrite it (press 'r') or exit and delete this book: ");
		char c = getchar();
		if (c == 'r' || c == 'R') {
			setSurname(book->author);
		}
		else {
			deleteBook(book);
		}
	}
}

void setTitle(Book* book) {
	char* _title = (char*)malloc(256);
	scanf_s("%s", _title, 256);
	book->title = _title;

	// check if valid
	if (book->title == ""  || !(is_valid_string(book->title))) {
		printf("Invalid value assigned to 'title'. You may rewrite it (press 'r') or exit and delete this book: ");
		char c = getchar();
		if (c == 'r' || c == 'R') {
			setTitle(book);
		}
		else {
			deleteBook(book);
		}
	}
}

// sets year of publishment of the book
void setYear(Book* book) {
	int _year = 9999;
	scanf_s("%d", &_year);
	book->year = _year;

	// check if valid
	if (book->year > 2020 || !(isdigit(book->year))) {
		printf("Invalid value assigned to 'year'. You may rewrite it (press 'r') or exit and delete this book: ");
		char c = getchar();
		if (c == 'r' || c == 'R') {
			setYear(book);
		}
		else {
			deleteBook(book);
		}
	}
}

// sets number of pages of the book
void setPages(Book* book) {
	int _pages = -1234;
	scanf_s("%d", &_pages);
	book->pages = _pages;

	// check if valid
	if (book->pages <= 0 || !(isdigit(book->pages))) {
		printf("Invalid value assigned to 'pages'. You may rewrite it (press 'r') or exit and delete this book: ");
		char c = getchar();
		if (c == 'r' || c == 'R') {
			setPages(book);
		}
		else {
			deleteBook(book);
		}
	}
}

void setCost(Book* book) {
	int _cost = -9876;
	scanf_s("%d", &_cost);
	book->cost = _cost;

	// check if valid
	if (book->cost < 0 || !(isdigit(book->cost))) {
		printf("Invalid value assigned to 'cost'. You may rewrite it (press 'r') or exit and delete this book: ");
		char c = getchar();
		if (c == 'r' || c == 'R') {
			setCost(book);
		}
		else {
			deleteBook(book);
		}
	}
}


void deleteBook(Book* book) {
	if (book->title) {
		free(book->title);
	}
	if (book->author) {
		free(book->author->name);
		free(book->author->surname);
		free(book->author);
	}
	if (book) {
		free(book);
	}
}

// displays all book's information to the console
void displayBook(Book* book) {
	if (book) {
		printf("%s %s: '%s' %dy. %dp. %d$\n", book->author->name, book->author->surname, \
			book->title, book->year, book->pages, book->cost);
		printf("--------------------------------------------------------\n");
	}
}



// deletes node from the list
void deleteNode(Node** head, Node** tail, Node* toDelete) {
	// if a node to delete is the first element of the list
	if (toDelete == *head) {
		deleteBook((*head)->book);
		*head = (*head)->next;
		free((*head)->prev);
		(*head)->prev = NULL;
	}
	// if a node to delete is the last element of the list
	else if (toDelete == *tail) {
		deleteBook((*tail)->book);
		*tail = (*tail)->prev;
		free((*tail)->next);
		(*tail)->next = NULL;
	}

	// else if in the middle

}

int is_valid_string(char* check) {
	int i = 0, res = 0;
	if (!check[i]) {
		return 0;
	}
	while (check[i]) {
		if ((isalpha(check[i])) || ((check[i] == '-') || (check[i] == '_'))) {
			res = 1;
		}
		else {
			return 0;
		}
		i++;
	}
	return res;
}
