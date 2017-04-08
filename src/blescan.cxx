#include <iostream>

#include "ccs/ccs.hxx"

int
main( int argc, char *argv[] )
{
	ccs::fio	fio(1);

	std::cout << "hello, world" << std::endl;

	{
		ccs::list<int>	l;

		l.push(1);
		l.push(2);
	}


	return 0;
}
