#include "SystemManager.h"
using namespace sturm;

SystemManager::SystemManager(World* world) 
	: _world(world)
{

}

SystemManager::~SystemManager() {
	_world = 0;
}



/** 
	Register Systems and set its systembit
**/
EntitySystem* SystemManager::RegisterSystem(EntitySystem* system) {
	system->SetWorld(_world);
	_entitySystems[system->typeInfo] = system;
	uint64 systemBit = SystemBitMapper::GetSystemBit(system->typeInfo);
	if(systemBit == 0) { /*problem*/}
	system->SetSystemBit(systemBit);
	system->Initialize();
	return system;
}

std::map<const type_info*, EntitySystem*> SystemManager::GetSystems() { return _entitySystems; }