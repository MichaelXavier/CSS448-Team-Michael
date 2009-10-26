#ifndef IDENTRECORD_H
#define IDENTRECORD_H
#include <iostream>
#include <string>

using namespace std;

class IdentRecord {
public:
  IdentRecord(const string& name);
	~IdentRecord(void);				// Destructor

	int strcmp(const IdentRecord& rhs)const;	// Compares the this and parameter's ident name
	virtual void display(int depth)const = 0;			// Displays data held in record, pure virtual
	string getName(void) {return identName;} // Returns the identifier name

  //Needed by the map used in ScopeNode, FIXME: i was told only less than is needed. 
  //At compile time we'll find out if we need more
  bool operator<(const IdentRecord& rhs)const; 
protected:
	string identName;					// The name of the identifier

  void printIndent(int depth)const;
};
#endif
