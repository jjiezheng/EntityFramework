#include "Entiity.h"

using namespace inertia;

Entity::Entity(Game* game, EntityId id) 
	: _id(id), _game(game)
{
	_cm = _game->getComponentMgr();
	componentBits.reset();
	systemBits.reset();
}

Entity::~Entity() {}

void Entity::addComponent(Component* comp) {
	_cm->addComponent(this, comp);
}

int Entity::getId() { return _id; }



