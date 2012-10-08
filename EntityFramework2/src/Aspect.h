#ifndef _aspect_h_
#define _aspect_h_

#include <typeinfo>
#include <stdarg.h>
#include <vector>

namespace inertia {

	class Aspect {
	public:
		template<typename T>
		Aspect* addComponent() {
			_types.push_back(&typeid(T));
			return this;
		}
	private:
		std::vector<const type_info*> _types;

	};
};

#endif