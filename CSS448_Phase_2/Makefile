CC = g++
DEBUGFLAGS = -g
#CXXLIB_PATH = ~/src/cxxtest

a.out: IdentTypes/*.cpp ScopeNode.cpp STObject.cpp stdriver09.cpp
	${CC} -o $@ $^

debug_a.out: IdentTypes/*.cpp ScopeNode.cpp STObject.cpp stdriver09.cpp
	${CC} ${DEBUGFLAGS} -o $@ $^

clean:
	rm -f *runner.cpp
	rm -f *runner
	rm -f *_test
	rm -f a.out
	rm -f junktest.out
