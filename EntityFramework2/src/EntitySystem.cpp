#include "EntitySystem.h"
using namespace inertia;

EntitySystem::EntitySystem(Aspect* aspect, const type_info* ti) 
	: _aspect(aspect),  typeInfo(ti)
{

}

EntitySystem::~EntitySystem() {}

void EntitySystem::preProcess() {}
void EntitySystem::postProcess() {}
void EntitySystem::entityAdded(Entity* e) {}
void EntitySystem::entityRemoved(Entity* e) {}
void EntitySystem::process() {
	if(checkProcessing()) {
		preProcess();
		processEntities(&_entities);
		postProcess();
	}
}
void EntitySystem::setGame(Game* game) { _game = game; }