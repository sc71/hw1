#ifndef SPLIT_H
#define SPLIT_H
#include <cstdlib>
#include <iostream>

struct Node 
{
  int value;
  Node* next;

  /**
   * Initializing constructor
   */
  Node(int v, Node* n)
  {
    value = v;
    next = n;
  }
};

void split(Node*& in, Node*& odds, Node*& evens);
Node* getTail(Node* n);
#endif
