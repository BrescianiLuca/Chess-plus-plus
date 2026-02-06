CXX = g++
CXXFLAGS = -std=c++11 -Wall -g
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

SRCS = main.cpp game.cpp pieces/gamepiece.cpp pieces/pawn.cpp pieces/bishop.cpp pieces/rook.cpp pieces/king.cpp pieces/queen.cpp pieces/knight.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = chess_game

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
