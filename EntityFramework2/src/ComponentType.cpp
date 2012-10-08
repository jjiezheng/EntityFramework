#include "ComponentType.h"

using namespace inertia;

int ComponentTypeMap::_indexKey = 0;
std::map<const type_info*, ComponentType*> ComponentTypeMap::_componentTypes;

ComponentType::ComponentType(const type_info* type, int index) {
	_index = index++;
	_type = type;
}

int ComponentType::getIndex() { return _index; }





ComponentType* ComponentTypeMap::getTypeFor(const type_info* type) {
	ComponentType* componentType = _componentTypes[type];

	if(componentType == 0) {
		componentType = new ComponentType(type, _indexKey++);
		_componentTypes[type] = componentType;
	}

	return componentType;
}

int ComponentTypeMap::getIndexFor(const type_info* type) {
	return getTypeFor(type)->getIndex();
}