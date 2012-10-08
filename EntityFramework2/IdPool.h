#ifndef _idpool_h_
#define _idpool_h_

#include <list>

namespace inertia {

	class IdPool {
	public:
		IdPool() {
			_idKey = 0;
		};

		int  takeId() {
			if(_returnedIds.empty())
				return _idKey++;
			else {
				int id = _returnedIds.front();
				_returnedIds.pop_front();
				return id;
			}
		};
		void returnId(int id) {
			_returnedIds.push_back(id);
		};

	private:
		int _idKey;
		std::list<int> _returnedIds;
	}; 

};
 
#endif // !_idpool_h_
