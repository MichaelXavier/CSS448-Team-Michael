//------------------------------------------------------------------------------
// CSS342 Lab 2
// Michael Xavier
// UW NETID: coiffio
// Part 1, IntSet implementation file intset.cpp
// IntSet - A mathematical set data type. Contains 0 or more positive unique
//   integer values from an external perspective and offers methods to add,
//   remove, print elements as well as comparing two different IntSets
// Assumptions:  
//    -- The initializers for IntSet do not exceed the maximum size of an int
//       on the system.
//    -- The largest element in the union may not exceed the maximum size of an
//       unsigned int on the system.
//    -- Any input from the keyboard is to be correctly formatted and terminated
//       with an invalid number such as -1.
//------------------------------------------------------------------------------

#include "intset.h"

//------------------------------constructor-------------------------------------
//This constructor can be called with 0 through 5 arguments. Arguments which are
//invalid, like the defaults, I.E negative numbers will be ignored.
IntSet::IntSet(int one, int two, int three, int four, int five) {

  //Check validity of each argument, bool casts, so the sum is the initial size
  unsigned short initial_size = (one >= 0) 
    + (two >= 0)
    + (three >= 0) 
    + (four >= 0)
    + (five >= 0);

  //Allocate the set_members variable with the constructor parameters
  if (initial_size > 0) {
    unsigned int initial_array[initial_size]; //temp array of union members
    unsigned short count = 0;      //keep track of which index to insert at

    //Go through all the passed in values and ignore values that are negative
    if (one >= 0) { initial_array[count++] = one; }
    if (two >= 0) { initial_array[count++] = two; }
    if (three >= 0) { initial_array[count++] = three; }
    if (four >= 0) { initial_array[count++] = four; }
    if (five >= 0) { initial_array[count] = five; }

    //set private member variable largest to the largest of the passed-in values
    largest = findLargest(initial_array, initial_size);

    //allocate the array. set_members must be one larger than the largest 
    //number because the array will start at index 0
    set_members = new bool[largest + 1]; 

    //start from 0 up to the largest integer passed in
    for (unsigned int i = 0; i <= largest; i++) {
      set_members[i] = false;

      //see if the initial array includes the current value, if so, reset the 
      //value to true
      for (unsigned int j = 0; j < initial_size; j++) {
        if (initial_array[j] == i) { set_members[i] = true; }
      }
    }
  } else {
    //the default array is empty, with index 0 as false
    largest = 0;
    set_members = new bool[1]; 
    set_members[0] = false;
  }
}

IntSet::IntSet(int low, int high) {
  if (low > high) {
    throw "Lower bound cannot be greater than the higher bound.";
  }
  set_members = new bool[high + 1]; 
  for (int i = 0; i < low; i++) {
    set_members[i] = false;
  }
  for (int i = low; i <= high; i++) {
    set_members[i] = true;
  }
}

//------------------------------destructor--------------------------------------
//Simply frees the memory of the dynamically-allocated set_members variable 
IntSet::~IntSet() {
  delete[] set_members;
  set_members = NULL;
}

//------------------------------copy constructor--------------------------------
//Initializes an IntSet by using another IntSset which is to be copied
IntSet::IntSet(const IntSet& other) {

  //copy over largest member variable
  largest = other.largest;

  //allocate an array of the same size
  set_members = new bool[largest + 1];

  //iterate through the set_members in the other and set the values for each
  for (unsigned int i = 0; i <= largest; i++) {
    set_members[i] = other.set_members[i];
  }
}

//------------------------------operator+()-------------------------------------
//Operator to create a union of two sets. Returns an IntSet of unique union
//members that are common to one or both of the two operands
IntSet IntSet::operator+(const IntSet& other)const {

  //instantiate the IntSet which will be returned
  IntSet result = other; //the copy constructor is called

  //loop through the current IntSet and insert the values into the result
  for(unsigned int i = 0; i <= largest; i++) {
    if (set_members[i]) {
      result.insert(i);
    }
  }
  return result;
}

//------------------------------operator*()-------------------------------------
//Operator to create an intersection of two sets. Returns an IntSet of unique 
//union members that are common to ONLY both of the two operands
IntSet IntSet::operator*(const IntSet& other)const {

  //instantiate the IntSet which will be returned
  IntSet result;

  //loop through the current array, insert if both have that element
  for(unsigned int i = 0; i <= largest; i++) {
    if (set_members[i] && other.isInSet(i)){
      result.insert(i);
    }
  }
  return result;
}

//------------------------------operator-()-------------------------------------
//Operator to create a difference of two sets such that all elements which are
//in the current IntSet but NOT in the other IntSet
IntSet IntSet::operator-(const IntSet& other)const {
  
  //instantiate the IntSet which will be returned
  IntSet result;

  //loop through the current IntSet and only insert if the other IntSet doesnt
  //contain it.
  for(unsigned int i = 0; i <= largest; i++) {
    if (set_members[i] && !other.isInSet(i)){
      result.insert(i);
    }
  }
  return result;
}

//------------------------------operator=()-------------------------------------
//Assignment operator to replace the contents of the current IntSet with the 
//contents of the other IntSet.
IntSet IntSet::operator=(const IntSet& other) {

  //forgo the assignment if they are the same thing
  if (this != &other) {

    //delete old memory
    delete[] set_members;

    //set the new largest value
    largest = other.largest;

    //allocate the new set_members array
    bool* new_set_members = new bool[largest + 1];

    //copy over values from the other IntSet to the current IntSet
    for(unsigned int i = 0; i <= largest; i++) {

      //sets the local value to either true or false
      new_set_members[i] = other.set_members[i];  
    }

   //swap pointers so the set_members array points to the newly allocated memory
    set_members = new_set_members;
  }
  return *this;
}

//------------------------------operator+=()------------------------------------
//Union operator that changes the value of the current IntSet to the result
IntSet IntSet::operator+=(const IntSet& other) {
  return *this = (*this) + other;
}

//------------------------------operator*=()------------------------------------
//Intersection operator that changes the value of current IntSet to the result
IntSet IntSet::operator*=(const IntSet& other) {
  return *this = (*this) * other;
}

//------------------------------operator-=()------------------------------------
//Difference operator that changes the value of the current IntSet to the result
IntSet IntSet::operator-=(const IntSet& other) {
  return *this = (*this) - other;
}

//------------------------------operator==()------------------------------------
//Equality operator that evaluates whether or not each set mc
bool IntSet::operator==(const IntSet& other)const {

  //If the two IntSets have different lengths, they cannot possibly be equal
  if (other.largest != largest) {return false;}

  //If they are equal size, then walk through the current array and make sure 
  //each value is equal to to that in the other one
  for(unsigned int i = 0; i <= largest; i++) {
    if (set_members[i] && !other.isInSet(i)) {
      return false; 
    }
  }
  return true;
}

//------------------------------operator!=()------------------------------------
//Non-equality operator, which simply calls the equality operator and then
//returns the opposite of the return value of that operator
bool IntSet::operator!=(const IntSet& other)const {
  return !((*this) == other);
}

//------------------------------isEmpty()---------------------------------------
//Checks to see if the current IntSet has no members
bool IntSet::isEmpty()const {
  
  //the IntSet will only be empty if the size is 1 ,signified by largest being 
  //0 AND the value of that single array element is false
  return (largest == 0 && !set_members[0]);
}

//------------------------------isInSet()---------------------------------------
//Search function that goes through the IntSet and sees if the supplied num
//exists in the current set.
bool IntSet::isInSet(const int num)const {

  //invalid or out-of-bounds num will always not be in set
  if (num > largest || num < 0) { return false; }
  return set_members[num];
}

//------------------------------insert()----------------------------------------
//Insert function that takes in a single set member and inserts it into the set,
//reallocating if necessary. Returns a success/failure condition on the insert.
//Will return a false if the system runs out of memory.
bool IntSet::insert(const int num) {

  //fail if negative
  if (num < 0) { return false; } 

  //skip assignment if that value is already in the current IntSet
  if ((*this).isInSet(num)) { return true; } 

  //if num is outside of the current array boundaries
  if (num > largest) {

    //reallocate the array to fit the new largest
    bool* temp_members = new bool[num + 1];

    if (temp_members == NULL) { return false; }//ran out of memory

    //loop through this new size and set all of the values, defaulting to false
    //for elements that exceed the old set_members boundaries
    for (unsigned int i = 0; i <= num; i++) {
      if (i <= largest) {
        temp_members[i] = set_members[i];
      } else {
        temp_members[i] = false;
      }
    }
    largest = num; //num is the new largest within this if statement

    //deallocate the old memory
    delete[] set_members;

    //swap pointers, setting the current set_members array to be new one
    set_members = temp_members;
  }
  //for the new set member, the new largest number, set it to true
  set_members[num] = true;
  return true;
}

//------------------------------remove()----------------------------------------
//Remove function where given a num, it attempts to find that member in the set
//and remove it. Returns the success/failure condition of the removal.
bool IntSet::remove(const int num) {

  //out-of-bounds or invalid values can't be removed because they aren't present
  if (largest == 0 || num < 0) {return false;}

  set_members[num] = false;//member being removed will be internally false now

  //Loop through set members in reverse now to find the new largest
  for (unsigned int i = largest; i >= 0; i--) {
    if (set_members[i]) { 
      largest = i;
      return true;
    }
  }
  largest = 0;//otherwise, zero is the largest
  return true;
}

//------------------------------findLargest()-----------------------------------
//Private utility method to find the largest number in an presumably unsorted
//array of unsigned ints. Used in the constructor
unsigned int IntSet::findLargest(unsigned int numbers[], unsigned int size) {
  if (size == 0) { return 0; }
  unsigned int largest = numbers[0];//default largest is the first element

  //loop through all elements in the array to find a larger one
  for (unsigned int i = 1; i < size; i++) {
    if (numbers[i] > largest) { largest = numbers[i]; }
  }
  return largest;
}

//------------------------------operator<<()------------------------------------
//Friend function to print the contents of an IntSet to an out stream. The 
//output format looks like { 1 2 3} for a non-empty and {} for empty (with 
//no space). Returns the output stream
ostream& operator<<(ostream& sout, const IntSet& set) {
  sout << "{";

  //loop through the elements in the current set, print if its in the set
  for (unsigned int i = 0; i <= set.largest; i++) {
    if (set.isInSet(i)) { 
      sout << ' ' << i; 
    }
  }
  sout << "}";
  return sout;
}

//------------------------------operator>>()------------------------------------
//Input function that allows an istream to assign members to an already 
//instantiated IntSet. Input is terminated with an invalid value such as -1.
//Returns the input stream.
istream& operator>>(istream& sin, IntSet& set) {
  int num; 

  //while a number can still be extracted from the stream
  while (sin >> num) {
    if (!set.insert(num)) { break; }
  }
  return sin;
}
