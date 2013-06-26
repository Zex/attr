CC = g++
CXXFLAG = -g3 -std=c++11 -pg

% : %.cpp try-attrs.o
	$(CC) $(CXXFLAG) $^ -o $@
	@rm *.o

try-attrs.o : try-attrs.cpp
	$(CC) $(CXXFLAG) -c $^ -o $@

