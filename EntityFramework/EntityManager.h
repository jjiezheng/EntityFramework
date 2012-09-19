#ifndef _entitymanager_h_
#define _entitymanager_h_

#include "World.h"
#include "Entity.h"
#include "Typedefs.h"
#include "Component.h"
#include <map>

namespace sturm {

	class World;
	class Entity;

	class EntityManager {
	public:
		EntityManager(World* world);
		~EntityManager();

		Entity* CreateEntity();
		uint64	AddComponent(Entity* e, Component* c);
		Component* GetComponent(Entity* e, const type_info* type);
		void	UpdateEntity(Entity* e);
	private:
		static uint64 _uniqueIDKey;

		World*	_world;
		std::map<uint64, Entity*> _entities;
		std::map<uint64, std::map<uint64, Component*>> _components;
	};
}

#endif