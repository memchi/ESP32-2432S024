/* -----------------------------------------------------------------------------
  Copyright (c) Martin Emch, CH - 6010 Kriens
  ------------------------------------------------------------------------------
  https://de.wikipedia.org/wiki/C%2B%2B-Standardbibliothek#Container
  http://playground.arduino.cc/Code/QueueList
  https://en.wikipedia.org/wiki/Doubly_linked_list
  http://stackoverflow.com/questions/13906980/calling-an-overridden-function-from-a-list-of-its-base-class
  --------------------------------------------------------------------------- */
#pragma once
// -----------------------------------------------------------------------------
#include "LinkedList2.h" // TODO: replace by CoThreadList
//#include "CoThreadList.h"
#include "CoThreadBase.h"
// -----------------------------------------------------------------------------
using namespace std;
// -----------------------------------------------------------------------------
#define MAXLOOPTIME 1000
enum TThreadPriority {tpLowest, tpBelowNormal, tpNormal, tpAboveNormal, tpHighest};
// -----------------------------------------------------------------------------
// Class which hold all the components derived from TCoThreadBase
class TCoThreadSchedule {
public:
  // Default constructor
  TCoThreadSchedule();
  // Default destructor
  ~TCoThreadSchedule();
  // add an item to the queue.
  TCoThreadBase * Add(TCoThreadBase * CoThreadBase);
  // add an item to the queue.
  TCoThreadBase * Add(TCoThreadBase * CoThreadBase, const TThreadPriority ThreadPriority);
  bool Execute(uint32_t MaxMicros);
private:
  // TODO: this should replaced by an own implementation
  LinkedList<TCoThreadBase *> CoThreads; // http://stackoverflow.com/questions/9241680/list-of-polymorphic-objects
};
// -----------------------------------------------------------------------------