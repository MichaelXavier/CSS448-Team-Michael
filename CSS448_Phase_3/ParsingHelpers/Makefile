include ../Makefile.inc
OBJ = ArrayHelper.o ConstDecHelper.o FunctionHelper.o PointerHelper.o ProcedureHelper.o ProgramHelper.o RecordHelper.o SetHelper.o TypeHelper.o VarDecHelper.o 

all: $(OBJ)

%.o: %.cpp %.h
	${CC} ${CFLAGS} $< -o $@ 	

clean: 
	rm -f *.o
