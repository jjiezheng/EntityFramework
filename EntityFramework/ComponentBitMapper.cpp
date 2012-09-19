#include "ComponentBitMapper.h"
using namespace std;
using namespace sturm;

uint64 ComponentBitMapper::_nextbit = 1;
uint64 ComponentBitMapper::_nextid  = 0;
map<const type_info*, ComponentInfo2> ComponentBitMapper::_hash;

void ComponentBitMapper::AddComponent(const type_info* ti) {
	//may need to track the size of the hash since we only have 64 bits
	map<const type_info*, ComponentInfo2>::iterator it = _hash.find(ti);
	if (it == _hash.end()) {
		ComponentInfo2 ci;
		ci.bit = _nextbit;
		ci.id = _nextid++;
		_hash[ti] = ci;
		_nextbit = _nextbit << 1;

	}
}

uint64 ComponentBitMapper::GetComponentBit(const type_info* ti) {
	map<const type_info*, ComponentInfo2>::iterator it = _hash.find(ti);
	if (it == _hash.end()) {
		AddComponent(ti);
		return GetComponentBit(ti);
	}
	else {
		return it->second.bit;
	}
}

uint64 ComponentBitMapper::GetComponentID(const type_info* ti) {
	map<const type_info*, ComponentInfo2>::iterator it = _hash.find(ti);
	if (it == _hash.end()) {
		AddComponent(ti);
		return GetComponentID(ti);
	}
	else {
		return it->second.id;
	}
}