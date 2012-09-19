#ifndef _component_h_
#define _component_h_

#include "Typedefs.h"
#include "ComponentBitMapper.h"
#include <typeinfo>



namespace sturm {

	class Component {
	protected:
		Component(const type_info* ti);
	public:
		const type_info* const typeInfo;
	};
}

#endif