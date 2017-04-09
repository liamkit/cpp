#include <iostream>

#include "ccs/ccs.hxx"

int
p(int *p)
{
	std::cout << *p << std::endl;
	return 0;
}

int
d(int *p)
{
	delete p;
	return 0;
}

int
main( int argc, char *argv[] )
{
	ccs::fio	fio(1);

	std::cout << "hello, world" << std::endl;

	{
		ccs::list<int>	l;

		l.push(new int(1));
		l.push(new int(2));
		l.push(new int(4));
		l.push(new int(8));
		l.push(new int(16));
		l.push(new int(32));

		int * ip = l.pop();
		std::cout << "pop1 " << *ip << std::endl;
		delete ip;

		ip = l.pop();
		std::cout << "pop2 " << *ip << std::endl;
		delete ip;

		l.mapcar( p );
		l.mapcar( d );
	}


	return 0;
}
