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

		static const int DEFAULT_SIZE = 10;
		size_t m_size;							//!< Current list size.
		size_t m_capacity;						//!< Maximun list capacity.
		NodeAL *mpt_data;						//!< Dynamic storage array.

		KeyComparator compare;					//!< Functor for compare func.

		int _search( const Key & k_ ) const	//!< Auxiliary search method.
		{
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
	
		//! @brief Inserts......
		bool insert( const Key & new_k_, const Data & new_d_ );

		//! @brief Minimun.......
		Key min( void ) const;

		//! @brief Maximun.......
		Key max( void ) const;

		//! @brief 
		bool sucessor( const Key & key_1_, Key & key_2_ ) const;

		//! @brief
		bool predecessor( const Key & key_1_, Key & key_2_ ) const;

		//! @brief Reallocates necessary memory space for dict.
		void resize( void );

		inline friend std::ostream &operator<< (std::ostream& os_,
												const DAL& List_ )
		{
			os_ << "[ ";
			for( int i=0; i < (int)List_.m_size; i++ ){
				os_ << "{id: " << List_.mpt_data[i].id << ", info: "
					<< List_.mpt_data[i].info << "}  ";
			}
			os_ << "]";

			return os_;
		}
};

// template< typename Key, typename Data, typename KeyComparator >
// class DSAL : public DAL< Key, Data, KeyComparator >	// Heritage.
// // DSAL = Dictionary with Sorted Array List.
// {
// 	public:
// 		DSAL( int _MaxSz ) : DAL< Key, Data, KeyComparator >( _MaxSz )
// 		{ /* empty */ };
// 		DSAL( void ) : DAL< Key, Data, KeyComparator >( void )
// 		{ /* empty */ };
// 		virtual ~DSAL() { /* empty */ };

// 		// Methods to overwrite.
// 		bool remove( const Key & k_, Data & d_ );
// 		bool insert( const Key & new_k_, const Data & new_d_ );
// 		Key min() const;
// 		Key max() const;
// 		bool sucessor( const Key & key_1_, Key & key_2_ ) const;
// 		bool predecessor( const Key & key_1_, Key & key_2_ ) const;

// 	private:
// 		int _search( const Key & k_ ) const	// Auxiliary search method.
// 		{
// 			int first = 0;
// 			int last = m_size - 1;
// 			int pos = m_size/2;
// 			while( first <= last ){
// 				if( true == KeyComparator( mpt_data[pos].id, k_ ) ){
// 					first = pos+1;
// 				}
// 				else if( true == KeyComparator( k_, mpt_data[pos].id ){
// 					last = pos-1;
// 				}
// 				else {
// 					return pos;
// 				}

// 				pos = first + (last-first+1)/2;
// 			}

// 			return -1;
// 		}
// };

// Source Code
#include "dict.inl"	// All the class function implementations.

#endif
