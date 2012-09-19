#ifndef _entity_h_
#define _entity_h_


#include "Typedefs.h"
#include "Component.h"
#include "World.h"

namespace sturm {

	class World;

	class Entity {
	public:
		Entity(World* world, uint64 uniqueID);

		void AddComponent(Component* comp);
		Component* GetComponent(const type_info* type);
		void Refresh();
		uint64 GetID();
		uint64 GetSystemBits();
		uint64 GetComponentBits();
		void AddSystemBit(uint64 sb);
		void RemoveSystemBit(uint64 sb);
	private:
		World*		_world;
		uint64		_uniqueID;
		uint64		_componentBits;
		uint64		_systemBits;
	};
}

#endif