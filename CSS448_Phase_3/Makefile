CC = g++
OBJ = y.tab.o main.o lex.yy.o
H = y.tab.h tokenconsts.h

# The $ is a macro reference.  The following ident is replaced with the
# specified list.  Parens must be used if the ident is longer than one char.

a.out: $(OBJ) $H
	$(CC) $(OBJ) -o $@

main.o: main.cpp ScopeNode.cpp STObject.cpp
	$(CC) -c $^

lex.yy.c: lex.l y.tab.c $H
	flex -i $< #rule1

lex.yy.o: lex.yy.c
	$(CC) -c $< -o $@ #rule2

y.tab.o: y.tab.c lex.yy.o 
	$(CC) -c $< -o $@ #rule3

y.tab.c: y
	yacc -d -v $< #rule4

clean: 
	rm -f *.o a.out *.c y.output y.tab.h
