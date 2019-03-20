//
//  tests.c
//  lab-1-75-acaravello
//
//  Created by Anthoni on 3/20/19.
//  Copyright © 2019 Anthoni. All rights reserved.
//

#include "tests.h"
#include <stdlib.h>

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
    printf("Is in list: %d\n", is_in_list_dll(list, 20));
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


void test_is_in_list_cl(void){
    
}

void test_insert_cl(void){
    
}

void test_find_element_cl(void){
    
}

void test_remove_cl(void){
    
}

void test_print_cl(void){
    
}

void test_create_array_cl(void){
    
}

