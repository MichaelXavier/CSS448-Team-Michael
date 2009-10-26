CC = g++
CFLAGS = -g
CXXLIB_PATH = ~/src/cxxtest

clean:
	rm -f *runner.cpp
	rm -f *runner
	rm -f *_test

%_runner.cpp: UnitTests/%TestSuite.h
	cxxtestgen.py --error-printer -o $@ $^

%_test: IdentTypes/IdentRecord.cpp IdentTypes/%.cpp %_runner.cpp
	${CC} ${CFLAGS} -o $@ $^ -I ${CXXLIB_PATH}
	./$@

test_all:
	find UnitTests -type f | grep "TestSuite\.h$$" | xargs -I {} basename {} | sed -e 's/TestSuite\.h$$//' | xargs -I {} make {}_test
	
#TODO: figure out how to instead glue the make commands together with && so one test stops the whole process
