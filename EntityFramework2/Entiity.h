#ifndef _entity_h_
#define _entity_h_

#include <vector>
#include "Component.h"
#include "ComponentManager.h"
#include "Typedefs.h"

namespace inertia {

	class Game;
	class ComponentManager;

	/** 
		Entities may only be created by the EntityManager which is accessed through the Game class.
	**/
	class Entity {
	public:
		~Entity();

		/** 
		**/
		void	addComponent(Component* component);

		/**
			Call after adding new components to an entity to updated their status is the managers
		**/
		void	update();

		/** 
			Returns identifier for the entity. Id are unique to existing for all active entities
			but deleted entities ids may be reused.
		**/
		int		getId();
	protected:
		Entity(Game* game, EntityId id);
		Entity(const Entity& e);
		
		std::vector<bool> getSystemBits();
		std::vector<bool> getComponentBits();
		
	private:
		Game*	_game;
		ComponentManager* _cm;
		EntityId	_id;						//unique identifier for entity set by entity manager
		std::vector<bool> _componentBits;		//bitset representing component types active in this entity
		std::vector<bool> _systemBits;			//bitset representing systems this entity is being processed by
		
	};
};

#endif