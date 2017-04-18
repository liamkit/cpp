#ifndef __CCS_LIST__
#define __CCS_LIST__

struct cdr;

class baselist
{
public:
				baselist();
	~			baselist();

	typedef int		(*mcf)(void *);

	int			size();


protected:
	int			mapcar( mcf );
	int			remove( void * item );
	void			push( void * item );
	void *			pop();

	cdr *			_cdr;
};

template <class T>
class list : public baselist
{
public:
	int			mapcar( int (func)(T *) ) { return baselist::mapcar( (mcf)func ); }
	int			remove( T * item ) { return baselist::remove( item ); }
	void			push( T * item ) { baselist::push( item ); }
	T *			pop() { return (T*) baselist::pop(); }
};

#endif
