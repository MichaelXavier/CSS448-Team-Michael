#ifndef IDENTRECORD_H
#define IDENTRECORD_H
#include <iostream>
#include <string>

class IdentRecord {
public:
  IdentRecord(char*);
  virtual ~IdentRecord(void);//Virtual destructor needed to properly deallocate child classes

  //Generic display method, pure virtual method so subclasses must implement it
  virtual void display(void)const = 0;
  bool operator>(const IdentRecord&)const;
  bool operator<(const IdentRecord&)const;

  //supposedly just needs a strcmp of some sort. not sure if its only comparing name
  bool operator==(const IdentRecord&)const;

private:
  //FIXME: might want to store a char* instead? strings are easier to work with though
  string type_name;//Stores the type name of the class. Set in subclass' constructors. Not 100% sure if needed
  string name;
}
#endif
