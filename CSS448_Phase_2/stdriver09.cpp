#include <iostream>
#include "IdType.h"
#include "STObject.h"

#include "IdentTypes/IdentRecord.h"
#include "IdentTypes/ArrayType.h"
#include "IdentTypes/BooleanType.h"
#include "IdentTypes/CharacterType.h"
#include "IdentTypes/Constant.h"
#include "IdentTypes/Function.h"
#include "IdentTypes/IdentRecord.h"
#include "IdentTypes/IntegerType.h"
#include "IdentTypes/Parameter.h"
#include "IdentTypes/PointerType.h"
#include "IdentTypes/Procedure.h"
#include "IdentTypes/RealType.h"
#include "IdentTypes/RecordField.h"
#include "IdentTypes/RecordType.h"
#include "IdentTypes/SetType.h"
#include "IdentTypes/Variable.h"


using namespace std;

// These are the types of identifiers stored. 
// The type is not actually needed, but is included for clarity 
// in this phase; it may be useful for debugging.

// Simulates seeing identifiers in the right order as if you were
// scanning a pascal program.  The hardcoded strings would be stored 
// in a variable obtained from your lexical analyzer (LEX).
// Any numbers would be ynumber tokens (or yinteger, yreal if you added that).
// The numbers would be stored in some associated variable from LEX string.
// I will refer to names in grammar for attributes stored.
// Adjust as needed for your implementation.

int main() {
	Program* newProg = new Program("example");
   STObject st(newProg);  

   Constant* tempConst;
   ArrayType* tempArray;
   Parameter* tempParam;
   PointerType* tempPointer;
   RecordField* tempField;
   RecordType* tempRecord;
   SetType* tempSet;
   Variable* tempVariable;
   Procedure* tempProcedure;
   Function* tempFunction;

   IdentRecord* typePtr;

   bool something;

   // create a table holding standard identifiers (sit): 
   //      integer, real, boolean, char

   // something could be bool or ptr
   // assume first insert is the program, possible scopeEntry
  // tempProcedure = new Procedure("example");           // program example(...);
  // something = st.insert(tempProcedure, procedure);    
                                             
   tempConst = new Constant("grades");             //       grades = 5; 
   something = st.insert(tempConst, constant);     
   tempConst->setConstFactor(5);
   tempConst = new Constant("size");
   something = st.insert(tempConst, constant);        
   tempConst->setConstFactor(5);


												// type 
   tempArray = new ArrayType("int3d");             //   int3D = array [1..5,2..3,0..2]
   something = st.insert(tempArray, arraytype);    //           of integer;
   tempArray->addDimension(1, 5);
   tempArray->addDimension(2, 3);
   tempArray->addDimension(0, 2);
   typePtr = st.lookup("integer");
   tempArray->setTypePtr(typePtr);


   tempPointer = new PointerType("cellptr");  //   cellPtr = ^cell;
   something = st.insert(tempPointer, pointertype);            
   tempRecord = new RecordType("cell");          //   cell = record 
   something = st.insert(tempRecord, recordtype);
   // Sets cellPtr to point to cell type
   tempPointer->setPointObj(tempRecord);	
   tempField = new RecordField("id");              //      id: integer;
   something = tempRecord->insertField(tempField);      
   typePtr = st.lookup("integer");
   tempField->setTypePtr(typePtr);
   tempField = new RecordField("info");            //      info: int3D;
   something = tempRecord->insertField(tempField);  
   typePtr = st.lookup("int3d");
   tempField->setTypePtr(typePtr);
   tempField = new RecordField("id");              //      id: real;
   something = tempRecord->insertField(tempField); 
                                             // produce error: "id" exists
   tempField = new RecordField("next");            //      next: cellPtr;
   something = tempRecord->insertField(tempField);    
   typePtr = st.lookup("cellptr");
   tempField->setTypePtr(typePtr);
                                             //   end;

   // note that we will assume that sets are limited to 256 ordinal items
   tempSet = new SetType("digit");               //   Digit = set of 0..9;
   something = st.insert(tempSet, settype);    
   tempSet->setRange(0,9);

                                             // var  
   tempVariable = new Variable("list");               //      list: cellPtr;
   something = st.insert(tempVariable, variable);   
   typePtr = st.lookup("cellptr");
   tempVariable->setTypePtr(typePtr);
   tempVariable = new Variable("newrec");             //      newrec: cellPtr;
   something = st.insert(tempVariable, variable);    
   typePtr = st.lookup("cellptr");
   tempVariable->setTypePtr(typePtr);
   tempVariable = new Variable("count");              //      count: int3D;
   something = st.insert(tempVariable, variable);    
   typePtr = st.lookup("int3d");
   tempVariable->setTypePtr(typePtr);
   tempVariable = new Variable("classnum");           //      classNum: integer;
   something = st.insert(tempVariable, variable);    
   typePtr = st.lookup("integer");
   tempVariable->setTypePtr(typePtr);

   // scopeEntry
   // use bool tag for parameters that are "var", pass by reference
   // no "var" means pass by value
   tempProcedure = new Procedure("proc1");      // procedure proc1(var list: cellPtr;
                                          //                 var theA: int3D;
                                          //                      rec: cellPtr);
   something = st.insert(tempProcedure, procedure);    
   tempParam = new Parameter("list");
   tempParam->setVar(true);
   typePtr = st.lookup("cellptr");
   tempParam->setTypePtr(typePtr);
   something = tempProcedure->insertParameter(tempParam); 
   tempParam = new Parameter("thea");
   tempParam->setVar(true);
   typePtr = st.lookup("int3d");
   tempParam->setTypePtr(typePtr);
   something = tempProcedure->insertParameter(tempParam); 
   tempParam = new Parameter("rec");
   tempParam->setVar(false);
   typePtr = st.lookup("cellptr");
   tempParam->setTypePtr(typePtr);
   something = tempProcedure->insertParameter(tempParam); 

                                             // var  
   tempVariable = new Variable("count");              //      count: integer;
   something = st.insert(tempVariable, variable);    
   // don't forget to search for locals in the param list, repeat names not allowed
   typePtr = st.lookup("integer");
   tempVariable->setTypePtr(typePtr);
   tempVariable = new Variable("x1");                 //      x1: integer;
   typePtr = st.lookup("integer");
   tempVariable->setTypePtr(typePtr);
   something = st.insert(tempVariable, variable);    
   tempVariable = new Variable("y");                  //      y: integer;
   typePtr = st.lookup("integer");
   tempVariable->setTypePtr(typePtr);
   something = st.insert(tempVariable, variable);    
 //  look up "integer" in st; if not there, get it from sit, in typeptr

   st.printST();
   // scopeExit of proc1                     // end of proc1
   


   // scopeEntry
   tempProcedure = new Procedure("proc2");         // procedure proc2(...);
   something = st.insert(tempProcedure, procedure);    
                                             // var  
   tempVariable = new Variable("count");              //      count: int3D;
   typePtr = st.lookup("int3d");
   tempVariable->setTypePtr(typePtr);
   something = st.insert(tempVariable, variable);    
   tempVariable = new Variable("x2");                 //      x2: integer;
   typePtr = st.lookup("integer");
   tempVariable->setTypePtr(typePtr);
   something = st.insert(tempVariable, variable);    
   tempVariable = new Variable("y");                  //      y: integer;
   typePtr = st.lookup("integer");
   tempVariable->setTypePtr(typePtr);
   something = st.insert(tempVariable, variable);    
   tempVariable = new Variable("z");                  //      z: integer;
   typePtr = st.lookup("integer");
   tempVariable->setTypePtr(typePtr);
   something = st.insert(tempVariable, variable);    
   tempVariable = new Variable("y");                  //      y: integer;
   something = st.insert(tempVariable, variable);    
                                             // produce error: "y" exists

   // scopeEntry
   tempProcedure = new Procedure("proc2a");         //    procedure proc2a(...);
   something = st.insert(tempProcedure, procedure);    
                                              //    var  
   tempVariable = new Variable("count");               //      count: int3D;
   something = st.insert(tempVariable, variable);    
   typePtr = st.lookup("int3d");
   tempVariable->setTypePtr(typePtr);
   tempVariable = new Variable("x2a");                 //      x2a: integer;
   typePtr = st.lookup("integer");
   tempVariable->setTypePtr(typePtr);
   something = st.insert(tempVariable, variable);    
   tempVariable = new Variable("y");                   //      y: integer;
   typePtr = st.lookup("integer");
   tempVariable->setTypePtr(typePtr);
   something = st.insert(tempVariable, variable);    
   tempVariable = new Variable("z");                   //      z: integer;
   typePtr = st.lookup("integer");
   tempVariable->setTypePtr(typePtr);
   something = st.insert(tempVariable, variable);    

   
   // scopeEntry
   tempProcedure = new Procedure("proc2b");         //    procedure proc2b(...);
   something = st.insert(tempProcedure, procedure);    
                                              //    var  
   tempVariable = new Variable("x2b");                 //      x2b: integer;
   typePtr = st.lookup("integer");
   tempVariable->setTypePtr(typePtr);
   something = st.insert(tempVariable, variable);    
   tempVariable = new Variable("y");                   //      y: integer;
   typePtr = st.lookup("integer");
   tempVariable->setTypePtr(typePtr);
   something = st.insert(tempVariable, variable);    

   // scopeEntry
   tempProcedure = new Procedure("proc2c");         //    procedure proc2c(...);
   something = st.insert(tempProcedure, procedure);    
                                              //    const
   tempConst = new Constant("someconst");           //        someConst = 10; 
   something = st.insert(tempConst, constant);     
   tempConst->setConstFactor(10);
   tempConst = new Constant("theconst");            //        theConst = 20;
   tempConst->setConstFactor(20);
   something = st.insert(tempConst, constant);        

                                              //    var  
   tempVariable = new Variable("x2c");                 //      x2c: integer;
   typePtr = st.lookup("integer");
   tempVariable->setTypePtr(typePtr);
   something = st.insert(tempVariable, variable);    
   tempVariable = new Variable("y");                   //      y: integer;
   typePtr = st.lookup("integer");
   tempVariable->setTypePtr(typePtr);
   something = st.insert(tempVariable, variable);    
   tempVariable = new Variable("x2c");                 //      x2c: integer;
   something = st.insert(tempVariable, variable);    
                                              // produce error: "x2c" exists

   // scopeEntry 
   // could use new Function if desired
   tempFunction = new Function("func2d");         //    function func2d(  
   something = st.insert(tempFunction, function);    
                                              //      newrec: cellPtr): integer;
   tempParam = new Parameter("newrec");
   tempParam->setVar(false);
   typePtr = st.lookup("cellptr");
   tempParam->setTypePtr(typePtr);
   something = tempFunction->insertParameter(tempParam); 
   typePtr = st.lookup("integer");
   tempFunction->setReturnType(typePtr);


   // Not sure if this is correct:
                                              //    var  
                                              //      a: array [5..10] of real;
   tempVariable = new Variable("a");               
   something = st.insert(tempVariable, variable);    
   tempArray = new ArrayType("NONAME"); 
   tempArray->addDimension(5, 10);
   typePtr = st.lookup("real");
   tempArray->setTypePtr(typePtr);
   tempVariable->setTypePtr(tempArray); // ?

   st.printST();
   // scopeExit of func2d              // end of func2d
   // scopeExit of proc2c              // end of proc2c
   // scopeExit of proc2b              // end of proc2b
   // scopeExit of proc2a              // end of proc2a
   // scopeExit of proc2               // end of proc2
   // scopeExit of example             // end of example

 
   return 0;
}


