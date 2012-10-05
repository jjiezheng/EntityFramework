#ifndef _entityprocessingsystem_h_
#define _entityprocessingsystem_h_

#include "EntitySystem.h"
using namespace sturm;

class EntityProcessingSystem : public EntitySystem {
public:
	EntityProcessingSystem(std::vector<const type_info*> componentNames, const type_info* ti);
	EntityProcessingSystem(Aspect aspect, const type_info* ti);
	virtual ~EntityProcessingSystem();
	
protected:
	virtual void Process(Entity* e) = 0;
	bool CheckProcessing();
	void ProcessEntities(std::list<Entity*> entities);
};

#endif