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

#%_runner.cpp: UnitTests/%TestSuite.h UnitTests/IdentRecordTestHelper.h 
#	cxxtestgen.py --error-printer -o $@ $<
#
#%_test: IdentTypes/IdentRecord.cpp IdentTypes/%.cpp %_runner.cpp
#	${CC} ${CFLAGS} -o $@ $^ -I ${CXXLIB_PATH}
#
#run_%_test: %_test
#	./$<
#
#test_all:
#	find UnitTests -type f | grep "TestSuite\.h$$" | xargs -I {} basename {} | sed -e 's/TestSuite\.h$$//' | xargs -I {} make {}_test
