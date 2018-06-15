#include "dict.hpp"

/**
 * @file dict.inl
 * @date June, 14.
 * @author Daniel Guerra (daniel.guerra13@hotmail.com)
 * @title Dict Implementation
 */

// DAL Implementation
/*DAL Implementation{{{*/

template< typename Key, typename Data, typename KeyComparator >
DAL< Key, Data, KeyComparator >::DAL ( int _MaxSz )
/*{{{*/
{
	mpt_data = new NodeAL[_MaxSz];
	m_size = 0;
	m_capacity = _MaxSz;
}
/*}}}*/

template< typename Key, typename Data, typename KeyComparator >
DAL< Key, Data, KeyComparator >::DAL ( void )
/*{{{*/
{
	mpt_data = new NodeAL[DEFAULT_SIZE];
	m_size = 0;
	m_capacity = DEFAULT_SIZE;
}
/*}}}*/


template< typename Key, typename Data, typename KeyComparator >
bool DAL< Key, Data, KeyComparator >::remove ( const Key & k_,
											   Data & d_ )
/*{{{*/
{
	int i = _search( k_ );
	if( i == -1 ) return false;

	d_ == mpt_data[i].info;
	mpt_data[i].id = mpt_data[m_size-1].id;
	mpt_data[i].info = mpt_data[m_size-1].info;

	m_size--;
	return true;
}
/*}}}*/

template< typename Key, typename Data, typename KeyComparator >
bool DAL< Key, Data, KeyComparator >::insert ( const Key & new_k_,
											   const Data & new_d_ )
/*{{{*/
{
	int i = _search( new_k_ );
	// Overwrites information if key already exists.
	if( i >= 0 ){
		mpt_data[i].info = new_d_;
		return false;
	}

	// Allocates more space if it isn't sufficient.
	if( ++m_size > m_capacity ) resize();
	mpt_data[m_size-1].id = new_k_;
	mpt_data[m_size-1].info = new_d_;

	return true;
}
/*}}}*/

template< typename Key, typename Data, typename KeyComparator >
Key DAL< Key, Data, KeyComparator >::min ( void ) const
/*{{{*/
{
	Key min_ = mpt_data[0].id;
	for( int i=1; i < (int) m_size; i++ ){
		if( true == compare( mpt_data[i].id, min_ ) ){
			min_ = mpt_data[i].id;
		}
	}

	return min_;
}
/*}}}*/

template< typename Key, typename Data, typename KeyComparator >
Key DAL< Key, Data, KeyComparator >::max ( void ) const
/*{{{*/
{
	Key max_ = mpt_data[0].id;
	for( int i=1; i < (int) m_size; i++ ){
		if( true == compare( max_, mpt_data[i].id ) ){
			max_ = mpt_data[i].id;
		}
	}

	return max_;
}
/*}}}*/

template< typename Key, typename Data, typename KeyComparator >
bool DAL< Key, Data, KeyComparator >::sucessor ( const Key & key1_,
												 Key & key2_ ) const
/*{{{*/
{
	Key suc;
	bool is_a_bigger = false;
	for( int i=0; i < (int) m_size; i++ ){
		if( true == compare( key1_, mpt_data[i].id ) ){
			if( !is_a_bigger ){
				suc = mpt_data[i].id;
				is_a_bigger = true;
				//continue;
			}
			if( true == compare( mpt_data[i].id, suc ) ){
				suc = mpt_data[i].id;
			}
		}
	}

	if( is_a_bigger ){
		key2_ = suc;
		return true;
	}

	return false;
}
/*}}}*/

template< typename Key, typename Data, typename KeyComparator >
bool DAL< Key, Data, KeyComparator >::predecessor ( const Key & key1_,
													Key & key2_ ) const
/*{{{*/
{
	Key pred;
	bool is_a_smaller = false;
	for( int i=0; i < (int) m_size; i++ ){
		if( true == compare( mpt_data[i].id, key1_ ) ){
			if( !is_a_smaller ){
				pred = mpt_data[i].id;
				is_a_smaller = true;
				//continue;
			}
			if( true == compare( pred, mpt_data[i].id ) ){
				pred = mpt_data[i].id;
			}
		}
	}

	if( is_a_smaller ){
		key2_ = pred;
		return true;
	}

	return false;
}
/*}}}*/

template< typename Key, typename Data, typename KeyComparator >
void DAL< Key, Data, KeyComparator >::resize ( void )
/*{{{*/
{
	NodeAL *new_data = new NodeAL[m_capacity];
	std::copy( mpt_data, mpt_data + m_size, new_data );
	delete [] mpt_data;

	mpt_data = new NodeAL[(3*m_capacity)/2];
	std::copy( new_data, new_data + m_size, mpt_data );
	delete [] new_data;
	
	m_capacity = (3*m_capacity)/2;
}
/*}}}*/

/*}}}*/

// DSAL Implementation
/*DSAL Implementation{{{*/

// template< typename Key, typename Data, typename KeyComparator >
// bool DSAL< Key, Data, KeyComparator >::remove ( const Key & k_,
// 												Data & d_ )
// /*{{{*/
// {
// 	int i = _search( k_ );
// 	if( i == -1 ) return false;
// 	d_ == mpt_data[i].info;

// 	for( int j=i; j+1 < m_size; j++ ){
// 		mpt_data[j].id = mpt_data[j+1].id;
// 		mpt_data[j].info = mpt_data[j+1].info;
// 	}

// 	m_size--;
// 	return true;
// }
// /*}}}*/

// template< typename Key, typename Data, typename KeyComparator >
// bool DSAL< Key, Data, KeyComparator >::insert ( const Key & new_k_,
// 												const Data & new_d_ )
// /*{{{*/
// {
// 	int i = _search( new_k_ );

// 	// Overwrites information if key already exists. Returns False.
// 	if( i >= 0 ){
// 		mpt_data[i].info = new_d_;
// 		return false;
// 	}
// 	if( ++m_size > m_capacity ) resize();

// 	i=0;

// 	// Finding where the new key should be inserted.
// 	while( true == compare( mpt_data[i].id, new_k_ ) ){
// 		i++;
// 	}

// 	for( int j=m_size-1; j > i; j-- ){
// 		mpt_data[j].id = mpt_data[j-1].id;
// 		mpt_data[j].info = mpt_data[j-1].info;
// 	}

// 	mpt_data[i].id = new_k_;
// 	mpt_data[i].info = new_d_;

// 	return true;
// }
// /*}}}*/

// template< typename Key, typename Data, typename KeyComparator >
// Key DSAL< Key, Data, KeyComparator >::min ( void ) const
// /*{{{*/
// {
// 	return mpt_data[0].id;
// }
// /*}}}*/

// template< typename Key, typename Data, typename KeyComparator >
// Key DSAL< Key, Data, KeyComparator >::max ( void ) const
// /*{{{*/
// {
// 	return mpt_data[m_size-1].id;
// }
// /*}}}*/

// template< typename Key, typename Data, typename KeyComparator >
// bool DSAL< Key, Data, KeyComparator >::sucessor ( const Key & key1_,
// 												  Key & key2_ ) const
// /*{{{*/
// {
// 	int i = _search( key1_ );
// 	if( i+1 > m_size-1 ) return false;
// 	key2_ = mpt_data[i+1].id;

// 	return true;
// }
// /*}}}*/

// template< typename Key, typename Data, typename KeyComparator >
// bool DSAL< Key, Data, KeyComparator >::predecessor ( const Key & key1_,
// 													 Key & key2_ ) const
// /*{{{*/
// {
// 	int i = _search( key1_ );
// 	if( i-1 < 0 ) return false;
// 	key2_ = mpt_data[i-1].id;
	
// 	return true;
// }
// /*}}}*/

// /*}}}*/
