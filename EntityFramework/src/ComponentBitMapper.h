#ifndef _componentbitmapper_h_
#define _componentbitmapper_h_

#include <map>
#include <string>
#include <typeinfo>
#include "Typedefs.h"

namespace sturm {

	struct ComponentInfo2 {
		ComponentInfo2() : bit(0), id(0) {};
		uint64 bit;
		uint64 id;
	};
	class ComponentBitMapper {
	public:
		friend class Component; //only Component Constructor can AddComponent()

		static uint64 GetComponentBit(const type_info* ti);
		static uint64 GetComponentID(const type_info* ti);
		
	protected:
		static void	  AddComponent(const type_info* ti);
	private:
		static std::map<const type_info*, ComponentInfo2> _hash;
		static uint64 _nextbit;
		static uint64 _nextid;
	};
}

#endif