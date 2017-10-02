#include <catch.hpp>
#include <vector>

#include "hoare_partition.hpp"

template <typename Iterator>
bool equal( range_t<Iterator> range, std::vector<int> const & array )
{
    return std::equal( range.begin,
                      range.begin + range.size,
                      array.begin(),
                      array.end() );
}

TEST_CASE("hoare partition on empty array", "")
{
    std::vector<int> array = {};
    auto partition = hoare_partition( array.begin() , array.end(), 0 );
    
    REQUIRE( equal( partition.less, {} ) );
    REQUIRE( equal( partition.equal, {} ) );
    REQUIRE( equal( partition.great, {} ) );
}

TEST_CASE("hoare partition on sorted array in ascending order", "")
{
    {
        std::vector<int> array = {1};
        auto partition = hoare_partition( array.begin() , array.end(), 0 );
        
        REQUIRE( equal( partition.less, {} ) );
        REQUIRE( equal( partition.equal, {} ) );
        REQUIRE( equal( partition.great, {1} ) );
    }
    
    {
        std::vector<int> array = {1};
        auto partition = hoare_partition( array.begin() , array.end(), 1 );
        
        REQUIRE( equal( partition.less, {} ) );
        REQUIRE( equal( partition.equal, {1} ) );
        REQUIRE( equal( partition.great, {} ) );
    }
    
    {
        std::vector<int> array = {1};
        auto partition = hoare_partition( array.begin() , array.end(), 2 );
        
        REQUIRE( equal( partition.less, {1} ) );
        REQUIRE( equal( partition.equal, {} ) );
        REQUIRE( equal( partition.great, {} ) );
    }
    
    {
        std::vector<int> array = {1, 2};
        auto partition = hoare_partition( array.begin() , array.end(), 0 );
        
        REQUIRE( equal( partition.less, {} ) );
        REQUIRE( equal( partition.equal, {} ) );
        REQUIRE( equal( partition.great, {1, 2} ) );
    }
    
    {
        std::vector<int> array = {1, 2};
        auto partition = hoare_partition( array.begin() , array.end(), 1 );
        
        REQUIRE( equal( partition.less, {} ) );
        REQUIRE( equal( partition.equal, {1} ) );
        REQUIRE( equal( partition.great, {2} ) );
    }
    
    {
        std::vector<int> array = {1, 2};
        auto partition = hoare_partition( array.begin() , array.end(), 2 );
        
        REQUIRE( equal( partition.less, {1} ) );
        REQUIRE( equal( partition.equal, {2} ) );
        REQUIRE( equal( partition.great, {} ) );
    }
    
    {
        std::vector<int> array = {1, 2};
        auto partition = hoare_partition( array.begin() , array.end(), 3 );
        
        REQUIRE( equal( partition.less, {1, 2} ) );
        REQUIRE( equal( partition.equal, {} ) );
        REQUIRE( equal( partition.great, {} ) );
    }
    
    {
        std::vector<int> array = {1, 2, 3};
        auto partition = hoare_partition( array.begin() , array.end(), 0 );
        
        REQUIRE( equal( partition.less, {} ) );
        REQUIRE( equal( partition.equal, {} ) );
        REQUIRE( equal( partition.great, {1, 2, 3} ) );
    }
    
    {
        std::vector<int> array = {1, 2, 3};
        auto partition = hoare_partition( array.begin() , array.end(), 1 );
        
        REQUIRE( equal( partition.less, {} ) );
        REQUIRE( equal( partition.equal, {1} ) );
        REQUIRE( equal( partition.great, {2, 3} ) );
    }
    
    {
        std::vector<int> array = {1, 2, 3};
        auto partition = hoare_partition( array.begin() , array.end(), 2 );
        
        REQUIRE( equal( partition.less, {1} ) );
        REQUIRE( equal( partition.equal, {2} ) );
        REQUIRE( equal( partition.great, {3} ) );
    }
    
    {
        std::vector<int> array = {1, 2, 3};
        auto partition = hoare_partition( array.begin() , array.end(), 3 );
        
        REQUIRE( equal( partition.less, {1, 2} ) );
        REQUIRE( equal( partition.equal, {3} ) );
        REQUIRE( equal( partition.great, {} ) );
    }
    
    {
        std::vector<int> array = {1, 2, 3};
        auto partition = hoare_partition( array.begin() , array.end(), 4 );
        
        REQUIRE( equal( partition.less, {1, 2, 3} ) );
        REQUIRE( equal( partition.equal, {} ) );
        REQUIRE( equal( partition.great, {} ) );
    }
}

TEST_CASE("hoare partition on sorted array in descending order", "")
{
    {
        std::vector<int> array = {1};
        auto partition = hoare_partition( array.begin() , array.end(), 0 );
        
        REQUIRE( equal( partition.less, {} ) );
        REQUIRE( equal( partition.equal, {} ) );
        REQUIRE( equal( partition.great, {1} ) );
    }
    
    {
        std::vector<int> array = {1};
        auto partition = hoare_partition( array.begin() , array.end(), 1 );
        
        REQUIRE( equal( partition.less, {} ) );
        REQUIRE( equal( partition.equal, {1} ) );
        REQUIRE( equal( partition.great, {} ) );
    }
    
    {
        std::vector<int> array = {1};
        auto partition = hoare_partition( array.begin() , array.end(), 2 );
        
        REQUIRE( equal( partition.less, {1} ) );
        REQUIRE( equal( partition.equal, {} ) );
        REQUIRE( equal( partition.great, {} ) );
    }
    
    {
        std::vector<int> array = {2, 1};
        auto partition = hoare_partition( array.begin() , array.end(), 0 );
        
        REQUIRE( equal( partition.less, {} ) );
        REQUIRE( equal( partition.equal, {} ) );
        REQUIRE( equal( partition.great, {2, 1} ) );
    }
    
    {
        std::vector<int> array = {2, 1};
        auto partition = hoare_partition( array.begin() , array.end(), 1 );
        
        REQUIRE( equal( partition.less, {} ) );
        REQUIRE( equal( partition.equal, {1} ) );
        REQUIRE( equal( partition.great, {2} ) );
    }
    
    {
        std::vector<int> array = {2, 1};
        auto partition = hoare_partition( array.begin() , array.end(), 2 );
        
        REQUIRE( equal( partition.less, {1} ) );
        REQUIRE( equal( partition.equal, {2} ) );
        REQUIRE( equal( partition.great, {} ) );
    }
    
    {
        std::vector<int> array = {2, 1};
        auto partition = hoare_partition( array.begin() , array.end(), 3 );
        
        REQUIRE( equal( partition.less, {2, 1} ) );
        REQUIRE( equal( partition.equal, {} ) );
        REQUIRE( equal( partition.great, {} ) );
    }
    
    {
        std::vector<int> array = {3, 2, 1};
        auto partition = hoare_partition( array.begin() , array.end(), 0 );
        
        REQUIRE( equal( partition.less, {} ) );
        REQUIRE( equal( partition.equal, {} ) );
        REQUIRE( equal( partition.great, {3, 2, 1} ) );
    }
    
    {
        std::vector<int> array = {3, 2, 1};
        auto partition = hoare_partition( array.begin() , array.end(), 1 );
        
        REQUIRE( equal( partition.less, {} ) );
        REQUIRE( equal( partition.equal, {1} ) );
        REQUIRE( equal( partition.great, {2, 3} ) );
    }
    
    {
        std::vector<int> array = {3, 2, 1};
        auto partition = hoare_partition( array.begin() , array.end(), 2 );
        
        REQUIRE( equal( partition.less, {1} ) );
        REQUIRE( equal( partition.equal, {2} ) );
        REQUIRE( equal( partition.great, {3} ) );
    }
    
    {
        std::vector<int> array = {3, 2, 1};
        auto partition = hoare_partition( array.begin() , array.end(), 3 );
        
        REQUIRE( equal( partition.less, {2, 1} ) );
        REQUIRE( equal( partition.equal, {3} ) );
        REQUIRE( equal( partition.great, {} ) );
    }
    
    {
        std::vector<int> array = {3, 2, 1};
        auto partition = hoare_partition( array.begin() , array.end(), 4 );
        
        REQUIRE( equal( partition.less, {3, 2, 1} ) );
        REQUIRE( equal( partition.equal, {} ) );
        REQUIRE( equal( partition.great, {} ) );
    }
}

TEST_CASE("hoare partition on shuffled array", "")
{
    {
        std::vector<int> array = {1};
        auto partition = hoare_partition( array.begin() , array.end(), 0 );
        
        REQUIRE( equal( partition.less, {} ) );
        REQUIRE( equal( partition.equal, {} ) );
        REQUIRE( equal( partition.great, {1} ) );
    }
    
    {
        std::vector<int> array = {1};
        auto partition = hoare_partition( array.begin() , array.end(), 1 );
        
        REQUIRE( equal( partition.less, {} ) );
        REQUIRE( equal( partition.equal, {1} ) );
        REQUIRE( equal( partition.great, {} ) );
    }
    
    {
        std::vector<int> array = {1};
        auto partition = hoare_partition( array.begin() , array.end(), 2 );
        
        REQUIRE( equal( partition.less, {1} ) );
        REQUIRE( equal( partition.equal, {} ) );
        REQUIRE( equal( partition.great, {} ) );
    }
    
    {
        std::vector<int> array = {2, 1};
        auto partition = hoare_partition( array.begin() , array.end(), 0 );
        
        REQUIRE( equal( partition.less, {} ) );
        REQUIRE( equal( partition.equal, {} ) );
        REQUIRE( equal( partition.great, {2, 1} ) );
    }
    
    {
        std::vector<int> array = {2, 1};
        auto partition = hoare_partition( array.begin() , array.end(), 1 );
        
        REQUIRE( equal( partition.less, {} ) );
        REQUIRE( equal( partition.equal, {1} ) );
        REQUIRE( equal( partition.great, {2} ) );
    }
    
    {
        std::vector<int> array = {2, 1};
        auto partition = hoare_partition( array.begin() , array.end(), 2 );
        
        REQUIRE( equal( partition.less, {1} ) );
        REQUIRE( equal( partition.equal, {2} ) );
        REQUIRE( equal( partition.great, {} ) );
    }
    
    {
        std::vector<int> array = {2, 1};
        auto partition = hoare_partition( array.begin() , array.end(), 3 );
        
        REQUIRE( equal( partition.less, {2, 1} ) );
        REQUIRE( equal( partition.equal, {} ) );
        REQUIRE( equal( partition.great, {} ) );
    }
    
    {
        std::vector<int> array = {3, 2, 1};
        auto partition = hoare_partition( array.begin() , array.end(), 0 );
        
        REQUIRE( equal( partition.less, {} ) );
        REQUIRE( equal( partition.equal, {} ) );
        REQUIRE( equal( partition.great, {3, 2, 1} ) );
    }
    
    {
        std::vector<int> array = {3, 2, 1};
        auto partition = hoare_partition( array.begin() , array.end(), 1 );
        
        REQUIRE( equal( partition.less, {} ) );
        REQUIRE( equal( partition.equal, {1} ) );
        REQUIRE( equal( partition.great, {2, 3} ) );
    }
    
    {
        std::vector<int> array = {3, 2, 1};
        auto partition = hoare_partition( array.begin() , array.end(), 2 );
        
        REQUIRE( equal( partition.less, {1} ) );
        REQUIRE( equal( partition.equal, {2} ) );
        REQUIRE( equal( partition.great, {3} ) );
    }
    
    {
        std::vector<int> array = {3, 2, 1};
        auto partition = hoare_partition( array.begin() , array.end(), 3 );
        
        REQUIRE( equal( partition.less, {2, 1} ) );
        REQUIRE( equal( partition.equal, {3} ) );
        REQUIRE( equal( partition.great, {} ) );
    }
    
    {
        std::vector<int> array = {3, 2, 1};
        auto partition = hoare_partition( array.begin() , array.end(), 4 );
        
        REQUIRE( equal( partition.less, {3, 2, 1} ) );
        REQUIRE( equal( partition.equal, {} ) );
        REQUIRE( equal( partition.great, {} ) );
    }
}

