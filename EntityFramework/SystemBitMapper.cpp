#include "SystemBitMapper.h"
using namespace std;
using namespace sturm;

uint64 SystemBitMapper::_nextbit = 1;
uint64 SystemBitMapper::_nextid  = 0;
map<const type_info*, SystemInfo2> SystemBitMapper::_hash;

void SystemBitMapper::AddSystem(const type_info* ti) {
	//may need to track the size of the hash since we only have 64 bits
	map<const type_info*, SystemInfo2>::iterator it = _hash.find(ti);
	if (it == _hash.end()) {
		SystemInfo2 ci;
		ci.bit = _nextbit;
		ci.id = _nextid++;
		_hash[ti] = ci;
		_nextbit = _nextbit << 1;

	}
}

uint64 SystemBitMapper::GetSystemBit(const type_info* ti) {
	map<const type_info*, SystemInfo2>::iterator it = _hash.find(ti);
	if (it == _hash.end()) {
		return 0;
	}
	else {
		return it->second.bit;
	}
}

uint64 SystemBitMapper::GetSystemID(const type_info* ti) {
	map<const type_info*, SystemInfo2>::iterator it = _hash.find(ti);
	if (it == _hash.end()) {
		return -1;
	}
	else {
		return it->second.id;
	}
}