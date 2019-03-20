//
//  DoublyLinkedList.h
//  lab-1-75-acaravello
//
//  Created by Anthoni on 3/20/19.
//  Copyright © 2019 Anthoni. All rights reserved.
//

#ifndef DoublyLinkedList_h
#define DoublyLinkedList_h

#include <stdio.h>

typedef struct doubly_linked_list_node {
    struct doubly_linked_list_node* previous;
    struct doubly_linked_list_node* next;
    int key;
    int data;
} doubly_linked_list_node;

typedef struct doubly_linked_list {
    doubly_linked_list_node* head;
} doubly_linked_list;

int insert_dll(doubly_linked_list* list, int data, int key);
int is_in_list_dll(doubly_linked_list* list, int key);
int find_element_dll(doubly_linked_list* list, int key);
int remove_dll(doubly_linked_list* list, int key);
void print_dll(doubly_linked_list* list);
int* create_array_dll(doubly_linked_list* list);

#endif /* DoublyLinkedList_h */
