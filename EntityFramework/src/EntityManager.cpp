#include "EntityManager.h"
using namespace sturm;

uint64 EntityManager::_uniqueIDKey = 0;

EntityManager::EntityManager(World* world) 
: _world(world) 
{

}

EntityManager::~EntityManager() {
	_world = 0;
}

Entity* EntityManager::CreateEntity() {
	Entity* e = new Entity(_world, _uniqueIDKey++);
	_entities[e->GetID()] = e;
	return e;
}

uint64 EntityManager::AddComponent(Entity* e, Component* c) {
	//check if entity exists
	if(_entities[e->GetID()]) {
		
		uint64 componentTypeId = ComponentBitMapper::GetComponentID(c->typeInfo);
		if(componentTypeId == -1) { /* problem */ }
		
		//check if entity already holds that component
		if(!_components[e->GetID()][componentTypeId]) {
			_components[e->GetID()][componentTypeId] = c;
			return ComponentBitMapper::GetComponentID(c->typeInfo);
		}
	}
	return 0;
}

Component* EntityManager::GetComponent(Entity* e, const type_info* type) {
	if(_entities[e->GetID()]) {
		uint64 componentTypeId = ComponentBitMapper::GetComponentID(type);
		return _components[e->GetID()][componentTypeId];
	}
	else return 0;
}

/**
	Push the entity to all systems to update who is monitoring it.
**/
void EntityManager::UpdateEntity(Entity* e) {
	std::map<const type_info*, EntitySystem*> systems = _world->GetSystemMgr()->GetSystems();
	std::map<const type_info*, EntitySystem*>::iterator it = systems.begin();
	for(; it != systems.end(); ++it) {
		it->second->UpdateEntities(e);
	}
}

