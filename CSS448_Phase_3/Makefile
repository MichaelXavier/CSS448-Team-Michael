CC = g++
OBJ = main.o lex.o y.tab.o actions.o     # all object files, the  .o  files
H = lex.h lexextern.h
ACT = actions.h actextern.h        

lex.out: $(OBJ) $H $(ACT)         # lex.out depends on everything
	$(CC) $(OBJ) -o lex.out

main.o:	$H main.cpp                 # main.o depends on the .h's of H and main.c
	$(CC) -g -c main.cpp

actions.o: $(ACT) actions.cpp       # actions.o depends on .h's of ACT
	$(CC) -c actions.cpp          #                      and actions.c

lex.o: $H lex.c                   # lex.o depends on lex.h, lexextern.h, lex.c
	$(CC) -c lex.c

y.tab.o: y.tab.c                  # y.tab.o depends on y.tab.c
	$(CC) -c y.tab.c

y.tab.c: yacc.y                   # y.tab.c depends on yacc.y
	yacc -v $<

clean:
	rm -f *.cpp *.c *.o *.out

