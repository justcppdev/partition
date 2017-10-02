#include <algorithm>
#include <utility>

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
auto lomuto_partition( _ForwardIterator first, _ForwardIterator last, T pivot ) -> std::pair<_ForwardIterator, _ForwardIterator>
{
    
    auto begin = first;
    auto end = first;
    for( auto current = first; current != last; ++current ) {
        if( !( pivot < *current ) ) {
            std::iter_swap( current, end );
            if( *end < pivot ) {
                std::iter_swap( end, begin++ );
            }
            ++end;
        }
    }
    
    return {begin, end};
}
