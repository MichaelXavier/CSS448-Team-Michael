// IdentRecord.h
// Abstract class from which other identifier types derive.

#ifndef IDENTRECORD_H
#define IDENTRECORD_H
#include <iostream>
#include <sstream>
#include <string>
#include <queue>

using namespace std;

class IdentRecord {

public:
  IdentRecord(const string& name);
  virtual ~IdentRecord(void);			

  // Compares the this and parameter's ident name
  int strcmp(const IdentRecord& rhs)const;

  // Displays data held in record, pure virtual
  virtual void display(ostream& out, int depth)const = 0;		

  // Returns the identifier name
  string getName(void)const {return identName;} 

  // Needed by the map used in ScopeNode
  bool operator==(const IdentRecord& rhs)const;
  bool operator<(const IdentRecord& rhs)const; 

  string getInstanceName() { return instanceName; } 

  // This should be overridden for classes that need the
  // hasConflictingParams function.  This is in order to keep
  // 2 levels of inheritance.
  virtual bool hasConflictingParams(const IdentRecord*)const 
  {     cout << "WARNING: IdentRecord's hasConflictingParams called for name" 
        << identName << endl; return true;
  }

  virtual IdentRecord* lookupParameter(const string&) const
  {
	  cout << "WARNING: IdentRecord's lookupParameter called for name"
           << identName << endl; return NULL;
  }

protected:
  string identName;					// The name of the identifier
  string instanceName;				// Stores the name of the class

  // Prints an indent for printing out ST
  void printIndent(ostream& sout, int depth)const; 

};
#endif
