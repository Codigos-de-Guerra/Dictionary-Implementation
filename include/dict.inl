#include "dict.inl"
#include <functional>
#include <cmath>

/**
 * @file dict.inl
 * @date June, 14.
 * @author Daniel Guerra (daniel.guerra13@hotmail.com)
 * @title Dict Implementation
 */

// DAL Implementation
/*DAL Implementation{{{*/

template< typename Key, typename Data, typename KeyComparator >
DAL< Key, Data, KeyComparator >::DAL ( int _MaxSz = DEFAULT_SIZE )
/*{{{*/
{
	mpt_Data = new NodeAL[_MaxSz];
	m_size = 0;
	m_capacity = _MaxSz;
}
/*}}}*/

template< typename Key, typename Data, typename KeyComparator >
bool DAL< Key, Data, KeyComparator >::remove ( const Key & k_,
											   Data & d_ )
/*{{{*/
{
	
}
/*}}}*/

template< typename Key, typename Data, typename KeyComparator >
bool DAL< Key, Data, KeyComparator >::search ( const Key & k_,
											   Data & d_ ) const
/*{{{*/
{

}
/*}}}*/

template< typename Key, typename Data, typename KeyComparator >
bool DAL< Key, Data, KeyComparator >::insert ( const Key & new_k_,
											   const Data & new_d_ ) const
/*{{{*/
{

}
/*}}}*/

template< typename Key, typename Data, typename KeyComparator >
typename Key DAL< Key, Data, KeyComparator >::min ( void ) const
/*{{{*/
{

}
/*}}}*/

template< typename Key, typename Data, typename KeyComparator >
typename Key DAL< Key, Data, KeyComparator >::max ( void ) const
/*{{{*/
{

}
/*}}}*/

template< typename Key, typename Data, typename KeyComparator >
bool DAL< Key, Data, KeyComparator >::sucessor ( const Key & key1_,
												 Key & key2_ ) const
/*{{{*/
{

}
/*}}}*/

template< typename Key, typename Data, typename KeyComparator >
bool DAL< Key, Data, KeyComparator >::predecessor ( const Key & key1_,
													Key & key2_ ) const
/*{{{*/
{

}
/*}}}*/

/*}}}*/

// DSAL Implementation
/*DSAL Implementation{{{*/

template< typename Key, typename Data, typename KeyComparator >
bool DSAL< Key, Data, KeyComparator >::remove ( const Key & k_,
												Data & d_ )
/*{{{*/
{

}
/*}}}*/

template< typename Key, typename Data, typename KeyComparator >
bool DSAL< Key, Data, KeyComparator >::insert ( const Key & new_k_,
												const Data & new_d_ )
/*{{{*/
{

}
/*}}}*/

template< typename Key, typename Data, typename KeyComparator >
typename Key DSAL< Key, Data, KeyComparator >::min ( void ) const
/*{{{*/
{

}
/*}}}*/

template< typename Key, typename Data, typename KeyComparator >
typename Key DSAL< Key, Data, KeyComparator >::max ( void ) const
/*{{{*/
{

}
/*}}}*/

template< typename Key, typename Data, typename KeyComparator >
bool DSAL< Key, Data, KeyComparator >::sucessor ( const Key & key1_,
												  const Key & key2_ ) const
/*{{{*/
{

}
/*}}}*/


template< typename Key, typename Data, typename KeyComparator >
bool DSAL< Key, Data, KeyComparator >::predecessor ( const Key & key1_,
													 const Key & key2_ ) const
/*{{{*/
{

}
/*}}}*/

/*}}}*/
