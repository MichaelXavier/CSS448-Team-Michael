CC = g++
CFLAGS = -g -o
CXXLIB_PATH = ~/src/cxxtest

clean:
	rm -f runner.cpp
	rm -f runner
	rm -f procedure_runner.cpp
	rm -f procedure_runner

procedure_runner.cpp: UnitTests/ProcedureTestSuite.h
	cxxtestgen.py --error-printer -o $@ $^

procedure_runner: IdentTypes/IdentRecord.cpp IdentTypes/Procedure.cpp procedure_runner.cpp
	${CC} ${CFLAGS} $@ $^ -I ${CXXLIB_PATH}
	./$@
