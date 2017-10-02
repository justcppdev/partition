#include <algorithm>
#include <utility>

template <typename _Iterator>
struct range_t
{
    _Iterator begin;
    typename _Iterator::difference_type size;
};

template <typename _Iterator>
struct parition_t
{
    range_t<_Iterator> less;
    range_t<_Iterator> equal;
    range_t<_Iterator> great;
};

// first                                      last
//   |                                         |
//   |                                         |
//   |                                         |
//   v                                         v
//+-----+-----+-----+-----+-----+-----+-----+
//| >p  | <=p | <=p | =p  | >p  | <p  |  =p |
//+-----+-----+-----+-----+-----+-----+-----+

// first       begin        end               last
//   |           |           |                 |
//   |           |           |                 |
//   |           |           |                 |
//   v           v           v                 v
//+-----+-----+-----+-----+-----+-----+-----+
//| <p  |  <p |  =p |  =p | >p  | >p  | >p  |
//+-----+-----+-----+-----+-----+-----+-----+


template <typename T, typename _ForwardIterator>
auto lomuto_partition( _ForwardIterator first, _ForwardIterator last, T pivot ) -> parition_t<_ForwardIterator>
{
    typename _ForwardIterator::difference_type less_count = 0;
    typename _ForwardIterator::difference_type equal_count = 0;
    typename _ForwardIterator::difference_type great_count = 0;
    
    auto begin = first;
    auto end = first;
    for( auto current = first; current != last; ++current ) {
        if( !( pivot < *current ) ) {
            std::iter_swap( current, end );
            if( *end < pivot ) {
                std::iter_swap( end, begin++ );
                ++less_count;
            }
            else {
                ++equal_count;
            }
            ++end;
        }
        else {
            ++great_count;
        }
    }
    
    return {{first, less_count}, {begin, equal_count}, {end, great_count}};
}
