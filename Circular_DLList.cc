/**
 * @file Circular_DLList.cc
 * @author Krisna Gusti (k_gusti@hotmail.com)
 * @brief 
 */

#include <iostream>
#include "Circular_DLList.h"

// Destructor
Circular_DLList::~Circular_DLList()
{
    // delete each DLLNode from tail until empty
    while(!is_empty()) {
        delete_from_tail();
    }
}

// Add a new DLLNode to tail of list
void Circular_DLList::add_to_tail(int data)
{
    // if list is empty
    if (is_empty()) {
        tail = new DLLNode(data);
        tail->next = tail;
        tail->prev = tail;
    // one or more elements
    } else { 
        tail = new DLLNode(data, tail->prev, tail);
        tail->next->prev = tail;
        tail->prev->next = tail;
    }
}

// Delete DLLNode at tail and return its data
int Circular_DLList::delete_from_tail()
{
    int data = 0;

    // delete only if list is not empty
    if (!is_empty()) {
        data = tail->info;
        DLLNode* temp = tail;

        // only one element in list
        if (tail->next == tail) {
            tail = 0;
        // reassign pointers
        } else {
            tail = tail->next;
            temp->prev->next = tail;
            tail->prev = temp->prev;
        }
        // delete DLLNode
        delete temp;
    }

    return data;
}

// Finds if an element is in list
bool Circular_DLList::is_in_list(int data)
{
    bool found = false;

    // if list is not empty
    if (!is_empty()) { 
        DLLNode* pointer = tail;

        // traverse list
        do {
            // break if element is found
            if (pointer->info == data) {
                found = true;
                break;
            }
            pointer = pointer->next;
        } while(pointer != tail);
    }

    return found;
}

// Print out list if not empty
void Circular_DLList::print_list()
{
    if (!is_empty()) {
        DLLNode* pointer = tail;
        // print first DLLNode element then traverse list
        do {
            std::cout << pointer->info << " ";
            pointer = pointer->next;
        } while (pointer != tail);
        std::cout << std::endl;
    }
}

// Tail next node data
int Circular_DLList::return_head()
{
	DLLNode* head = tail->next;
	return head->info;
}

// Tail previous node data
int Circular_DLList::return_one_before_tail()
{
	DLLNode* one_before_tail = tail->prev;
	return one_before_tail->info;
}