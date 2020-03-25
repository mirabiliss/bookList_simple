#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Node.h"
#include "List.h"

int main(void) {
	Node* head = NULL, * tail = NULL;

	get_books(&head, &tail);
	displayList(&head);

<<<<<<< HEAD
	//displayBook(book);
	//deleteBook(book);
=======
	//Book* book = (Book*)malloc(sizeof(Book));
	//book->author = (Author*)malloc(sizeof(Author));
	//book->title = (char*)malloc(50);

	//book->author->name = "name";
	//book->author->surname = "surname";
	//book->title = "title";
	//book->year = 2000;
	//book->pages = 456;
	//book->cost = 85;

	//Book* second = (Book*)malloc(sizeof(Book));
	//second->author = (Author*)malloc(sizeof(Author));
	//second->title = (char*)malloc(50);

	//second->author->name = "Austin";
	//second->author->surname = "Hdfhsame";
	//second->title = "HisOwnBook";
	//second->year = 2540;
	//second->pages = 126;
	//second->cost = 11;

	//push_back(&head, &tail, book);
	//push_back(&head, &tail, second);
	//push_back(&head, &tail, book);
	//push_back(&head, &tail, second);

	//bubble_sort_by_cost(&head);
	////bubble_sort_by_surname(&head);
>>>>>>> update

	return 0;
}