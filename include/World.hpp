#ifndef WORLD_HPP
#define WORLD_HPP
#include "Chunk.hpp"
//#include "Entity.hpp" until this is fixed

class World {
	public:
		World();
		std::vector<Chunk*> getChunks();
		void draw();
	private:
		std::vector<Chunk*> chunks;
		//std::vector<Entity*> entities;
};

#endif
