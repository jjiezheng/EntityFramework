#ifndef _component_manager_h_
#define _component_manager_h_

#include "Game.h"
#include "Entiity.h"
#include "Component.h"
#include "ComponentType.h"
#include "Typedefs.h"
#include <typeinfo>
#include <map>

namespace inertia {

	class Entity;
	class Game;

	typedef std::map<EntityId, Component*> EntityComponentMap;
	typedef std::map<int, EntityComponentMap> ComponentsByTypeMap;

	/** 
	**/
	class ComponentManager {
	public:
		/** 
		**/
		void addComponent(Entity* e, Component* c);
	protected:
		ComponentManager(Game* game);
		ComponentManager(const ComponentManager& cm) {};
	private:
		Game* _game;
		ComponentsByTypeMap _componentByType;
	};
};

#endif