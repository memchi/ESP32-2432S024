/* -----------------------------------------------------------------------------
  Copyright (c) Martin Emch, CH - 6010 Kriens
  ------------------------------------------------------------------------------
  --------------------------------------------------------------------------- */
#pragma once
// -----------------------------------------------------------------------------
#include <stddef.h>
#include "Tracing.h"
// -----------------------------------------------------------------------------
template<class T>
struct ListNode {
  T data;
  ListNode<T> * next;
};
// -----------------------------------------------------------------------------
template <typename T>
class LinkedList {

protected:
  int _size;
  ListNode<T> * root;
  ListNode<T>	* last;

  // Helps "get" method, by saving last position
  ListNode<T> * lastNodeGot;
  int lastIndexGot;
  // isCached should be set to FALSE
  // everytime the list suffer changes
  bool isCached;

  ListNode<T> * getNode(int index);

  ListNode<T> * findEndOfSortedString(ListNode<T> * p, int (*cmp)(T &, T &));

public:
  LinkedList();
  LinkedList(int sizeIndex, T _t); //initiate list size and default value
  virtual ~LinkedList();

  /*
  	Returns current size of LinkedList
  */
  virtual int size();
  /*
  	Adds a T object in the specified index;
  	Unlink and link the LinkedList correcly;
  	Increment _size
  */
  virtual bool add(int index, T);
  /*
  	Adds a T object in the end of the LinkedList;
  	Increment _size;
  */
  virtual bool add(T);
  /*
  	Adds a T object in the start of the LinkedList;
  	Increment _size;
  */
  virtual bool unshift(T);
  /*
  	Set the object at index, with T;
  */
  virtual bool set(int index, T);
  /*
  	Remove object at index;
  	If index is not reachable, returns false;
  	else, decrement _size
  */
  virtual T remove(int index);
  /*
  	Remove last object;
  */
  virtual T pop();
  /*
  	Remove first object;
  */
  virtual T shift();
  /*
  	Get the index'th element on the list;
  	Return Element if accessible,
  	else, return false;
  */
  virtual T get(int index);

  /*
  	Clear the entire array
  */
  virtual void clear();

  /*
  	Sort the list, given a comparison function
  */
  virtual void sort(int (*cmp)(T &, T &));

  // add support to array brakets [] operator
  inline T & operator[](int index);
  inline T & operator[](size_t & i) {
    return this->get(i);
  }
  inline const T & operator[](const size_t & i) const {
    return this->get(i);
  }

};
// -----------------------------------------------------------------------------
