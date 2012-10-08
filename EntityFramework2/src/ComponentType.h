#ifndef _component_type_h_
#define _component_type_h_

#include <typeinfo>
#include <map>

namespace inertia{
	
	class ComponentType {
	public:
		ComponentType(const type_info* type, int index);
		int getIndex();
	private:
		const type_info* _type;
		int _index;	
		
	};


	/**
		Generates and stores unique index per component type
	**/
	class ComponentTypeMap {
		friend ComponentType;

		public:
		/** 
		**/
		static ComponentType* getTypeFor(const type_info* type);
		
		/** 
		**/
		static int getIndexFor(const type_info* type);
	private:
		static int _indexKey;
		static std::map<const type_info*, ComponentType*> _componentTypes;
	};
};

#endif
