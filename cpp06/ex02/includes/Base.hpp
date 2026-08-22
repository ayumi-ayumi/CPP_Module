#ifndef _BASE_H_
#define _BASE_H_

class Base
{
	public:
		Base();
		virtual ~Base();
};

Base* generate();
void identify(Base* p);
void identify(Base& p);

#endif
