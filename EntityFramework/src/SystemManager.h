#ifndef _systemmanager_h_
#define _systemmanager_h_

#include "World.h"

#include "EntitySystem.h"

#include "SystemBitMapper.h"
#include <map>
#include <list>

namespace sturm {

	class World;

	class EntitySystem;

	class SystemManager {
	public:
		SystemManager(World* world);
		~SystemManager();


		EntitySystem* RegisterSystem(EntitySystem* system);
		std::map<const type_info*, EntitySystem*> GetSystems();
	private:
		World* _world;

		std::map<const type_info*, EntitySystem*> _entitySystems;
	};
}

#endif
