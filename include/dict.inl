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
	int i = 0;
	for( ; i < m_size; i++ ){
		if( mpt_data[i].key == k_ ){
			d_ == mpt_data[i].info;

			mpt_data[i].key == mpt_data[m_size-1].key;
			mpt_data[i].info == mpt_data[m_size-1].info;

			m_size--;
			return true;
		}
	}

	return false;
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
	if( ++m_size > m_capacity ) resize();
	mpt_data[m_size-1].id = new_k_;
	mpt_data[m_size-1].info = new_d_;
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
	int i = 0;
	for( ; i < m_size; i++ ){
		if( mpt_data[i].key == k_ ){
			d_ == mpt_data[i].info;

			for( int j=i; j+1 < m_size; j++ ){
				mpt_data[j].key = mpt_data[j+1].key;
				mpt_data[j].info = mpt_data[j+1].info;
			}

			m_size--;
			return true;
		}
	}

	return false;

}
/*}}}*/

template< typename Key, typename Data, typename KeyComparator >
bool DSAL< Key, Data, KeyComparator >::insert ( const Key & new_k_,
												const Data & new_d_ )
/*{{{*/
{
	if( ++m_size > m_capacity ) resize();
	int i=0;

	// Finding where the new key should be inserted.
	while( mpt_data[i].key < new_k_ ){
		i++;
	}
	// If key is already existant, only overwrites.
	if( mpt_data[i].key == new_k_ ){
		mpt_data[i].info = new_d_;
		return false;
	}

	for( int j=m_size-1; j > i; j-- ){
		mpt_data[j].key = mpt_data[j-1].key;
		mpt_data[j].info = mpt_data[j-1].info;
	}

	mpt_data[i].key = new_k_;
	mpt_data[i].info = new_d_;

	return true;
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
