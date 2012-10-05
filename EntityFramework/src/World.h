#ifndef _world_h_
#define _world_h_

#include "Entity.h"
#include "EntityManager.h"
#include "SystemManager.h"

namespace sturm {

	class Entity;
	class EntityManager;
	class SystemManager;

	class World {
	public:
		World();
		~World();

		Entity*			CreateEntity();
		EntityManager*	GetEntityMgr();
		SystemManager*  GetSystemMgr();
	private:
		EntityManager* _entityMgr;
		SystemManager* _systemMgr;
	};
}

#endif