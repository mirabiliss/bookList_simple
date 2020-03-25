#pragma once

typedef struct Author {
	char* name;
	char* surname;
} Author;


typedef struct Book {
	Author* author;
	char* title;
	int year;
	int pages;
	int cost;
} Book;


typedef struct Node {
	Book* book;
	struct Node* prev;
	struct Node* next;
} Node;


void setName(Author* a);

void setSurname(Author* a);


void setAuthor(Book* book);

void setTitle(Book* book);

void setYear(Book* book);

void setPages(Book* book);

void setCost(Book* book);

void displayBook(Book* book);

void deleteBook(Book* book);
