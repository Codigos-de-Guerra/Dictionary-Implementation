#include <string>
#include <cassert>

#include "../include/dict.hpp"

class MyKeyComparator {

	public:
		bool operator()( const int &lhs, const int &rhs ) const
		{
			return lhs < rhs;
		}
};

int main() {
//	DAL< int, std::string, MyKeyComparator > myList;
	DSAL< int, std::string, MyKeyComparator > myList( 50 );

	std::cout << ">>> Inserindo {2015003129, \"Jack\"}\n";
	myList.insert( 2015003129, "Jack" );

	std::cout << myList;

	std::cout << ">>> Inserindo {2014065190, \"John\"}\n";
	myList.insert( 2014065190, "John" );

	std::cout << ">>> Inserindo {2013013529, \"Joe\"}\n";
	myList.insert( 2013013529, "Joe" );

	std::cout << ">>> Inserindo {2012067130, \"Jess\"}\n";
	myList.insert( 2012067130, "Jess" );

	std::cout << ">>> Inserindo {2011003129, \"Jason\"}\n";
	myList.insert( 2011003129, "Jason" );

	std::cout << ">>> Inserindo {2010065190, \"James\"}\n";
	myList.insert( 2010065190, "James" );

	std::cout << myList;

	std::string m;
	std::cout << "Removing Key 2012067130 with name Jess\n\n";
	myList.remove( 2012067130, m );

	int j;
	myList.predecessor( 2014065190, j);

	int z;
	myList.sucessor( 2014065190, z);

	std::cout << "predecessor->" << j << ", sucessor->" << z << "\n";

	std::cout << "Min: " << myList.min() << ", Max: " << myList.max() << "\n\n";

	std::cout << myList;

	return 0;
}
