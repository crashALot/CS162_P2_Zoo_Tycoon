#target: dependencies
#	rule to build
#
# Work cited: https://askubuntu.com/questions/433943/how-to-clean-executable-using-make-clean
# 	      https://www.cs.bu.edu/teaching/cpp/writing-makefiles/

CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -g
CXXFLAGS += -Wall 
#CXXFLAGS += -O3
#CXXFLAGS += -pedantic-errors
#LDFLAGS = -lboost_date_time
OBJS =animal.o zooMenu.o penguin.o tiger.o turtle.o zoo.o zooMain.o zooValidation.o
SRCS =animal.cpp zooMenu.cpp penguin.cpp tiger.cpp turtle.cpp zoo.cpp zooMain.cpp zooValidation.cpp
HEADERS = animal.hpp zooMenu.hpp penguin.hpp tiger.hpp turtle.hpp zoo.hpp zooValidation.hpp

zooMain: ${OBJS}
	${CXX} ${CXXFLAGS} -o zooMain zooMain.o animal.o penguin.o tiger.o turtle.o zoo.o zooValidation.o zooMenu.o

zooMain.o: zooMain.cpp ${HEADERS}
	 ${CXX} ${CXXFLAGS} -c zooMain.cpp

animal.o: animal.hpp
penguin.o: penguin.hpp
tiger.o: tiger.hpp
turtle.o: turtle.hpp
zoo.o: zoo.hpp
zooValidation.o: zooValidation.hpp
zooMenu.o: zooMenu.hpp

clean: ${OBJS}
	-rm *.o ${OBJS} zooMain
