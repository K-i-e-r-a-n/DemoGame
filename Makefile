CC := clang++
CXX := $(CC)
CXXFLAGS := -Wall -std=c++11 -ggdb -stdlib=libc++ -I ~/SFML-2.1/include -I include
LDFLAGS := -L ~/SFML-2.1/lib -lsfml-graphics -lsfml-window -lsfml-system
OBJS := $(patsubst %.cpp, %.o, $(wildcard src/*.cpp))

game: $(OBJS)
	$(CC) -o bin/game $(CXXFLAGS) $(LDFLAGS) $(OBJS)

clean: 
	rm bin/game
	rm $(OBJS)

.PHONY: clean

