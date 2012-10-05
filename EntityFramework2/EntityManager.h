#ifndef _entity_manager_h_
#define _entity_manager_h_

#include "Game.h"
#include "Entiity.h"
#include "Typedefs.h"
#include <map>

namespace inertia {

	class Game;
	class Entity;

	typedef std::map<EntityId, Entity*> EntityMap;

	/** 
	**/
	class EntityManager {
	public:
		~EntityManager();

		Entity* CreateEntity();
	protected:
		EntityManager(Game* game);
		EntityManager(const EntityManager& em);
	private:
		Game* _game;
		EntityMap _entities;
	};
};

#endif 