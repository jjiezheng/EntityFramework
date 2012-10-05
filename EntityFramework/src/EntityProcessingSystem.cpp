#include "EntityProcessingSystem.h"
using namespace sturm;
using namespace std;

EntityProcessingSystem::EntityProcessingSystem(vector<const type_info*> componentNames, const type_info* ti) 
	: EntitySystem(componentNames, ti)
{}

EntityProcessingSystem::EntityProcessingSystem(Aspect aspect, const type_info* ti) 
	: EntitySystem(aspect, ti)
{}

EntityProcessingSystem::~EntityProcessingSystem() 
{}


void EntityProcessingSystem::ProcessEntities(list<Entity*> entities) {
	list<Entity*>::iterator it = entities.begin();
	for(; it != entities.end(); ++it) {
		Process(*it);
	}
}

bool EntityProcessingSystem::CheckProcessing() { return true; }
