include Makefile.inc
OBJ 		= main.o lex.yy.o actions.o y.tab.o IdentTypes/*.o ParsingHelpers/*.o scopenode.o stobject.o cppgenerator.o
SUBDIRS = IdentTypes ParsingHelpers
ACT 		= actions.h
H 			= y.tab.h tokenconsts.h

# The $ is a macro reference.  The following ident is replaced with the
# specified list.  Parens must be used if the ident is longer than one char.

a.out: $(SUBDIRS) $(OBJ) $H $(ACT)
	$(CC) $(OBJ) -o $@

main.o: main.cpp 
	$(CC) $(CFLAGS) $<

cppgenerator.o: CPPGenerator.cpp
	$(CC) $(CFLAGS) $< -o $@

stobject.o: STObject.cpp
	$(CC) $(CFLAGS) $< -o $@

scopenode.o: ScopeNode.cpp
	$(CC) $(CFLAGS) $< -o $@

IdentTypes: force_look
	cd $@; $(MAKE) 

ParsingHelpers: force_look
	cd $@; $(MAKE) 

actions.o: actions.cpp $(ACT)
	$(CC) $(CFLAGS) $< -o $@

lex.yy.c: lex.l y.tab.c $H
	flex -i $<

lex.yy.o: lex.yy.c 
	$(CC) $(CFLAGS) $< -o $@

y.tab.o: y.tab.c lex.yy.o 
	$(CC) $(CFLAGS) $< -o $@

y.tab.c: y
	yacc -d -v $<

clean: 
	rm -f *.o a.out *.c y.output y.tab.h
	-for d in $(SUBDIRS); do (cd $$d; $(MAKE) clean ); done

force_look:
	true

.PHONY: IdentTypes/*.o ParsingHelpers/*.o
