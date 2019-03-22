//
//  main.c
//  lab-1-75-acaravello
//
//  Created by Anthoni on 3/17/19.
//  Copyright © 2019 Anthoni. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "DoublyLinkedList.h"
#include "CircularBuffer.h"
#include "tests.h"




int main(int argc, const char * argv[]) {
    printf("Starting Tests for Doubly Linked List\n\n");
    test_is_in_list_dll();
    test_insert_dll();
    test_find_element_dll();
    test_remove_dll();
    test_print_dll();
    test_create_array_dll();
    printf("\nCompleted All Tests for Doubly Linked List\n");
    
    printf("Starting Tests for Circular Buffer\n\n");
    test_create_cl();
    test_push_cl();
    test_pop_cl();
    test_head_cl();
    
    printf("\nCompleted All Tests for Circular Buffer\n");
    
    
    
    
    printf("\nCompleted All Tests\n");
    
    return 0;
}




