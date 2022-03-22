#ifndef object_construction_hpp
#define object_construction_hpp

#include <stdio.h>

class object{
public:
	object();
	void operator=(const object &);
	object(object&);
	~object();

private:
};

#endif
