OBJ = y.tab.o main.o lex.o         # all object files, the .o  files
                                   # change lex.o to lex.yy.o if (f)lex used
H = y.tab.h tokenconsts.h

# The $ is a macro reference.  The following ident is replaced with the
# specified list.  Parens must be used if the ident is longer than one char.

a.out: $(OBJ) $H             
	g++ $(OBJ) -o a.out

main.o: main.cpp            
	g++ -c  main.cpp

lex.o: lex.yy.c
	g++ -c lex.yy.c -o lex.o

lex.yy.c: y.tab.c $H lex.l  
	flex -i --header-file=lex.h lex.l  

lex.yy.o: lex.yy.c              
	g++ -c lex.yy.c                

y.tab.o: lex.yy.o y.tab.c      
	g++ -c y.tab.c

y.tab.c: y                    
	yacc -d -v y                   

clean: 
	rm -f *.o a.out *.c y.output y.tab.h lex.h
