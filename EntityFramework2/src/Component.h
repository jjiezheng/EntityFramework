#ifndef _component_h_
#define _component_h_

#include <typeinfo>

namespace inertia {

	/** 
	**/
	class Component {
	protected:
		Component(const type_info* ti) : typeInfo(ti) {};
	public:
		const type_info* const typeInfo;
	};
;
};

#endif