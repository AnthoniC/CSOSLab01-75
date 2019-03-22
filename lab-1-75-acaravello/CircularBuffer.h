//
//  CircularBuffer.h
//  lab-1-75-acaravello
//
//  Created by Anthoni on 3/20/19.
//  Copyright © 2019 Anthoni. All rights reserved.
//

#ifndef CircularBuffer_h
#define CircularBuffer_h

#include <stdio.h>

typedef struct circular_buffer_node{
    int value;
    struct circular_buffer_node* next;
    struct circular_buffer_node* previous;
} circular_buffer_node;

typedef struct circular_buffer{
    int size;
    int occupied;
    circular_buffer_node* head;
    circular_buffer_node* tail;
} circular_buffer;

circular_buffer* create_cl(int size);
int push_cl(circular_buffer* cb, int value);
int pop_cl(circular_buffer* cb);
int head_cl(circular_buffer* cb);

#endif /* CircularBuffer_h */
