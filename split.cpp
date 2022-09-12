/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"

/* Add a prototype for a helper function here if you need */

Node* getTail(Node* n);
//void printList(Node* n);
void split(Node*& in, Node*& odds, Node*& evens)
{
    if(in = NULL){
        return;
    }
    else{
        //see if node value is odd or even and place it accordingly
        int val = in->value;
        Node* node = &*in;
        node->next = NULL;
        in = in->next;
        if(val % 2 == 0){
            getTail(evens)->next = node;
        }
        else{
            getTail(odds)->next = node;
        }
        //remove sorted node from in
        split(in, odds, evens);
    }
}

Node* getTail(Node* n){
    if(n = NULL){
        return n;
    }
    else{
        return getTail(n->next);
    }
}
