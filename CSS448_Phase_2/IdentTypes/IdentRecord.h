#ifndef IDENTRECORD_H
#define IDENTRECORD_H
#include <iostream>
#include <string>

using namespace std;

class IdentRecord {
public:
  IdentRecord(const string& name);
	virtual ~IdentRecord(void);				// Destructor

	int strcmp(const IdentRecord& rhs)const;	// Compares the this and parameter's ident name
	virtual void display(ostream& out, int depth)const = 0;			// Displays data held in record, pure virtual
	string getName(void)const {return identName;} // Returns the identifier name

  //Needed by the map used in ScopeNode, FIXME: i was told only less than is needed. 
  //At compile time we'll find out if we need more
  bool operator==(const IdentRecord& rhs)const;
  bool operator<(const IdentRecord& rhs)const; 

  // Doesn't do anything, but can be overridden
  virtual bool hasConflictingParams(const IdentRecord*)const {return true;}

protected:
	string identName;					// The name of the identifier

  void printIndent(ostream& sout, int depth)const;
};
#endif
