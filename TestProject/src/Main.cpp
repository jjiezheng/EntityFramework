#include <EntityFramework.h>
#include <stdlib.h>
#include <typeinfo>

using namespace sturm;


class Renderable : public Component {
public:
	Renderable() 
		: Component(&typeid(Renderable)) 
	{}
};

class RenderSystem : public EntityProcessingSystem {
public:

	RenderSystem() : EntityProcessingSystem(Aspect(1, &typeid(Renderable)), &typeid(RenderSystem)) 	{
	
	};

	void Process(Entity* e) {
	}
};


int main(int argc, char** argv) {

	World* world = new World();
	Entity* e1 = world->CreateEntity();
	world->GetSystemMgr()->RegisterSystem(new RenderSystem());

	e1->AddComponent(new Renderable());
	e1->Refresh();





	system("pause");
	return 0;
}