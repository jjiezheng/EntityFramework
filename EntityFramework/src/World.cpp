#include "World.h"
using namespace sturm;

World::World() {
	_entityMgr = new EntityManager(this);
	_systemMgr = new SystemManager(this);
}

World::~World() {
	delete _entityMgr;
	delete _systemMgr;
	_entityMgr = 0;
	_systemMgr = 0;
}

Entity* World::CreateEntity() { return _entityMgr->CreateEntity(); }

EntityManager* World::GetEntityMgr() { return _entityMgr; }
SystemManager* World::GetSystemMgr() { return _systemMgr; }