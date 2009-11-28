include ../Makefile.inc
OBJ = ArrayType.o BooleanType.o CharacterType.o Constant.o Function.o IdentRecord.o IntegerType.o Parameter.o PointerType.o Procedure.o Program.o ProgramParameter.o RealType.o RecordField.o RecordType.o SetType.o Variable.o

all: $(OBJ)

%.o: %.cpp %.h
	${CC} ${CFLAGS} $< -o $@ 	

clean: 
	rm -f *.o
