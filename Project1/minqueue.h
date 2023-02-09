#ifndef MIN_QUEUE_H
#define MIN_QUEUE_H

#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;



#define DEFAULT_LIST_CAPACITY 10

template <class T> 
class MinQueue
{
public:
			MinQueue		( void );
		   ~MinQueue		( void );
            MinQueue     (T*A , int n);
    void    insert     (const T &item);
    void heapify    (int id ) ; 
string		to_string	( void ) const;	
T &			operator[]	( int index );
void        build_min_heap (void)  ;
T     min             (void) ;
T     extract_min            (void) ;
void decrease_key       (int id , T k);
void set       (int id , T k);
void sort           ( T*A);
int len 		(void);
int cap (void);
void allocate (int n);
//List<T>		operator+	( const List<T> &mylist ) const;
//int			length		( void ) const;
//bool		isEmpty		( void ) const;
//void		clear		( void );


private:
	// DO NOT CHANGE THESE THREE VARIABLES
	T	*list;			// the pointer for the dynamic array
	int capacity;		// the size of the array
	int size;			// the number of items in the list
	//int capacity ;
	// YOU CAN ADD METHODS/VARIABLES HERE
};


#include "minqueue.cpp"

#endif