#pragma once
#include "Node.h"

void initList(Node** head, Node** tail, Book* _book);

void push_back(Node** head, Node** tail, Book* _book);

void push_sorted_by_surname(Node** head, Node** tail, Book* _book);

void get_books(Node** head, Node** tail);

void displayList(Node** head);

void swap_nodes(Node** first, Node** second);

void swap_books(Book** first, Book** second);

void bubble_sort_by_surname(Node** head);

void bubble_sort_by_cost(Node** head);
