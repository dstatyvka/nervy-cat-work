
SRC=Main.cpp TList.cpp TNode.cpp

prog: Main.o TList.o TNode.o

# %.obj: %.cpp
# 	$(CXX) $(CFLAGS) $(CXXFLAGS) -c $^ -o $@
