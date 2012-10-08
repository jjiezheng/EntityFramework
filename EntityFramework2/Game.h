#ifndef _game_h_
#define _game_h_

#include "Entiity.h"
#include "EntityManager.h"
#include "ComponentManager.h"
#include "EntitySystem.h"
#include <map>
#include <typeinfo>

namespace inertia {

	class Entity;
	class EntitySystem;
	class ComponentManager;
	class EntityManager;

	/** 
	**/
	class Game {
	public:
		Game();
		~Game();

		/** 
			Creates a new entity, adds it to the game world and returns it
		**/
		Entity*	createEntity();

		/** 
		**/
		void addSystem(EntitySystem* es);	

		EntityManager*		getEntityMgr();
		ComponentManager*	getComponentMgr();
	private:
		EntityManager*		_em;
		ComponentManager*	_cm;

		std::map<const type_info*, EntitySystem*> _systems;
	};

};


#endif