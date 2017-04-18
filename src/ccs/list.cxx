#include "ccs.hxx"

struct ccs::cdr
{
			cdr( void *car, cdr *cdr = 0L);


	void *		_car;
	cdr *		_cdr;
};


ccs::cdr::cdr( void * car, cdr * cdr )
{
	_car = car;
	_cdr = cdr;
}

ccs::baselist::baselist()
	: _cdr( 0L )
{
}

ccs::baselist::~baselist()
{
	cdr * next = _cdr;

	while ( next != 0L )
	{
		cdr * free = next;

		next = free->_cdr;
		delete free;
	}
}

void
ccs::baselist::push( void * item )
{
	_cdr = new cdr( item, _cdr );
}

void *
ccs::baselist::pop()
{
	void * ret = 0L;
	if ( _cdr )
	{
		cdr *	free = _cdr;

		ret = free->_car;
		_cdr = free->_cdr;

		delete free;
	}

	return ret;
}

int
ccs::baselist::mapcar( int (func)(void *) )
{
	int ret = 0;

	for ( cdr * next = _cdr; next != 0L; next = next->_cdr )
	{
		if ( (ret = (func)(next->_car )) < 0 )
		{
			break;
		}
	}
	return ret;
}

int
ccs::baselist::size()
{
	int ret = 0;
	for ( cdr *next = _cdr; next != 0L; next = next->_cdr )
	{
		ret++;
	}
	return ret;
}

