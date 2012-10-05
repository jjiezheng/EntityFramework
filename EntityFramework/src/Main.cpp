
#include <stdlib.h>
#include "World.h"
#include "ComponentBitMapper.h"
#include <vector>
#include <typeinfo>
#include "Aspect.h"

using namespace sturm;

class C1 : public Component { public: C1() : Component(&typeid(C1)) {}};
class C2 : public Component { public: C2() : Component(&typeid(C2)) {}};
class C3 : public Component { public: C3() : Component(&typeid(C3)) {}};
class C4 : public Component { public: C4() : Component(&typeid(C4)) {}};
class C5 : public Component { public: C5() : Component(&typeid(C5)) {}};

class S1 : public EntitySystem { public: 
	S1() : EntitySystem(Aspect(2, &typeid(C1), &typeid(C5)), &typeid(S1)) {} };

int main(int argc, char** argv) {

	World world;
	Entity* e1 = world.CreateEntity();
	Entity* e2 = world.CreateEntity();
	Entity* e3 = world.CreateEntity();

	SystemManager* sm = world.GetSystemMgr();

	S1* s = new S1();
	sm->RegisterSystem(s);
	
	e1->AddComponent(new C1());
	e1->AddComponent(new C5());
	e1->Refresh();

	e2->AddComponent(new C3());
	e2->AddComponent(new C1());
	e2->AddComponent(new C5());
	e2->Refresh();

	e3->AddComponent(new C2());
	e3->Refresh();
	
	

	return 0;
}