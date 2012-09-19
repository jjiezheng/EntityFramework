#ifndef _aspect_h_
#define _aspect_h_

#include <string>
#include "Typedefs.h"
#include <typeinfo>
#include <stdarg.h>


namespace sturm {
	struct Aspect {
		Aspect(int num_args, ...) {
			va_list vl;
			const type_info* val;
			va_start(vl,num_args);
			for (int i = 0; i < num_args; ++i)
			{
				val = va_arg(vl,const type_info*);
				components.push_back(val);
			}
			va_end(vl);
		}
		std::vector<const type_info*> components;
	};
}

#endif