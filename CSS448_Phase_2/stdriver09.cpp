
// These are the types of identifiers stored. 
// The type is not actually needed, but is included for clarity 
// in this phase; it may be useful for debugging.
enum IdType {arraytype, pointertype, recordtype, settype,
             constant, variable, procedure, function, recordfield, parameter};

// Simulates seeing identifiers in the right order as if you were
// scanning a pascal program.  The hardcoded strings would be stored 
// in a variable obtained from your lexical analyzer (LEX).
// Any numbers would be ynumber tokens (or yinteger, yreal if you added that).
// The numbers would be stored in some associated variable from LEX string.
// I will refer to names in grammar for attributes stored.
// Adjust as needed for your implementation.
int main() {
   STObject st;
   IdentRecord* ptr;           // or IdentObject or IdentNode
   IdentRecord* typeptr;     
   IdentRecord* recptr;     
   IdentRecord* pointerptr;     
   IdentRecord* procptr;     
   IdentRecord* tempptr;     

   // create a table holding standard identifiers (sit): 
   //      integer, real, boolean, char

   // something could be bool or ptr
   // assume first insert is the program, possible scopeEntry
   ptr = new Procedure("example");           // program example(...);
   something = st.insert(ptr, procedure);    
                                             // const  
   ptr = new Constant("grades");             //       grades = 5;
   something = st.insert(ptr, constant);     
   ptr->set the constant's value, the ConstFactor to 5
   ptr = new Constant("size");               //       size = 4;
   something = st.insert(ptr, constant);        
   ptr->set the constant's value, the ConstFactor to 4

                                             // type 
   ptr = new ArrayType("int3d");             //   int3D = array [1..5,2..3,0..2]
   something = st.insert(ptr, arraytype);    //           of integer;
   dimension initially set to one
   ptr->set low of dim1 to ConstFactor of 1
   ptr->set high of dim1 to ConstFactor of 5
   now you get to know it has 2 dimensions
   ptr->set low of dim2 to ConstFactor of 2
   ptr->set high of dim2 to ConstFactor of 3
   now you get to know it has 3 dimensions
   ptr->set low of dim3 to ConstFactor of 0
   ptr->set high of dim3 to ConstFactor of 2
   look up "integer" in st; if not there, get it from sit, in typeptr
   ptr-> set array type to typeptr

   pointerptr = new PointerType("cellptr");  //   cellPtr = ^cell;
   something = st.insert(recptr, pointertype);            
   // have to hang onto pointerptr and identifier "cell" to set later
   recptr = new RecordType("cell");          //   cell = record 
   something = st.insert(ptr, recordtype);    
   //now you have recptr to "cell" object, can set pointerptr's attribute
   ptr = new RecordField("id");              //      id: integer;
   something = recptr->insertField(ptr, recordfield);      
   look up "integer" in st; if not there, get it from sit, in typeptr
   ptr-> set type to typeptr
   ptr = new RecordField("info");            //      info: int3D;
   something = recptr->insertField(ptr, recordfield);    
   look up "int3D" in st, in typeptr
   ptr-> set type to typeptr
   ptr = new RecordField("id");              //      id: real;
   something = recptr->insertField(ptr, recordfield); 
                                             // produce error: "id" exists
   ptr = new RecordField("next");            //      next: cellPtr;
   something = recptr->insertField(ptr, recordfield);    
   look up "cellPtr" in st, in typeptr
   ptr-> set type to typeptr
                                             //   end;

   // note that we will assume that sets are limited to 256 ordinal items
   ptr = new SetType("digit");               //   Digit = set of 0..9;
   something = st.insert(ptr, settype);    
   set ptr's range to go from 0 to 9

                                             // var  
   ptr = new Variable("list");               //      list: cellPtr;
   something = st.insert(ptr, variable);    
   look up "cellPtr" in st, in typeptr
   ptr-> set type to typeptr
   ptr = new Variable("newrec");             //      newrec: cellPtr;
   something = st.insert(ptr, variable);    
   look up "cellPtr" in st, in typeptr
   ptr-> set type to typeptr
   ptr = new Variable("count");              //      count: int3D;
   something = st.insert(ptr, variable);    
   look up "int3D" in st, in typeptr
   ptr-> set type to typeptr
   ptr = new Variable("classnum");           //      classNum: integer;
   something = st.insert(ptr, variable);    
   look up "integer" in st; if not there, get it from sit, in typeptr
   ptr-> set type to typeptr

   // scopeEntry
   // use bool tag for parameters that are "var", pass by reference
   // no "var" means pass by value
   procptr = new Procedure("proc1");      // procedure proc1(var list: cellPtr;
                                          //                 var theA: int3D;
                                          //                      rec: cellPtr);
   something = st.insert(procptr, procedure);    
   ptr = new Parameter("list");
   look up "cellPtr" and set ptr's typeptr
   something = procptr->insertParameter(ptr, parameter); 
   ptr = new Parameter("thea");
   look up "int3D" and set ptr's typeptr
   something = procptr->insertParameter(ptr, parameter); 
   ptr = new Parameter("rec");
   look up "cellPtr" and set ptr's typeptr
   something = procptr->insertParameter(ptr, parameter); 

                                             // var  
   ptr = new Variable("count");              //      count: integer;
   something = st.insert(ptr, variable);    
   don't forget to search for locals in the param list, repeat names not allowed
   look up "integer" in st; if not there, get it from sit, in typeptr
   ptr = new Variable("x1");                 //      x1: integer;
   something = st.insert(ptr, variable);    
   look up "integer" in st; if not there, get it from sit, in typeptr
   ptr = new Variable("y");                  //      y: integer;
   something = st.insert(ptr, variable);    
   look up "integer" in st; if not there, get it from sit, in typeptr

   st.printST();
   // scopeExit of proc1                     // end of proc1
   
   // scopeEntry
   procptr = new Procedure("proc2");         // procedure proc2(...);
   something = st.insert(procptr, procedure);    
                                             // var  
   ptr = new Variable("count");              //      count: int3D;
   something = st.insert(ptr, variable);    
   look up "int3D" and set ptr's typeptr
   ptr = new Variable("x2");                 //      x2: integer;
   something = st.insert(ptr, variable);    
   look up "integer" in st; if not there, get it from sit, in typeptr
   ptr = new Variable("y");                  //      y: integer;
   something = st.insert(ptr, variable);    
   look up "integer" in st; if not there, get it from sit, in typeptr
   ptr = new Variable("z");                  //      z: integer;
   something = st.insert(ptr, variable);    
   look up "integer" in st; if not there, get it from sit, in typeptr
   ptr = new Variable("y");                  //      y: integer;
   something = st.insert(ptr, variable);    
                                             // produce error: "y" exists

   // scopeEntry
   procptr = new Procedure("proc2a");         //    procedure proc2a(...);
   something = st.insert(procptr, procedure);    
                                              //    var  
   ptr = new Variable("count");               //      count: int3D;
   something = st.insert(ptr, variable);    
   look up "int3D" and set ptr's typeptr
   ptr = new Variable("x2a");                 //      x2a: integer;
   something = st.insert(ptr, variable);    
   look up "integer" in st; if not there, get it from sit, in typeptr
   ptr = new Variable("y");                   //      y: integer;
   something = st.insert(ptr, variable);    
   look up "integer" in st; if not there, get it from sit, in typeptr
   ptr = new Variable("z");                   //      z: integer;
   something = st.insert(ptr, variable);    
   look up "integer" in st; if not there, get it from sit, in typeptr
   
   // scopeEntry
   procptr = new Procedure("proc2b");         //    procedure proc2b(...);
   something = st.insert(procptr, procedure);    
                                              //    var  
   ptr = new Variable("x2b");                 //      x2b: integer;
   something = st.insert(ptr, variable);    
   look up "integer" in st; if not there, get it from sit, in typeptr
   ptr = new Variable("y");                   //      y: integer;
   something = st.insert(ptr, variable);    
   look up "integer" in st; if not there, get it from sit, in typeptr
   
   // scopeEntry
   procptr = new Procedure("proc2c");         //    procedure proc2c(...);
   something = st.insert(procptr, procedure);    
                                              //    const
   ptr = new Constant("someconst");           //        someConst = 10; 
   something = st.insert(ptr, constant);     
   ptr->set the constant's value, the ConstFactor to 10
   ptr = new Constant("theconst");            //        theConst = 20;
   something = st.insert(ptr, constant);        
   ptr->set the constant's value, the ConstFactor to 20

                                              //    var  
   ptr = new Variable("x2c");                 //      x2c: integer;
   something = st.insert(ptr, variable);    
   look up "integer" in st; if not there, get it from sit, in typeptr
   ptr = new Variable("y");                   //      y: integer;
   something = st.insert(ptr, variable);    
   look up "integer" in st; if not there, get it from sit, in typeptr
   ptr = new Variable("x2c");                 //      x2c: integer;
   something = st.insert(ptr, variable);    
                                              // produce error: "x2c" exists

   // scopeEntry 
   // could use new Function if desired
   procptr = new Procedure("func2d");         //    function func2d(
   something = st.insert(procptr, function);    
                                              //      newrec: cellPtr): integer;
   ptr = new Parameter("newrec");
   look up "cellPtr" and set ptr's typeptr
   something = procptr->insertParameter(ptr, parameter); 
   look up "integer" in st; if not there, get it from sit, in typeptr
   set pointer for the function return type to typeptr
                                              //    var  
                                              //      a: array [5..10] of real;
   ptr = new Variable("a");               
   something = st.insert(ptr, variable);    
   tempptr = new ArrayType("NONAME");             
   dimension initially set to one
   ptr->set low of dim1 to ConstFactor of 5
   ptr->set high of dim1 to ConstFactor of 10
   look up "real" in st; if not there, get it from sit, in typeptr
   ptr-> set array type to typeptr

   st.printST();
   // scopeExit of func2d              // end of func2d
   // scopeExit of proc2c              // end of proc2c
   // scopeExit of proc2b              // end of proc2b
   // scopeExit of proc2a              // end of proc2a
   // scopeExit of proc2               // end of proc2
   // scopeExit of example             // end of example

   return 0;
}

