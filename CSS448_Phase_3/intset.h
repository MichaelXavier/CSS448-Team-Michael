//------------------------------------------------------------------------------
// CSS342 Lab 2
// Michael Xavier
// UW NETID: coiffio
// Part 1, IntSet header file intset.h
// Assumptions: See file intset.cpp
//------------------------------------------------------------------------------

#ifndef INTSET_H
#define INTSET_H
#include <iostream>

using namespace std;

class IntSet {
public:
  IntSet(int = -1, int = -1, int = -1, int = -1, int = -1);//defaults invalid
  IntSet(int, int);
  ~IntSet(void);
  IntSet(const IntSet&);
  IntSet operator+(const IntSet&)const;
  IntSet operator*(const IntSet&)const;
  IntSet operator-(const IntSet&)const;
  IntSet operator=(const IntSet&);
  IntSet operator+=(const IntSet&);
  IntSet operator*=(const IntSet&);
  IntSet operator-=(const IntSet&);
  bool operator==(const IntSet&)const;
  bool operator!=(const IntSet&)const;
  bool isEmpty(void)const;
  bool isInSet(const int)const;
  bool insert(const int);
  bool remove(const int);
  friend ostream& operator<<(ostream&, const IntSet&);
  friend istream& operator>>(istream&, IntSet&);
private:
  unsigned int findLargest(unsigned int[], unsigned int);
  unsigned int largest;//largest number in set
  bool* set_members;//internal array representing the set, of size largest + 1
};
#endif
