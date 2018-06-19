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

// Array containig differents keys values to insert.
int keys[] =
{
	2015003129,
	2014065190

};

int main() {
/*--------------------------- Testing DAL ------------------------------*/
	std::cout << "\e[34;4m>>> START TESTING DAL:----\e[0m\n";
	DAL< int, std::string, MyKeyComparator > myDAL;

	std::cout << ">>> Inserindo {2015003129, \"Jack\"}\n";
	myDAL.insert( 2015003129, "Jack" );

	assert( myDAL.min() == myDAL.max() and myDAL.min() == 2015003129 );

	std::cout << ">>> Inserindo {2014065190, \"John\"}\n";
	myDAL.insert( 2014065190, "John" );

	std::cout << ">>> Inserindo {2013013529, \"Joe\"}\n";
	myDAL.insert( 2013013529, "Joe" );

	std::cout << ">>> Inserindo {2012067130, \"Jess\"}\n";
	myDAL.insert( 2012067130, "Jess" );

	std::cout << ">>> Inserindo {2011003129, \"Jason\"}\n";
	myDAL.insert( 2011003129, "Jason" );

	std::cout << ">>> Inserindo {2010065190, \"James\"}\n";
	myDAL.insert( 2010065190, "James" );

	assert( myDAL.min() == 2010065190 and myDAL.max() == 2015003129 );

	std::cout << "\n\e[35;1mMy DAL Dictionary:\n" << myDAL << "\n\e[0m";


	std::string m;
	std::cout << ">Removing Key 2012067130 with name Jess\n";
	myDAL.remove( 2012067130, m );

	assert( m == "Jess" );

	int j;
	myDAL.predecessor( 2014065190, j);

	int z;
	myDAL.sucessor( 2014065190, z);

	assert( j == 2013013529 and z == 2015003129 );


	std::cout << ">Predecessor->" << j << ", Sucessor->" << z << "\n";
	std::cout << ">Min: " << myDAL.min() << ", Max: " << myDAL.max() << "\n\n";
	std::cout << "\n\e[35;1mMy DAL after removal:\n" << myDAL << "\e[0m";


	DAL< int, std::string, MyKeyComparator > myCopiedDAL( myDAL );
	assert( myCopiedDAL == myDAL );

/*--------------------------- Testing DSAL ------------------------------*/
	std::cout << "\n\n\e[34;4m>>> START TESTING DSAL:----\e[0m\n";
	DSAL< int, std::string, MyKeyComparator > myDSAL;

	std::cout << ">>>>> Inserindo {2015003129, \"Jack\"}\n";
	myDSAL.insert( 2015003129, "Jack" );

	assert( myDSAL.min() == myDSAL.max() and myDSAL.min() == 2015003129 );

	std::cout << ">>>>> Inserindo {2014065190, \"John\"}\n";
	myDSAL.insert( 2014065190, "John" );

	std::cout << ">>>>> Inserindo {2013013529, \"Joe\"}\n";
	myDSAL.insert( 2013013529, "Joe" );

	std::cout << ">>>>> Inserindo {2012067130, \"Jess\"}\n";
	myDSAL.insert( 2012067130, "Jess" );

	std::cout << ">>>>> Inserindo {2011003129, \"Jason\"}\n";
	myDSAL.insert( 2011003129, "Jason" );

	std::cout << ">>>>> Inserindo {2010065190, \"James\"}\n";
	myDSAL.insert( 2010065190, "James" );

	assert( myDSAL.min() == 2010065190 and myDSAL.max() == 2015003129 );

	std::cout << "\n\e[35;1mMy DSAL Dictionary:\n" << myDSAL << "\n\e[0m";

	std::string eme;
	std::cout << ">Removing Key 2012067130 with name Jess\n";
	myDSAL.remove( 2012067130, eme );

	assert( eme == "Jess" );

	int a;
	myDSAL.predecessor( 2014065190, a);

	int b;
	myDSAL.sucessor( 2014065190, b);

	assert( a == 2013013529 and b == 2015003129 );

	std::cout << ">Predecessor->" << a << ", Sucessor->" << b << "\n";
	std::cout << ">Min: " << myDSAL.min() << ", Max: " << myDSAL.max() << "\n\n";
	std::cout << "\e[35;1mMy DSAL after removal:\n" << myDSAL << "\n\e[0m";


	DSAL< int, std::string, MyKeyComparator > myCopiedDSAL( myDSAL );
	assert( myCopiedDSAL == myDSAL );

	return 0;
}
