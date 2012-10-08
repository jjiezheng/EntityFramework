#ifndef _entity_system_h_
#define _entity_system_h_

#include "Aspect.h"
#include "Entiity.h"
#include "Game.h"
#include <list>
#include <typeinfo>

namespace inertia {

	class Game;

	class EntitySystem {
	public:
		friend class Game;
	public:
		EntitySystem(Aspect* aspect, const type_info* ti);
		~EntitySystem();
	protected:
		virtual void preProcess();
		virtual void postProcess();
		virtual void entityAdded(Entity* e);
		virtual void entityRemoved(Entity* e);

		/**
			Can't modify the list of entities
		**/
		virtual void processEntities(std::list<Entity*> const* entities) = 0;	
		virtual bool checkProcessing() = 0;

		void process();
		void setGame(Game* game);
	protected:
		Game* _game;
		Aspect* _aspect;
		std::list<Entity*> _entities;

	public:
		const type_info* typeInfo;
		
	};
};


#endif