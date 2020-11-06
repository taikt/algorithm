/** Stack Example: Node helper template class for the Linked List Stack
    Julie A. Adams
**/

#ifndef NODE_H
#define NODE_H

template <typename T> 
class Node{	
 public:
  Node (T i, Node<T> *n = 0): item_(i), next_(n) {}
  
  T getItem() const {return item_;}
  Node<T>* getNext() const { return next_; }
    
 private:
  T item_;
  Node<T> *next_;
};

#endif

