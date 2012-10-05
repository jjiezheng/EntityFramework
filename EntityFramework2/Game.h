#ifndef _game_h_
#define _game_h_

#include "Entiity.h"
#include "EntityManager.h"
#include "ComponentManager.h"

namespace inertia {

	class Entity;
	class ComponentManager;
	class EntityManager;

	/** 
	**/
	class Game {
	public:
		Game();
		~Game();

		/** 
		**/
		Entity*			createEntity();

		EntityManager*		getEntityMgr();
		ComponentManager*	getComponentMgr();
	private:
		EntityManager*		_em;
		ComponentManager*	_cm;
	};

};


#endif