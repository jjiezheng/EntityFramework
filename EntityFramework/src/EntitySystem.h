#ifndef _entitysystem_h_
#define _entitysystem_h_

#include "World.h"
#include "Entity.h"
#include "Typedefs.h"
#include "Component.h"
#include "ComponentBitMapper.h"
#include "SystemBitMapper.h"
#include <typeinfo>
#include <vector>
#include <list>
#include <string>
#include "Aspect.h"

namespace sturm {
	class EntitySystem {
	public:
		virtual ~EntitySystem();
	protected:
		virtual void PreProcess();
		virtual void PostProcess();
		virtual void EntityAdded(Entity* e);
		virtual void EntityRemoved(Entity* e);
		virtual void ProcessEntities(std::list<Entity*> entities)	= 0;
		virtual bool CheckProcessing()								= 0;
	public:
		void Process();
		void UpdateEntities(Entity* e);
		void SetWorld(World* world);
		void SetSystemBit(uint64 bit);
	protected:
		EntitySystem(std::vector<const type_info*> componentNames, const type_info* ti);
		EntitySystem(Aspect aspect, const type_info* ti);
	protected:
		World* _world;
		std::list<Entity*> _entities;
		uint64 _systemBit;
		uint64 _componentBits;
	public:
		const type_info* const typeInfo;
	};
}

#endif