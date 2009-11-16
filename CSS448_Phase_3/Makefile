OBJ = y.tab.o main.o lex.o         # all object files, the .o  files
                                   # change lex.o to lex.yy.o if (f)lex used
H = y.tab.h tokenconsts.h

# The $ is a macro reference.  The following ident is replaced with the
# specified list.  Parens must be used if the ident is longer than one char.

a.out: $(OBJ) $H                   # a.out depends on everything
	g++ $(OBJ) -o a.out

main.o: main.cpp                   # main.o depends on main.cpp
	g++ -c  main.cpp

lex.o: lex.yy.c
	flex -i lex.l
	g++ -c lex.yy.c -o lex.o

lex.yy.c: y.tab.c $H lex.l                 # lex.yy.c depend on the lex file, lex.l
	lex -i  lex.l                      # include only if you used (f)lex

lex.yy.o: lex.yy.c                 # lex.yy.o depend on lex.yy.c
	g++ -c lex.yy.c                # include this if you used (f)lex

y.tab.o: lex.yy.o y.tab.c                   # y.tab.o depends on y.tab.c
	g++ -c y.tab.c

y.tab.c: y                         # y.tab.c depends on the yacc file, y   
	yacc -d -v y                   # -d separates out defines into .h file

clean: 
	rm -f *.o a.out *.c y.output y.tab.h
