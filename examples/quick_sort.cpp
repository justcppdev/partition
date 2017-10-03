#include <iostream>
#include <sstream>
#include <vector>

#include "hoare_partition.hpp"
#include "lomuto_partition.hpp"

template <typename _ForwardIterator>
void quick_sort_using_hoare_partition( _ForwardIterator first, _ForwardIterator last )
{
    if( first != last ) {
        auto partition = hoare_partition( first, last, *first );
        quick_sort_using_hoare_partition( first, partition.equal.begin );
        quick_sort_using_hoare_partition( partition.great.begin, last );
    }
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


template<typename TimeT = std::chrono::microseconds>
struct measure {
    template <typename Procedure, typename ...Args>
    static auto execution( Procedure && procedure, Args && ...args ) -> typename TimeT::rep
    {
        auto start = std::chrono::steady_clock::now();
        std::forward<decltype(procedure)>( procedure )( std::forward<Args>( args )... );
        auto stop = std::chrono::steady_clock::now();
        auto duration = std::chrono::duration_cast<TimeT>( stop - start );

        return duration.count();
    }
};

int main()
{
    for( std::string line; std::getline( std::cin, line ); ) {
        std::stringstream stream{ line };
        std::vector<int> numbers;
        std::copy( std::istream_iterator<int>{ stream }, {}, std::back_inserter( numbers ) );
        auto numbers_for_hoare = numbers;
        auto numbers_for_lomuto = numbers;

        auto duration_for_hoare = measure<>::execution( quick_sort_using_hoare_partition<decltype(numbers_for_hoare.begin())>, numbers_for_hoare.begin(), numbers_for_hoare.end() );
        std::cout << "hoare:\n";
        std::copy( numbers_for_hoare.cbegin(), numbers_for_hoare.cend(), std::ostream_iterator<int>{ std::cout, " " } );
        std::cout << std::endl << duration_for_hoare << std::endl;

        std::cout << "lomuto:\n";
        auto duration_for_lomuto = measure<>::execution( quick_sort_using_lomuto_partition<decltype(numbers_for_lomuto.begin())>, numbers_for_lomuto.begin(), numbers_for_lomuto.end() );
        std::copy( numbers_for_lomuto.cbegin(), numbers_for_lomuto.cend(), std::ostream_iterator<int>{ std::cout, " " } );
        std::cout << std::endl << duration_for_lomuto << std::endl;

    }

    return 0;
}
