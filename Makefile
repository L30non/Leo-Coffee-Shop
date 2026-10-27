# Makefile for Leo Coffee Shop POS
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra
TARGET = main
OBJS = main.o ui.o menu.o cart.o checkout.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp types.h ui.h menu.h cart.h checkout.h
	$(CXX) $(CXXFLAGS) -c main.cpp

ui.o: ui.cpp ui.h
	$(CXX) $(CXXFLAGS) -c ui.cpp

menu.o: menu.cpp menu.h types.h ui.h
	$(CXX) $(CXXFLAGS) -c menu.cpp

cart.o: cart.cpp cart.h menu.h types.h ui.h
	$(CXX) $(CXXFLAGS) -c cart.cpp

checkout.o: checkout.cpp checkout.h cart.h types.h ui.h
	$(CXX) $(CXXFLAGS) -c checkout.cpp

clean:
	rm -f $(TARGET) *.o
