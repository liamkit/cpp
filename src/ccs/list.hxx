#ifndef __CCS_LIST__
#define __CCS_LIST__

struct cdr;

class baselist
{
public:
			baselist( void );
	~		baselist( void );


	void		push( void * item );
	void *		pop( void );

protected:
	struct cdr *	_cdr;
};


template<class T>
class list : baselist
{
public:
	void		push( T item ) { baselist::push( (void*) item ); }
	T		pop( void ) { (T)baselist::pop(); }
};

#endif
