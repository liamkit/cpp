#include "ccs.h"


struct ccs::cdr
{
	struct cdr *	cdr;
	void *		car;
}

ccs::baselist::baselist()
	: _cdr( 0L )
{
}

ccs::baselist::~baselist()
{
	struct cdr **	cdrp = _cdr;
	struct cdr *	free;

	while ( (free = *cdrp) != 0L )
	{
		cdrp = &free->cdr;
		delete free;
	}
}


