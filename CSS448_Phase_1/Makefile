CXXLIB_PATH = ~/src/cxxtest

a.out:  ll main.cpp tokennames.h
				flex -i ll
				g++ lex.yy.c main.cpp

clean:
	rm -f a.out
	rm -f lex.yy.c
	rm -f output
	rm -f lex.h
	rm -f runner.cpp
	rm -f runner

lex.yy.c: ll 
	lex -i --header-file=lex.h ll

runner.cpp: 
	cxxtestgen.py --error-printer -o runner.cpp Phase1TestSuite.h

runner: Phase1TestSuite.h ll tokenconsts.h tokennames.h lex.yy.c runner.cpp
	g++ -g -o runner lex.yy.c runner.cpp -I ${CXXLIB_PATH}
