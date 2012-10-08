#include "Game.h"
using namespace inertia;

Game::Game() {
	_em = new EntityManager(this);
	_cm = new ComponentManager(this);
}

Game::~Game() {
	delete _em; _em = 0;
	delete _cm; _cm = 0;
}

Entity* Game::createEntity() {
	return _em->createEntity();
}

void Game::addSystem(EntitySystem* es) {
	if(_systems[es->typeInfo] != 0) {
		//TODO: handle previous system
	}
	es->setGame(this);
	_systems[es->typeInfo] = es;
}

EntityManager* Game::getEntityMgr() { return _em ; }

ComponentManager* Game::getComponentMgr() { return _cm ; }


