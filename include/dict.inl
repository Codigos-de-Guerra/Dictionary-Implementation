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
DAL< Key, Data, KeyComparator >::DAL ( DAL & rhs )
/*{{{*/
{
	mpt_data = new NodeAL[rhs.m_capacity];
	std::copy( rhs.mpt_data, rhs.mpt_data + rhs.m_size, mpt_data );

	m_size = rhs.m_size;
	m_capacity = rhs.m_capacity;
}
/*}}}*/

template< typename Key, typename Data, typename KeyComparator >
bool DAL< Key, Data, KeyComparator >::remove ( const Key & k_,
											   Data & d_ )
/*{{{*/
{
	int i = _search( k_ );
	if( i == -1 ) return false;

	d_ = mpt_data[i].info;

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
	if( m_size == 0 ) return Key(0);
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
	if( m_size == 0 ) return Key(0);
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

template< typename Key, typename Data, typename KeyComparator >
bool DAL< Key, Data, KeyComparator >::operator== ( const DAL & List_ )
/*{{{*/
{
	if( m_size != List_.m_size ) return false;
	if( m_capacity != List_.m_capacity ) return false;

	for( int i=0; i < m_size; i++ )
	{
		if( mpt_data[i].id != List_.mpt_data[i].id or
			mpt_data[i].info != List_.mpt_data[i].info ) return false;
	}

	return true;
}
/*}}}*/

template< typename Key, typename Data, typename KeyComparator >
size_t DAL< Key, Data, KeyComparator >::size ( void )
/*{{{*/
{
	return m_size;
}
/*}}}*/


/*}}}*/

// DSAL Implementation
/*DSAL Implementation{{{*/

template< typename Key, typename Data, typename KeyComparator >
DSAL< Key, Data, KeyComparator >::DSAL ( DSAL & rhs )
/*{{{*/
{
	this->mpt_data = new typename
					 DAL< Key,
						  Data,
						  KeyComparator >::NodeAL[rhs.m_capacity];

	std::copy( rhs.mpt_data,
			   rhs.mpt_data + rhs.m_size,
			   this->mpt_data );

	this->m_size = rhs.m_size;
	this->m_capacity = rhs.m_capacity;
}
/*}}}*/

template< typename Key, typename Data, typename KeyComparator >
bool DSAL< Key, Data, KeyComparator >::remove ( const Key & k_,
												Data & d_ )
/*{{{*/
{
	int i = _search( k_ );
	if( i == -1 ) return false;
	d_ = this->mpt_data[i].info;

	for( int j=i; j+1 < this->m_size; j++ ){
		this->mpt_data[j].id = this->mpt_data[j+1].id;
		this->mpt_data[j].info = this->mpt_data[j+1].info;
	}

	this->m_size--;
	return true;
}
/*}}}*/

template< typename Key, typename Data, typename KeyComparator >
bool DSAL< Key, Data, KeyComparator >::insert ( const Key & new_k_,
												const Data & new_d_ )
/*{{{*/
{
	int i = _search( new_k_ );

	// Overwrites information if key already exists. Returns False.
	if( i >= 0 ){
		this->mpt_data[i].info = new_d_;
		return false;
	}

	if( ++this->m_size > this->m_capacity ) this->resize();
/*	if( m_size = 0 ){
		this->mpt_data[0].id = new_k_;
		this->mpt_data[0].info = new_d_;
		this->m_size++;
		return true;
	}
*/

	i=0;

	// Finding where the new key should be inserted.
	while( i < this->m_size-1 and true == this->compare( this->mpt_data[i].id, new_k_ ) ){
		i++;
	}

	for( int j=this->m_size-1; j > i; j-- ){
		this->mpt_data[j].id = this->mpt_data[j-1].id;
		this->mpt_data[j].info = this->mpt_data[j-1].info;
	}

	this->mpt_data[i].id = new_k_;
	this->mpt_data[i].info = new_d_;

	return true;
}
/*}}}*/

template< typename Key, typename Data, typename KeyComparator >
Key DSAL< Key, Data, KeyComparator >::min ( void ) const
/*{{{*/
{
	return this->mpt_data[0].id;
}
/*}}}*/

template< typename Key, typename Data, typename KeyComparator >
Key DSAL< Key, Data, KeyComparator >::max ( void ) const
/*{{{*/
{
	return this->mpt_data[this->m_size-1].id;
}
/*}}}*/

template< typename Key, typename Data, typename KeyComparator >
bool DSAL< Key, Data, KeyComparator >::sucessor ( const Key & key1_,
												  Key & key2_ ) const
/*{{{*/
{
	int i = _search( key1_ );
	if( i+1 > this->m_size-1 ) return false;
	key2_ = this->mpt_data[i+1].id;

	return true;
}
/*}}}*/

template< typename Key, typename Data, typename KeyComparator >
bool DSAL< Key, Data, KeyComparator >::predecessor ( const Key & key1_,
													 Key & key2_ ) const
/*{{{*/
{
	int i = _search( key1_ );
	if( i-1 < 0 ) return false;
	key2_ = this->mpt_data[i-1].id;
 
	return true;
}
/*}}}*/

template< typename Key, typename Data, typename KeyComparator >
bool DSAL< Key, Data, KeyComparator >::operator== ( const DSAL & List_ )
/*{{{*/
{
	if( this->m_size != List_.m_size ) return false;
	if( this->m_capacity != List_.m_capacity ) return false;
	
	for( int i=0; i < this->m_size; i++ )
	{
		if( this->mpt_data[i].id != List_.mpt_data[i].id or
			this->mpt_data[i].info != List_.mpt_data[i].info ) return false;
	}

	return true;
}
/*}}}*/

template< typename Key, typename Data, typename KeyComparator >
size_t DSAL< Key, Data, KeyComparator >::size ( void )
/*{{{*/
{
	return this->m_size;
}
/*}}}*/

/*}}}*/
