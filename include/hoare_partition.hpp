#ifndef HOARE_PARTITION_HPP
#define HOARE_PARTITION_HPP

#include <algorithm>
#include <utility>

template <typename _BidirectionalIterator, typename T>
auto hoare_partition( _BidirectionalIterator first, _BidirectionalIterator last, T pivot ) -> std::pair<_BidirectionalIterator, _BidirectionalIterator>
{
    if( first == last ) {
        return {first, first};
    }
    
    auto i = first;
    auto k = first;
    auto j = last;
    
    while( i != j ) {
        while( i != j && !(pivot < *i) ) {
            if( *i < pivot ) {
                std::iter_swap( i , k++ );
            }
            ++i;
        }
        
        while( i != j ) {
            auto tmp = j;
            
            if( pivot < *--tmp ) {
                j = tmp;
            }
            else {
                break;
            }
        }
        
        if( i != j ) {
            std::iter_swap( i, --j );
            if( *i < pivot ) {
                std::iter_swap( i, k );
                ++k;
            }
            
            ++i;
        }
    }
    
    return {k, i};
}

#endif
