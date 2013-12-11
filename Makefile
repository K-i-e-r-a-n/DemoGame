CC := clang++
CXX := $(CC)
CXXFLAGS := -Wall -ggdb -I ./SFML-2.1/include -I include -std=c++11
LDFLAGS := -L ./SFML-2.1/lib -lsfml-graphics -lsfml-window -lsfml-system
OBJS := $(patsubst %.cpp, %.o, $(wildcard src/*.cpp))

game: $(OBJS)
	$(CC) -o bin/game $(CXXFLAGS) $(LDFLAGS) $(OBJS)

clean: 
	rm bin/game
	rm $(OBJS)

.PHONY: clean

