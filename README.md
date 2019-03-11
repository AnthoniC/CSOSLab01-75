# Lab 1.75 Setup
## Objective ##
The objective of this lab is to create three more types of data structures `doubly_linked_list`, a `circular_buffer`, and a `binary_tree`. 


## Doubly Linked List 
A `doubly_linked_list` is simliar to a `linked_list` from the last lab except that each node contains a pointer to its predecessor in addition to its sucessor. Towards this end here is what you must complete in this section.
+ Create a `struct` for a *doubly linked list node* that contains two entries `data` and `next`. 
	- `data` is an integer. This represents the value we are actually storing. (Note: "doubly" here refers to forwards and backwards, not the contents of what is being stored.)
	- `key` is an integer. This is used for sorting. 
	- `next` is a pointer the next element in the list. This is zero if its the last element in the list.
	- `last` is a pointer the last element in the list. This is zero if its the first element in the list.
+ Create a `struct` for a *doubly linked list* that contains one entry `head` that points to the first element of the doubly linked list. 
+ Create a method `insert` that takes three parameters, a doubly linked list struct, a data integer, and a key integer. This will insert the data integer as a liked list node struct, *sorted* by the key value. If there is already an element with the associated key in the list then the value will *not* be inserted. If the value fails to be inserted for any reason, it will return a 0. If successful, this will return 1.
+ Create a method `is_in_list_dll` that takes two parameters, a doubly linked list struct and an key integer. This will return 1 if there is an element in the doubly linked list that has the associated key integer, it returns a 0 if there isn't. -1 if there is an error. (May not need to return -1 depending on how you implement it.)
+ Create a method `find_element_dll` that takes two parameters, a doubly linked list struct and an key integer. This will return the value for the associated key from the list. If the node isn't present or something goes wrong it will return a 0.
+ Create a method `remove_dll` that takes two parameters, a doubly linked list struct and an key integer. This will remove the node with the associated key from the list. If the node is removed it will return a 1. If the node isn't present or something goes wrong it will return a 0.
+ Create a method `print_dll` that takes one parameter a doubly linked list struct. This prints out a list of all of the *integer values* of the elements in the doubly linked list.  
+ Crate a method `create_array_dll` that takes one parameter a doubly linked list struct. This returns an array of all of the *integer values* of the elements in the doubly linked list. 
