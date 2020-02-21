#define CATCH_CONFIG_MAIN
#include "include/catch.hpp"
#include "cci_5.4.h"

TEST_CASE("nextNumber()", "test"){
    //REQUIRE(next(0b0001) == -1);
    REQUIRE(next(0b0001) == 0b0010);
    //REQUIRE(getPrev(0b0100) == 0b0010);
    //REQUIRE(getNext(0b0100) == 0b1000);
    //REQUIRE(getPrev(0b10011110000011) == 0b10011101110000);  // example from textbook
    //REQUIRE(getNext(0b11011001111100) == 0b11011010001111);  // example from textbook
}

