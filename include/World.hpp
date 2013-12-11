#ifndef WORLD_HPP
#define WORLD_HPP
#include "Chunk.hpp"
#include "Entity.hpp"

class World {
	public:
		World();
		std::vector<Chunk*> getChunks();
	private:
		std::vector<Chunk*> chunks;
		std::vector<Entity*> entities;
};

#endif
