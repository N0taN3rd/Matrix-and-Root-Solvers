MAINPROG=417Solvers
CPPS:=main.cpp MatVecUtil.cpp MatrixMethods.cpp Roots.cpp MenuSelections.cpp ReadWriteMatrix.cpp FunctionFactory.cpp Function.cpp XTerm.cpp MathTerm.cpp EndTerm.cpp RootOperations.cpp MatrixOperations.cpp
DIR=${PWD}

CPPFLAGS=-std=c++11 -g 
TARGET=$(MAINPROG)$(EXE)
CPP=g++
LINK=$(CPP) $(CPPFLAGS)

OBJS=$(CPPS:%.cpp=%.o)
DEPENDENCIES = $(CPPS:%.cpp=%.d)


%.d: %.cpp
	touch $@

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -MMD -o $@ -c $*.cpp

# 
# Targets:
# 
all: $(TARGET)



$(TARGET): $(OBJS)
	$(LINK) $(FLAGS) -o $(TARGET) $(OBJS) $(LFLAGS)

clean:
	-/bin/rm -f *.d *.o $(TARGET)


make.dep: $(DEPENDENCIES)
	-cat $(DEPENDENCIES) > $@

include make.dep
