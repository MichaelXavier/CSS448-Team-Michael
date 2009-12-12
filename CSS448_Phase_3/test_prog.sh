make
./a.out < $1 > /dev/null 2> test.cpp && cat test.cpp && g++ test.cpp -o test.out
