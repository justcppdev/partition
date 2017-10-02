#include <catch.hpp>
#include <vector>

#include "hoare_partition.hpp"

template <typename Iterator>
bool equal( Iterator first, Iterator last, std::vector<int> const & array )
{
    return std::equal( first, last, array.begin(), array.end() );
}

TEST_CASE("hoare partition on sorted array in ascending order", "")
{
    {
        std::vector<int> array = {1};
        auto res = hoare_partition( array.begin() , array.end(), 0 );
        
        REQUIRE( equal( array.begin(), res.first, {} ) );
        REQUIRE( equal( res.first, res.second, {} ) );
        REQUIRE( equal( res.second, array.end(), {1} ) );
    }
    
    {
        std::vector<int> array = {1};
        auto res = hoare_partition( array.begin() , array.end(), 1 );
        
        REQUIRE( equal( array.begin(), res.first, {} ) );
        REQUIRE( equal( res.first, res.second, {1} ) );
        REQUIRE( equal( res.second, array.end(), {} ) );
    }
    
    {
        std::vector<int> array = {1};
        auto res = hoare_partition( array.begin() , array.end(), 2 );
        
        REQUIRE( equal( array.begin(), res.first, {1} ) );
        REQUIRE( equal( res.first, res.second, {} ) );
        REQUIRE( equal( res.second, array.end(), {} ) );
    }
    
    {
        std::vector<int> array = {1, 2};
        auto res = hoare_partition( array.begin() , array.end(), 0 );
        
        REQUIRE( equal( array.begin(), res.first, {} ) );
        REQUIRE( equal( res.first, res.second, {} ) );
        REQUIRE( equal( res.second, array.end(), {1, 2} ) );
    }
    
    {
        std::vector<int> array = {1, 2};
        auto res = hoare_partition( array.begin() , array.end(), 1 );
        
        REQUIRE( equal( array.begin(), res.first, {} ) );
        REQUIRE( equal( res.first, res.second, {1} ) );
        REQUIRE( equal( res.second, array.end(), {2} ) );
    }
    
    {
        std::vector<int> array = {1, 2};
        auto res = hoare_partition( array.begin() , array.end(), 2 );
        
        REQUIRE( equal( array.begin(), res.first, {1} ) );
        REQUIRE( equal( res.first, res.second, {2} ) );
        REQUIRE( equal( res.second, array.end(), {} ) );
    }
    
    {
        std::vector<int> array = {1, 2};
        auto res = hoare_partition( array.begin() , array.end(), 3 );
        
        REQUIRE( equal( array.begin(), res.first, {1, 2} ) );
        REQUIRE( equal( res.first, res.second, {} ) );
        REQUIRE( equal( res.second, array.end(), {} ) );
    }
    
    {
        std::vector<int> array = {1, 2, 3};
        auto res = hoare_partition( array.begin() , array.end(), 0 );
        
        REQUIRE( equal( array.begin(), res.first, {} ) );
        REQUIRE( equal( res.first, res.second, {} ) );
        REQUIRE( equal( res.second, array.end(), {1, 2, 3} ) );
    }
    
    {
        std::vector<int> array = {1, 2, 3};
        auto res = hoare_partition( array.begin() , array.end(), 1 );
        
        REQUIRE( equal( array.begin(), res.first, {} ) );
        REQUIRE( equal( res.first, res.second, {1} ) );
        REQUIRE( equal( res.second, array.end(), {2, 3} ) );
    }
    
    {
        std::vector<int> array = {1, 2, 3};
        auto res = hoare_partition( array.begin() , array.end(), 2 );
        
        REQUIRE( equal( array.begin(), res.first, {1} ) );
        REQUIRE( equal( res.first, res.second, {2} ) );
        REQUIRE( equal( res.second, array.end(), {3} ) );
    }
    
    {
        std::vector<int> array = {1, 2, 3};
        auto res = hoare_partition( array.begin() , array.end(), 3 );
        
        REQUIRE( equal( array.begin(), res.first, {1, 2} ) );
        REQUIRE( equal( res.first, res.second, {3} ) );
        REQUIRE( equal( res.second, array.end(), {} ) );
    }
    
    {
        std::vector<int> array = {1, 2, 3};
        auto res = hoare_partition( array.begin() , array.end(), 4 );
        
        REQUIRE( equal( array.begin(), res.first, {1, 2, 3} ) );
        REQUIRE( equal( res.first, res.second, {} ) );
        REQUIRE( equal( res.second, array.end(), {} ) );
    }
}

TEST_CASE("hoare partition on sorted array in descending order", "")
{
    {
        std::vector<int> array = {1};
        auto res = hoare_partition( array.begin() , array.end(), 0 );
        
        REQUIRE( equal( array.begin(), res.first, {} ) );
        REQUIRE( equal( res.first, res.second, {} ) );
        REQUIRE( equal( res.second, array.end(), {1} ) );
    }
    
    {
        std::vector<int> array = {1};
        auto res = hoare_partition( array.begin() , array.end(), 1 );
        
        REQUIRE( equal( array.begin(), res.first, {} ) );
        REQUIRE( equal( res.first, res.second, {1} ) );
        REQUIRE( equal( res.second, array.end(), {} ) );
    }
    
    {
        std::vector<int> array = {1};
        auto res = hoare_partition( array.begin() , array.end(), 2 );
        
        REQUIRE( equal( array.begin(), res.first, {1} ) );
        REQUIRE( equal( res.first, res.second, {} ) );
        REQUIRE( equal( res.second, array.end(), {} ) );
    }
    
    {
        std::vector<int> array = {2, 1};
        auto res = hoare_partition( array.begin() , array.end(), 0 );
        
        REQUIRE( equal( array.begin(), res.first, {} ) );
        REQUIRE( equal( res.first, res.second, {} ) );
        REQUIRE( equal( res.second, array.end(), {2, 1} ) );
    }
    
    {
        std::vector<int> array = {2, 1};
        auto res = hoare_partition( array.begin() , array.end(), 1 );
        
        REQUIRE( equal( array.begin(), res.first, {} ) );
        REQUIRE( equal( res.first, res.second, {1} ) );
        REQUIRE( equal( res.second, array.end(), {2} ) );
    }
    
    {
        std::vector<int> array = {2, 1};
        auto res = hoare_partition( array.begin() , array.end(), 2 );
        
        REQUIRE( equal( array.begin(), res.first, {1} ) );
        REQUIRE( equal( res.first, res.second, {2} ) );
        REQUIRE( equal( res.second, array.end(), {} ) );
    }
    
    {
        std::vector<int> array = {2, 1};
        auto res = hoare_partition( array.begin() , array.end(), 3 );
        
        REQUIRE( equal( array.begin(), res.first, {2, 1} ) );
        REQUIRE( equal( res.first, res.second, {} ) );
        REQUIRE( equal( res.second, array.end(), {} ) );
    }
    
    {
        std::vector<int> array = {3, 2, 1};
        auto res = hoare_partition( array.begin() , array.end(), 0 );
        
        REQUIRE( equal( array.begin(), res.first, {} ) );
        REQUIRE( equal( res.first, res.second, {} ) );
        REQUIRE( equal( res.second, array.end(), {3, 2, 1} ) );
    }
    
    {
        std::vector<int> array = {3, 2, 1};
        auto res = hoare_partition( array.begin() , array.end(), 1 );
        
        REQUIRE( equal( array.begin(), res.first, {} ) );
        REQUIRE( equal( res.first, res.second, {1} ) );
        REQUIRE( equal( res.second, array.end(), {2, 3} ) );
    }
    
    {
        std::vector<int> array = {3, 2, 1};
        auto res = hoare_partition( array.begin() , array.end(), 2 );
        
        REQUIRE( equal( array.begin(), res.first, {1} ) );
        REQUIRE( equal( res.first, res.second, {2} ) );
        REQUIRE( equal( res.second, array.end(), {3} ) );
    }
    
    {
        std::vector<int> array = {3, 2, 1};
        auto res = hoare_partition( array.begin() , array.end(), 3 );
        
        REQUIRE( equal( array.begin(), res.first, {2, 1} ) );
        REQUIRE( equal( res.first, res.second, {3} ) );
        REQUIRE( equal( res.second, array.end(), {} ) );
    }
    
    {
        std::vector<int> array = {3, 2, 1};
        auto res = hoare_partition( array.begin() , array.end(), 4 );
        
        REQUIRE( equal( array.begin(), res.first, {3, 2, 1} ) );
        REQUIRE( equal( res.first, res.second, {} ) );
        REQUIRE( equal( res.second, array.end(), {} ) );
    }
}

TEST_CASE("hoare partition on shuffled array", "")
{
    {
        std::vector<int> array = {1};
        auto res = hoare_partition( array.begin() , array.end(), 0 );
        
        REQUIRE( equal( array.begin(), res.first, {} ) );
        REQUIRE( equal( res.first, res.second, {} ) );
        REQUIRE( equal( res.second, array.end(), {1} ) );
    }
    
    {
        std::vector<int> array = {1};
        auto res = hoare_partition( array.begin() , array.end(), 1 );
        
        REQUIRE( equal( array.begin(), res.first, {} ) );
        REQUIRE( equal( res.first, res.second, {1} ) );
        REQUIRE( equal( res.second, array.end(), {} ) );
    }
    
    {
        std::vector<int> array = {1};
        auto res = hoare_partition( array.begin() , array.end(), 2 );
        
        REQUIRE( equal( array.begin(), res.first, {1} ) );
        REQUIRE( equal( res.first, res.second, {} ) );
        REQUIRE( equal( res.second, array.end(), {} ) );
    }
    
    {
        std::vector<int> array = {2, 1};
        auto res = hoare_partition( array.begin() , array.end(), 0 );
        
        REQUIRE( equal( array.begin(), res.first, {} ) );
        REQUIRE( equal( res.first, res.second, {} ) );
        REQUIRE( equal( res.second, array.end(), {2, 1} ) );
    }
    
    {
        std::vector<int> array = {2, 1};
        auto res = hoare_partition( array.begin() , array.end(), 1 );
        
        REQUIRE( equal( array.begin(), res.first, {} ) );
        REQUIRE( equal( res.first, res.second, {1} ) );
        REQUIRE( equal( res.second, array.end(), {2} ) );
    }
    
    {
        std::vector<int> array = {2, 1};
        auto res = hoare_partition( array.begin() , array.end(), 2 );
        
        REQUIRE( equal( array.begin(), res.first, {1} ) );
        REQUIRE( equal( res.first, res.second, {2} ) );
        REQUIRE( equal( res.second, array.end(), {} ) );
    }
    
    {
        std::vector<int> array = {2, 1};
        auto res = hoare_partition( array.begin() , array.end(), 3 );
        
        REQUIRE( equal( array.begin(), res.first, {2, 1} ) );
        REQUIRE( equal( res.first, res.second, {} ) );
        REQUIRE( equal( res.second, array.end(), {} ) );
    }
    
    {
        std::vector<int> array = {3, 2, 1};
        auto res = hoare_partition( array.begin() , array.end(), 0 );
        
        REQUIRE( equal( array.begin(), res.first, {} ) );
        REQUIRE( equal( res.first, res.second, {} ) );
        REQUIRE( equal( res.second, array.end(), {3, 2, 1} ) );
    }
    
    {
        std::vector<int> array = {3, 2, 1};
        auto res = hoare_partition( array.begin() , array.end(), 1 );
        
        REQUIRE( equal( array.begin(), res.first, {} ) );
        REQUIRE( equal( res.first, res.second, {1} ) );
        REQUIRE( equal( res.second, array.end(), {2, 3} ) );
    }
    
    {
        std::vector<int> array = {3, 2, 1};
        auto res = hoare_partition( array.begin() , array.end(), 2 );
        
        REQUIRE( equal( array.begin(), res.first, {1} ) );
        REQUIRE( equal( res.first, res.second, {2} ) );
        REQUIRE( equal( res.second, array.end(), {3} ) );
    }
    
    {
        std::vector<int> array = {3, 2, 1};
        auto res = hoare_partition( array.begin() , array.end(), 3 );
        
        REQUIRE( equal( array.begin(), res.first, {2, 1} ) );
        REQUIRE( equal( res.first, res.second, {3} ) );
        REQUIRE( equal( res.second, array.end(), {} ) );
    }
    
    {
        std::vector<int> array = {3, 2, 1};
        auto res = hoare_partition( array.begin() , array.end(), 4 );
        
        REQUIRE( equal( array.begin(), res.first, {3, 2, 1} ) );
        REQUIRE( equal( res.first, res.second, {} ) );
        REQUIRE( equal( res.second, array.end(), {} ) );
    }
}

