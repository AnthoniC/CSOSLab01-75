//
//  DoublyLinkedList.c
//  lab-1-75-acaravello
//
//  Created by Anthoni on 3/20/19.
//  Copyright © 2019 Anthoni. All rights reserved.
//

#include <stdlib.h>
#include "DoublyLinkedList.h"


int insert_dll(doubly_linked_list* list, int data, int key){
    
    doubly_linked_list_node* node_to_insert = (doubly_linked_list_node*)malloc(sizeof(doubly_linked_list_node));
    node_to_insert->key = key;
    node_to_insert->data = data;
    node_to_insert->next = 0;
    node_to_insert->previous = 0;
    
    if(!list->head){
        list->head = node_to_insert;
        return 1;
    }
    
    if(is_in_list_dll(list, key) == 1){
        return 0;
    }

    doubly_linked_list_node* temp = list->head;
    
    while(temp->key < key && temp->next != 0){
        temp = temp->next;
    }
    if(temp->key < key){
        temp->next = node_to_insert;
        node_to_insert->previous = temp;
    } else{
        if(temp == list->head){
            list->head = node_to_insert;
        } else{
            node_to_insert->previous = temp->previous;
            node_to_insert->previous->next = node_to_insert;
        }
        node_to_insert->next = temp;
        temp->previous = node_to_insert;
    }
    
    
    
    return 1;
}


int is_in_list_dll(doubly_linked_list* list, int key){
    
    if(!list->head){
        return 0;
    }
    
    
    doubly_linked_list_node* temp = list->head;
    
    
    while(temp->next){
        if(temp->key == key){
            return 1;
        }
        temp = temp->next;
    }
    
    if(temp->key == key){
        return 1;
    }
    
    
    return 0;
}


int find_element_dll(doubly_linked_list* list, int key){
    
    if(!list->head){
        return 0;
    }
    
    doubly_linked_list_node* temp = list->head;
    
    while(temp){
        if(temp->key == key){
            return temp->data;
        }
        temp = temp->next;
    }
    
    return 0;
}


int remove_dll(doubly_linked_list* list, int key){
    
    if(!list->head){
        return 0;
    }
    
    if(is_in_list_dll(list, key) == 0){
        return 0;
    }
    
    if(list->head->key == key){
        int value = list->head->data;
        if(list->head->next){
            list->head->next->previous = 0;
            list->head = list->head->next;
        } else{
            list->head = 0;
        }
        return value;
    }
    
    doubly_linked_list_node* temp = list->head;
    
    
    while(temp){
        if(temp->key == key){
            int value = temp->data;
            if(temp->next){
                temp->next->previous = temp->previous;
                temp->previous->next = temp->next;
            } else{
                temp->previous->next = 0;
            }
            return value;
        } else{
            temp = temp->next;
        }
    }
    
    
    return 0;
}


void print_dll(doubly_linked_list* list){
    doubly_linked_list_node* temp = list->head;
    while(temp){
        printf("%d, ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


int* create_array_dll(doubly_linked_list* list){
    doubly_linked_list_node* temp = list->head;
    int count = 0;
    while(temp){
        count++;
        temp = temp->next;
    }
    
    int* array = (int*)malloc(sizeof(int)*count);
    temp = list->head;
    for (int i=0; i<count; i++) {
        array[i] = temp->data;
        temp = temp->next;
    }
    
    return array;
}

