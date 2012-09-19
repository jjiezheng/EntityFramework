#include "EntitySystem.h"
using namespace sturm;
using namespace std;

EntitySystem::EntitySystem(vector<const type_info*> componentTypes, const type_info* ti) 
	: _world(0), _systemBit(0), _componentBits(0), typeInfo(ti)
{
	SystemBitMapper::AddSystem(ti);

	vector<const type_info*>::iterator it = componentTypes.begin();
	for(; it != componentTypes.end(); ++it) {
		_componentBits |= ComponentBitMapper::GetComponentBit(*it);
	}
}

EntitySystem::EntitySystem(Aspect aspect, const type_info* ti) 
	: _world(0), _systemBit(0), _componentBits(0), typeInfo(ti)
{
	
	SystemBitMapper::AddSystem(ti);

	vector<const type_info*>::iterator it = aspect.components.begin();
	for(; it != aspect.components.end(); ++it) {
		_componentBits |= ComponentBitMapper::GetComponentBit(*it);
	}
}

EntitySystem::~EntitySystem() {
	_world = 0;
}

void EntitySystem::Initialize() {}
void EntitySystem::PreProcess() {}
void EntitySystem::PostProcess() {}
void EntitySystem::SetWorld(World* world)		{ _world = world; }
void EntitySystem::SetSystemBit(uint64 bit)		{ _systemBit = bit; }

/** 
	Add or remove the entity based on its components
**/
void EntitySystem::UpdateEntities(Entity* e) {
	bool containsEntity = (e->GetSystemBits() & _systemBit)	== _systemBit;
	bool addEntity		= (e->GetComponentBits() & _componentBits) == _componentBits;

	if(addEntity && !containsEntity) { //add
		_entities.push_back(e);
		e->AddSystemBit(_systemBit);
		EntityAdded(e);
	}
	else if(!addEntity && containsEntity) { //remove
		_entities.remove(e);
		e->RemoveSystemBit(_systemBit);
		EntityRemoved(e);
	}
}

void EntitySystem::EntityAdded(Entity* e) {}
void EntitySystem::EntityRemoved(Entity* e) {}

bool EntitySystem::CheckProcessing() { return true; }

void EntitySystem::Process() {
	if(CheckProcessing()) {
		PreProcess();
		ProcessEntities(_entities);
		PostProcess();
	}	
}

void EntitySystem::ProcessEntities(std::list<Entity*> entities) {

}