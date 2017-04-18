#include "ccs.hxx"

static ccs::list<fio>	FIO_LIST;

ccs::fio::fio( int fd )
	: _fd( fd )
{
	FIO_LIST.push(this);
}

ccs::fio::~fio()
{
	if ( _fd >= 0 )
	{
		close( _fd );
		_fd = -1;
	}

	FIO_LIST.remove(this);
}

