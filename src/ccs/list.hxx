#ifndef __CCS_LIST__
#define __CCS_LIST__

struct cdr;

class baselist
{
public:
			baselist();
	~		baselist();


protected:
	struct cdr *	_cdr;
};

#endif
