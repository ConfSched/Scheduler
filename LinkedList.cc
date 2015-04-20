#include "Node.h"
#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList()
{
  /* Initialize the head and tail node */
  _pHead = _pTail = NULL;
}

LinkedList::LinkedList(int val)
{
  /* Create a new node, acting as both the head and tail node */
  _pHead = new Node(val);
  _pTail = _pHead;
}

LinkedList::~LinkedList()
{
  /*
   * Leave it empty temporarily.
   * It will be described in detail in the example "How to delete a linkedlist".
   */
}

//void LinkedList::addToFront(LinkedList List,int val) {

void LinkedList::traverse_and_print()
{
  Node *p = _pHead;
    
  /* The list is empty? */
  if (_pHead == NULL) {
    cout << "The list is empty" << endl;
    return;
  }
    
  cout << "LinkedList: ";
  /* A basic way of traversing a linked list */
  while (p != NULL) { /* while there are some more nodes left */
    /* output the value */
    cout << p->_value;
    /* The pointer moves along to the next one */
    p = p->_pNext;
  }
  cout << endl;
}
