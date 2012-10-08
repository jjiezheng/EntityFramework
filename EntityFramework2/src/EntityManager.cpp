#include "EntityManager.h"

using namespace inertia;

EntityManager::EntityManager(Game* game) 
	: _game(game) 
{}

EntityManager::~EntityManager() {}

Entity* EntityManager::createEntity() {
	Entity* e = new Entity(_game, _idPool.takeId());
	_entities[e->getId()] = e;
	return e;
}

