CC = g++
CFLAGS = -g
CXXLIB_PATH = ~/src/cxxtest

a.out: IdentTypes/*.cpp ScopeNode.cpp STObject.cpp stdriver09.cpp
	${CC} ${CFLAGS} -o $@ $^

clean:
	rm -f *runner.cpp
	rm -f *runner
	rm -f *_test
	rm -f a.out

%_runner.cpp: UnitTests/%TestSuite.h UnitTests/IdentRecordTestHelper.h 
	cxxtestgen.py --error-printer -o $@ $<

#FIXME: might want to remove the identrecord? will deal with this tomorrow
%_test: IdentTypes/IdentRecord.cpp IdentTypes/%.cpp %_runner.cpp
	${CC} ${CFLAGS} -o $@ $^ -I ${CXXLIB_PATH}

run_%_test: %_test
	./$<

test_all:
	find UnitTests -type f | grep "TestSuite\.h$$" | xargs -I {} basename {} | sed -e 's/TestSuite\.h$$//' | xargs -I {} make {}_test
	
#TODO: figure out how to instead glue the make commands together with && so one test stops the whole process
