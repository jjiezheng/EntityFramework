#ifndef _systembitmapper_h_
#define _systembitmapper_h_

#include <map>
#include <string>
#include <typeinfo>
#include "Typedefs.h"

namespace sturm {
	struct SystemInfo2 {
		SystemInfo2() : bit(0), id(0) {};
		uint64 bit;
		uint64 id;
	};
	class SystemBitMapper {
	public:
		friend class EntitySystem;

		static uint64 GetSystemBit(const type_info* ti);
		static uint64 GetSystemID(const type_info* ti);
	protected:
		static void AddSystem(const type_info* ti);
	private:
		static std::map<const type_info*, SystemInfo2> _hash;
		static uint64 _nextbit;
		static uint64 _nextid;
	};
}

#endif