CXX = g++
CXXFLAGS = -std=c++11 -Wall -g
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

SRCS = main.cpp game.cpp gamepiece.cpp pawn.cpp bishop.cpp rook.cpp king.cpp queen.cpp knight.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = chess_game

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
