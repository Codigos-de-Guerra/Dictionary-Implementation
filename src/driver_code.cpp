#include <string>

#include "../include/dict.hpp"

class MyKeyComparator {

	public:
		bool operator()( const int &lhs, const int &rhs ) const
		{
			return lhs < rhs;
		}
};

int main() {
//	DAL< int, std::string, MyKeyComparator > myList( 50 );
	DSAL< int, std::string, MyKeyComparator > myList( 50 );

	std::cout << ">>> Inserindo {2015003129, \"Jack\"}\n";
	myList.insert( 2015003129, "Jack" );

	std::cout << ">>> Inserindo {2014065190, \"John\"}\n";
	myList.insert( 2014065190, "John" );

	std::cout << myList;
	return 0;
}
