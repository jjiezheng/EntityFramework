#ifndef _componentmapper_h_
#define _componentmapper_h_

#include "World.h"
using namespace sturm;

template<class T>
class ComponentMapper {
public:
	ComponentMapper(World* world);
	T* GetComponent(Entity* e);
private:
	World* _world;
};

template<class T>
ComponentMapper<T>::ComponentMapper(World* world) : _world(world) {}
template<class T>
T* ComponentMapper<T>::GetComponent(Entity* e) {
	return (T*)(_world->GetEntityMgr()->GetComponent(e, &typeid(T)));
}


#endif