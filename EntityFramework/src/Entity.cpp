#include "Entity.h"
using namespace sturm;

Entity::Entity(World* world, uint64 uniqueID) 
	: _uniqueID(uniqueID), _world(world), _componentBits(0), _systemBits(0)
{

}

void Entity::AddComponent(Component* comp) {
	_componentBits |= _world->GetEntityMgr()->AddComponent(this, comp);
}

Component* Entity::GetComponent(const type_info* type) {
	return _world->GetEntityMgr()->GetComponent(this, type);
}

void Entity::Refresh() {
	_world->GetEntityMgr()->UpdateEntity(this);
}

uint64 Entity::GetID()					{ return _uniqueID; }
uint64 Entity::GetSystemBits()			{ return _systemBits; }
uint64 Entity::GetComponentBits()		{ return _componentBits; }
void Entity::AddSystemBit(uint64 sb)	{ _systemBits |= sb; }
void Entity::RemoveSystemBit(uint64 sb) { _systemBits &= ~sb; }