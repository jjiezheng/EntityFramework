#include "ComponentManager.h"

using namespace inertia;

ComponentManager::ComponentManager(Game* game) 
	: _game(game)
{

}

void ComponentManager::addComponent(Entity* e, Component* c) {
	ComponentType* type = ComponentTypeMap::getTypeFor(c->typeInfo);
	Component* comp = _componentByType[type->getIndex()][e->getId()];

	//check if entity already holds this components
	if(comp != 0) {
		//clean up old component
		_componentByType[type->getIndex()][e->getId()] = 0;
		delete comp;
	}
	
	_componentByType[type->getIndex()][e->getId()] = c;

	e->componentBits.set(type->getIndex(), true);
}

void ComponentManager::removeComponent(Entity* e, const type_info* type) {
	int index = ComponentTypeMap::getIndexFor(type);
	Component* c = _componentByType[index][e->getId()];


	//check if entity holds this component
	if(c != 0) {
		//remove component and cleanup
		_componentByType[index][e->getId()] = 0;
		delete c;
		
	}

	//just in case
	e->componentBits.set(index, false);
}

Component* ComponentManager::getComponent(Entity* e, const type_info* type) {
	return _componentByType[ComponentTypeMap::getIndexFor(type)][e->getId()];
}