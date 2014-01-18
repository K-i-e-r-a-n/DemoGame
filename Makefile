CC := clang++
CXX := $(CC)
CXXFLAGS := -Wall -ggdb -I ~/dev/SFML-2.1/include -I include -std=c++11
LDFLAGS := -L ~/dev/SFML-2.1/lib -lsfml-graphics -lsfml-window -lsfml-system
OBJS := $(patsubst src/%.cpp, src/%.o, $(wildcard src/*.cpp))

game: $(OBJS)
	$(CC) -o bin/game $(CXXFLAGS) $(LDFLAGS) $(OBJS)

clean: 
	rm $(OBJS)

.PHONY: clean

