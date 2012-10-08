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
		Manages all components linked to entities
	**/
	class ComponentManager {
	public:
		friend class Game;

	public:
		/** 
			Add a component to an entity. If an entity already has the component,
			the previous component is deleted and replaced with the new component.
		**/
		void addComponent(Entity* e, Component* c);

		/** 
			Remove a component from an entity. Nothing happens if entity does not hold
			the provided component.
		**/
		void removeComponent(Entity* e, const type_info* type);

		/** 
			Retrieves the desired component type attached to the entity. Returns null if 
			the entity does not have the component type attached to it
		**/
		Component* getComponent(Entity* e, const type_info* type);

	protected:
		ComponentManager(Game* game);
		ComponentManager(const ComponentManager& cm) {};

	private:
		Game* _game;
		ComponentsByTypeMap _componentByType;
	};
};

#endif