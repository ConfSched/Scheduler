#ifndef INCLUDED_Node
#define INCLUDED_Node
#include <iostream>

class Node
{
  friend class LinkedList;
private:
  int _value; /* data, can be any data type, but use integer for easiness */
  Node *_pNext; /* pointer to the next node */
    
public:
  /* Constructors with No Arguments */
  Node(void)
    : _pNext(NULL)
  { }
    
  /* Constructors with a given value */
  Node(int val)
    : _value(val), _pNext(NULL)
  { }
    
  /* Constructors with a given value and a link of the next node */
  Node(int val, Node* next)
    : _value(val), _pNext(next)
  {}
    
  /* Getters */
  int getValue(void)
  { return _value; }
    
  Node* getNext(void)
  { return _pNext; }
};
#endif
