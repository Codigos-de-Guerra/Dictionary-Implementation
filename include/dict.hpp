/**
 * @file dict.hpp
 * @author Daniel Guerra (daniel.guerra13@hotmail.com)
 * @date June, 14
 * @title Dictionary Implementation
 */

#ifndef _DICT_HPP_
#define _DICT_HPP_

#include <iostream>		// cin, cout
#include <algorithm>	// copy

template< typename Key, typename Data, typename KeyComparator >
class DAL {
// DAL = Dictionary with Array List

	protected:
		struct NodeAL {		//!< Node structure, representing pair key-data.
			Key id;			//!< Key for dictionary elements.
			Data info;		//!< Info about dictionary elements.
		};

		static const int DEFAULT_SIZE = 50;
		size_t m_size;							//!< Current list size.
		size_t m_capacity;						//!< Maximun list capacity.
		NodeAL *mpt_data;						//!< Dynamic storage array.

		KeyComparator compare;					//!< Functor for compare func.

		int _search( const Key & k_ ) const	//!< Auxiliary search method.
		{
			// Since it isn't sorted, we use just a simple linear search.
			int i=0;
			while( i < (int) m_size ){
				if( mpt_data[i].id == k_ ) return i;
				i++;
			}

			return -1;
		}

	public:
		DAL ( int _MaxSz );
		DAL ( void );
		virtual ~DAL() { delete [] mpt_data; };
		
		//! @brief Removes an pair of key-data inside dictionary.
		bool remove( const Key & k_, Data & d_ );
	
		//! @brief Inserts a new pair of key-data inside dictionary.
		bool insert( const Key & new_k_, const Data & new_d_ );

		//! @brief Lowest key existing on dictionary.
		Key min( void ) const;

		//! @brief Highest key existing on dictionary.
		Key max( void ) const;

		//! @brief Saves the smallest key bigger than 'key1_'.
		//! @return True if there is a bigger element. False otherwise.
		bool sucessor( const Key & key1_, Key & key2_ ) const;

		//! @brief Saves the biggest key smaller than 'key2_'.
		//!	@return True if there is a smaller element. False otherwise.
		bool predecessor( const Key & key1_, Key & key2_ ) const;

		//! @brief Reallocates necessary memory space for dictionary.
		void resize( void );

		//! @brief Friend function for debugging. Prints Dictionary.
		inline friend std::ostream &operator<< (std::ostream& os_,
												const DAL& List_ )
		{
			os_ << "[\n";
			for( int i=0; i < (int)List_.m_size; i++ ){
				os_ << "      {id: " << List_.mpt_data[i].id << ", info: "
					<< List_.mpt_data[i].info << "}  \n";
			}
			os_ << "]\n";

			return os_;
		}
};

template< typename Key, typename Data, typename KeyComparator >
class DSAL : public DAL< Key, Data, KeyComparator >	// Heritage.
// DSAL = Dictionary with Sorted Array List.
{
	public:
		DSAL( int _MaxSz ) : DAL< Key, Data, KeyComparator >( _MaxSz )
		{ /* empty */ };
	//	DSAL( void ) : DAL< Key, Data, KeyComparator >( void )
	//	{ /* empty */ };
		virtual ~DSAL() { /* empty */ };

		// Methods to overwrite.
		bool remove( const Key & k_, Data & d_ );
		bool insert( const Key & new_k_, const Data & new_d_ );
		Key min() const;
		Key max() const;
		bool sucessor( const Key & key1_, Key & key2_ ) const;
		bool predecessor( const Key & key1_, Key & key2_ ) const;

	private:
		int _search( const Key & k_ ) const	// Auxiliary search method.
		{
			// Since it is sorted, we can use a binary search.
			int first = 0;
			int last = this->m_size - 1;
			int pos = this->m_size/2;
			while( first <= last ){
				if( true == this->compare( this->mpt_data[pos].id, k_ ) ){
					first = pos+1;
				}
				else if( true == this->compare( k_, this->mpt_data[pos].id ) ){
					last = pos-1;
				}
				else {
					return pos;
				}

				pos = first + (last-first+1)/2;
			}

			return -1;
		}
};

// Source Code
#include "dict.inl"	// All the class function implementations.

#endif
