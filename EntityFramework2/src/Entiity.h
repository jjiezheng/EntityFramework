#ifndef _entity_h_
#define _entity_h_

#include <vector>
#include <bitset>
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
		friend class ComponentManager;
		friend class EntityManager;

	public:
		~Entity();

		/** 
			Adds a component to the entity through the ComponentManager
		**/
		void addComponent(Component* component);

		/** 
			Removes a component from the entity through the ComponentManager
		**/ 
		template<typename T>
		void removeComponent() {
			_cm->removeComponent(this, &typeid(T));
		};

		/**
			Return specified component type attached to entity
		**/
		template<typename T>
		Component* getComponent() {
			return _cm->getComponent(this, &typeid(T));
		};

		/**
			Call after adding new components to an entity to updated their status is the managers
		**/
		void update();

		/** 
			Returns identifier for the entity. Id are unique to existing for all active entities
			but deleted entities ids may be reused.
		**/
		int	 getId();

	protected:
		Entity(Game* game, EntityId id);
		Entity(const Entity& e);
		

	protected:
		std::bitset<64> componentBits;		//bitvector representing component types active in this entity
		std::bitset<64> systemBits;			//bitvector representing systems this entity is being processed by

	private:
		Game*	_game;
		ComponentManager* _cm;
		EntityId	_id;				//unique identifier for entity set by entity manager
	
		
		
	};
};

#endif