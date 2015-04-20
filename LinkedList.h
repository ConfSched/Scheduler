#ifndef INCLUDED_LinkedList
#define INCLUDED_LinkedList

class LinkedList
{
private:
  /* pointer of head node */
  Node *_pHead;
  /* pointer of tail node */
  Node *_pTail;
    
public:
  /* Constructors with No Arguments */
  LinkedList(void);
  /* Constructors with a given value of a list node */
  LinkedList(int val);
  /* Destructor */
  ~LinkedList(void);
    
  /* Traversing the list and printing the value of each node */
  void traverse_and_print();
}; 
#endif
