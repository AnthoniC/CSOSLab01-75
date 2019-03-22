//
//  CircularBuffer.c
//  lab-1-75-acaravello
//
//  Created by Anthoni on 3/20/19.
//  Copyright © 2019 Anthoni. All rights reserved.
//

#include "CircularBuffer.h"
#include <stdlib.h>


//typedef struct circular_buffer_node{
//    int value;
//    struct circular_buffer_node* next;
//    struct circular_buffer_node* previous;
//} circular_buffer_node;
//
//typedef struct circular_buffer{
//    int size;
//    int occupied;
//    circular_buffer_node* head;
//    circular_buffer_node* tail;
//} circular_buffer;

circular_buffer* create_cl(int size){
    if(size < 1){
        return 0;
    }
    circular_buffer* new_cb = (circular_buffer*)malloc(sizeof(circular_buffer));
    new_cb->size = size;
    new_cb->occupied = 0;
    circular_buffer_node* head = (circular_buffer_node*)malloc(sizeof(circular_buffer_node));
    new_cb->head = head;
    new_cb->tail = head;
    circular_buffer_node* temp = head;
    temp->value = 0;
    
    for (int i=1; i<size; i++) {
        circular_buffer_node* next = (circular_buffer_node*)malloc(sizeof(circular_buffer_node));
        temp->value = 0;
        temp->next = next;
        next->previous = temp;
        temp = next;
    }
    temp->next = head;
    head->previous = temp;
    
    return new_cb;
}


int push_cl(circular_buffer* cb, int value){
    if(cb->occupied == cb->size){
        return -1;
    }
    cb->head->value = value;
    cb->head = cb->head->next;
    cb->occupied++;
    return 0;
}


int pop_cl(circular_buffer* cb){
    if(cb->occupied == 0){
        return -1;
    }
    int temp = cb->tail->value;
    cb->tail = cb->tail->next;
    cb->occupied--;
    return temp;
}


int head_cl(circular_buffer* cb){
    if(cb->occupied == 0){
        return -1;
    } else{
        return cb->tail->value;
    }
    
}

