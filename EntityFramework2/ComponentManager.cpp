#include "ComponentManager.h"

using namespace inertia;

ComponentManager::ComponentManager(Game* game) 
	: _game(game)
{

}

void ComponentManager::addComponent(Entity* e, Component* c) {
	ComponentType* type = ComponentTypeMap::getTypeFor(c->typeInfo);

	//check if entity already holds this components
	if(_componentByType[type->getIndex()][e->getId()] != 0) {
		//TODO: clean up previous components?
	}
	
	_componentByType[type->getIndex()][e->getId()] = c;
	//e->getComponentBits()[type->getIndex()] = true;
}