#include <iostream>
#include <string>
using namespace std;


template <class T> 
class Set
{
private:
	// struct for Node for linked list
	struct Node
	{
		T		item;
		Node 	*next;
	};
	
	Node	*head ;		// the pointer for the linked list
	
public:
			Set			( void );
		  	// ~Set		( void );
void		insert		( const T &item	);
void		remove		( const T &item	);
int         cardinality (void) const ;
bool		empty		( void ) const;
bool        contains    (const T &item);
bool        operator== (const Set<T> & myset);
bool        operator<= (const Set<T> & myset);
Set<T>       operator+ (const Set<T> & myset);
Set<T>       operator& (const Set<T> & myset);
Set<T>       operator- (const Set<T> & myset);
string 		to_string 	(void ) const ;


};



