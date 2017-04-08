#include "ccs.hxx"

struct ccs::cdr
{
			cdr( void * car, cdr * cdr = 0L ) { _car = car; _cdr = cdr; }
	~		cdr() {};

	cdr *		_cdr;
	void *		_car;
};

ccs::baselist::baselist()
	: _cdr( 0L )
{
}

ccs::baselist::~baselist()
{
	struct cdr *	next = _cdr;

	while ( next != 0L )
	{
		struct cdr * free = next;

		next = free->_cdr;
		delete free;
	}
	_cdr = 0L;
}

void
ccs::baselist::push( void * item )
{
	ccs::cdr * cdr = new ccs::cdr( item, _cdr );
	_cdr = cdr;
}

void *
ccs::baselist::pop()
{
	void * ret = 0L;

	if ( _cdr )
	{
		ccs::cdr * cdr = _cdr;

		_cdr = cdr->_cdr;
		ret = cdr->_car;
		delete _cdr;
	}
	return ret;
}
