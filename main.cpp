#include <iostream>
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "BSTN.h"


using namespace std;

TEST_CASE( "BSTN is tested", "[BSTN]" ) {
    vector<int> v = {8, 9, 5, 2, 4, 10, 1};
    BSTN B;
    for (auto e: v) B.insert(e);
    REQUIRE (B.InOrder() == "1 2 4 5 8 9 10 ");
    REQUIRE (B.BFS() == "8 5 9 2 10 1 4 ");
}
