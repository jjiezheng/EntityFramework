#include "EF.h"
#include "Aspect.h"
#include <typeinfo>
using namespace inertia;

class c1 : public Component {
public:
	c1() : Component(&typeid(c1)) {};
};
class c2 : public Component {
public:
	c2() : Component(&typeid(c2)) {};
};


int main(int argc, char** argv) {

	Aspect a;
	a.addComponent<c1>()->addComponent<c2>();
	Game* game = new Game();
	Entity* e = game->createEntity();
	Component* c = e->getComponent<c1>();
	e->addComponent(new c1());
	c = e->getComponent<c1>();
	e->removeComponent<c1>();
	e->addComponent(new c1());
	e->addComponent(new c1());
	
	



	return 0;
}