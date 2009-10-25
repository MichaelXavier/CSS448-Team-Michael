CXXLIB_PATH = ~/src/cxxtest

clean:
	rm -f runner.cpp
	rm -f runner

procedure_runner.cpp: UnitTests/ProcedureTestSuite.h
	cxxtestgen.py --error-printer -o $@ $^

procedure_runner: IdentTypes/IdentRecord.cpp IdentTypes/Procedure.cpp procedure_runner.cpp
	g++ -g -o $@ $^ -I ${CXXLIB_PATH}
	./$@
