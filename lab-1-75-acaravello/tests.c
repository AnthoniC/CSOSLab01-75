//
//  tests.c
//  lab-1-75-acaravello
//
//  Created by Anthoni on 3/20/19.
//  Copyright © 2019 Anthoni. All rights reserved.
//

#include "tests.h"
#include <stdlib.h>
#include <assert.h>

void test_is_in_list_dll(void){
    printf("Starting test_is_in_list_dll\n");
    
    doubly_linked_list* list = (doubly_linked_list*)malloc(sizeof(doubly_linked_list));
    
    assert(is_in_list_dll(list, 10) == 0);
    doubly_linked_list_node* node = (doubly_linked_list_node*)malloc(sizeof(doubly_linked_list_node));
    node->data = 10;
    node->key = 10;
    node->next = 0;
    node->previous = 0;
    list->head = node;
    assert(is_in_list_dll(list, 10) == 1);
    doubly_linked_list_node* brode = (doubly_linked_list_node*)malloc(sizeof(doubly_linked_list_node));
    brode->data = 12;
    brode->key = 12;
    brode->next = 0;
    brode->previous = 0;
    list->head->next = brode;
    assert(is_in_list_dll(list, 10) == 1);
    assert(is_in_list_dll(list, 12) == 1);
    assert(is_in_list_dll(list, 15) == 0);
    
    printf("Completed test_is_in_list_dll\n");
    
}


void test_insert_dll(void){
    printf("Starting test_insert_dll\n");
    
    doubly_linked_list* list = (doubly_linked_list*)malloc(sizeof(doubly_linked_list));
    assert(insert_dll(list, 10, 10));
    assert(list->head->key == 10);
    
    assert(insert_dll(list, 10, 10) == 0);
    
    assert(insert_dll(list, 12, 12));
    assert(list->head->key == 10);
    assert(list->head->next->key == 12);
    
    assert(insert_dll(list, 9, 9));
    assert(list->head->key == 9);
    assert(list->head->next->key == 10);
    assert(list->head->next->next->key == 12);
    
    assert(insert_dll(list, 11, 11));
    assert(list->head->key == 9);
    assert(list->head->next->key == 10);
    assert(list->head->next->next->key == 11);
    assert(list->head->next->next->next->key == 12);
    
    assert(insert_dll(list, 9, 9) == 0);
    
    assert(insert_dll(list, 11, 11) == 0);
    
    assert(insert_dll(list, 15, 15));
    assert(list->head->key == 9);
    assert(list->head->next->key == 10);
    assert(list->head->next->next->key == 11);
    assert(list->head->next->next->next->key == 12);
    assert(list->head->next->next->next->next->key == 15);
    
    
    
    printf("Completed test_is_in_list_dll\n");
}


void test_find_element_dll(void){
    printf("Starting test_find_element_dll\n");
    
    doubly_linked_list* list = (doubly_linked_list*)malloc(sizeof(doubly_linked_list));
    assert(find_element_dll(list, 10) == 0);
    insert_dll(list, 10, 10);
    assert(find_element_dll(list, 10) == 10);
    insert_dll(list, 12, 12);
    insert_dll(list, 9, 9);
    insert_dll(list, 11, 11);
    assert(find_element_dll(list, 11) == 11);
    assert(find_element_dll(list, 12) == 12);
    assert(find_element_dll(list, 20) == 0);
    
    printf("Completed test_find_element_dll\n");
}


void test_remove_dll(void){
    printf("Starting test_remove_dll\n");
    
    doubly_linked_list* list = (doubly_linked_list*)malloc(sizeof(doubly_linked_list));
    insert_dll(list, 10, 10);
    insert_dll(list, 8, 8);
    insert_dll(list, 20, 20);
    insert_dll(list, 15, 15);
    insert_dll(list, 12, 12);
    assert(list->head->key == 8);
    assert(list->head->next->key == 10);
    assert(list->head->next->next->key == 12);
    assert(list->head->next->next->next->key == 15);
    assert(list->head->next->next->next->next->key == 20);
    
    assert(remove_dll(list, 10) == 10);
    assert(is_in_list_dll(list, 10) == 0);
    assert(list->head->key == 8);
    assert(list->head->next->key == 12);
    assert(list->head->next->next->key == 15);
    assert(list->head->next->next->next->key == 20);
    
    assert(remove_dll(list, 8) == 8);
    assert(is_in_list_dll(list, 8) == 0);
    assert(list->head->key == 12);
    assert(list->head->next->key == 15);
    assert(list->head->next->next->key == 20);
    
    assert(remove_dll(list, 20) == 20);
    assert(is_in_list_dll(list, 20) == 0);
    assert(list->head->key == 12);
    assert(list->head->next->key == 15);
    
    assert(remove_dll(list, 200) == 0);
    
    assert(remove_dll(list, 15) == 15);
    assert(is_in_list_dll(list, 15) == 0);
    assert(list->head->key == 12);
    
    assert(remove_dll(list, 12) == 12);
    assert(is_in_list_dll(list, 12) == 0);
    
    assert(remove_dll(list, 205) == 0);
    
    printf("Completed test_remove_dll\n");
}


void test_print_dll(void){
    printf("Starting test_print_dll\n");
    
    doubly_linked_list* list = (doubly_linked_list*)malloc(sizeof(doubly_linked_list));
    
    insert_dll(list, 10, 10);
    insert_dll(list, 8, 8);
    insert_dll(list, 20, 20);
    insert_dll(list, 15, 15);
    insert_dll(list, 12, 12);
    
    print_dll(list);
    
    printf("Completed test_print_dll\n");
}


void test_create_array_dll(void){
    printf("Starting test_create_array_dll\n");
    
    doubly_linked_list* list = (doubly_linked_list*)malloc(sizeof(doubly_linked_list));
    
    insert_dll(list, 10, 10);
    insert_dll(list, 8, 8);
    insert_dll(list, 20, 20);
    insert_dll(list, 15, 15);
    insert_dll(list, 12, 12);
    
    int* array = create_array_dll(list);
    
    assert(array[0] == 8);
    assert(array[1] == 10);
    assert(array[2] == 12);
    assert(array[3] == 15);
    assert(array[4] == 20);
    
    printf("Completed test_create_array_dll\n");
}


void test_create_cl(void){
    printf("Starting test_create_cl\n");
    circular_buffer* cb = create_cl(5);
    assert(cb);
    assert(cb->size == 5);
    assert(cb->occupied == 0);
    
    assert(create_cl(0) == 0);
    assert(create_cl(-1) == 0);
    
    printf("Completed test_create_cl\n");
}

void test_push_cl(void){
    printf("Starting test_push_cl\n");
    circular_buffer* cb = create_cl(5);
    assert(push_cl(cb, 1) == 0);
    assert(cb->head->previous->value == 1);
    assert(cb->tail->value = 1);
    assert(push_cl(cb, 2) == 0);
    assert(cb->head->previous->value == 2);
    assert(push_cl(cb, 3) == 0);
    assert(cb->head->previous->value == 3);
    assert(push_cl(cb, 4) == 0);
    assert(cb->head->previous->value == 4);
    assert(push_cl(cb, 5) == 0);
    assert(cb->head->previous->value == 5);
    assert(cb->tail->value = 1);
    assert(push_cl(cb, 6) == -1);
    assert(cb->head->previous->value == 5);
    printf("Completed test_create_cl\n");
}

void test_pop_cl(void){
    printf("Starting test_pop_cl\n");
    circular_buffer* cb = create_cl(5);
    push_cl(cb, 1);
    push_cl(cb, 2);
    push_cl(cb, 3);
    push_cl(cb, 4);
    push_cl(cb, 5);
    assert(pop_cl(cb) == 1);
    assert(pop_cl(cb) == 2);
    assert(pop_cl(cb) == 3);
    assert(pop_cl(cb) == 4);
    assert(pop_cl(cb) == 5);
    assert(pop_cl(cb) == -1);
    
 
    printf("Completed test_pop_cl\n");
}

void test_head_cl(void){
    printf("Starting test_head_cl\n");
    circular_buffer* cb = create_cl(5);
    push_cl(cb, 1);
    assert(head_cl(cb) == 1);
    push_cl(cb, 2);
    push_cl(cb, 3);
    push_cl(cb, 4);
    push_cl(cb, 5);
    pop_cl(cb);
    assert(head_cl(cb) == 2);
    pop_cl(cb);
    assert(head_cl(cb) == 3);
    pop_cl(cb);
    assert(head_cl(cb) == 4);
    pop_cl(cb);
    assert(head_cl(cb) == 5);
    pop_cl(cb);
    assert(head_cl(cb) == -1);
    
    printf("Completed test_head_cl\n");
}

