#include <iostream>
#include <sstream>
#include <vector>

#include "hoare_partition.hpp"
#include "lomuto_partition.hpp"

template <typename _ForwardIterator>
auto quick_sort_using_hoare_partition( _ForwardIterator first, _ForwardIterator last )
{
}

template <typename _BidirectionalIterator>
void quick_sort_using_lomuto_partition( _BidirectionalIterator first, _BidirectionalIterator last )
{
    if( first != last ) {
        auto partition = lomuto_partition( first, last, *first );
        quick_sort_using_lomuto_partition( first, partition.equal.begin );
        quick_sort_using_lomuto_partition( partition.great.begin, last );
    }
}

int main()
{
    for( std::string line; std::getline( std::cin, line ); ) {
        std::stringstream stream{ line };
        std::vector<int> numbers;
        std::copy( std::istream_iterator<int>{ stream }, {}, std::back_inserter( numbers ) );

        quick_sort_using_lomuto_partition( numbers.begin(), numbers.end() );

        std::copy( numbers.cbegin(), numbers.cend(), std::ostream_iterator<int>{ std::cout, " " } );
        std::cout << std::endl;
    }

    return 0;
}
