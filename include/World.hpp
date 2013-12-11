#ifndef WORLD_HPP
#define WORLD_HPP
#include "Chunk.hpp"

class World {
	public:
		World();
	private:
		std::vector<Chunk> chunks;
};

#endif
