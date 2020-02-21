#include "include/catch.hpp"

int next1(int x);
int previous(int x);
TEST_CASE("nextNumber()", "test"){
    //REQUIRE(next(0b0001) == -1);
    //REQUIRE(next1(0b0001) == 0b0010);
    //REQUIRE(next(0b0100) == 0b0010);
    //REQUIRE(next1(0b0100) == 0b1000);
    REQUIRE(previous(0b10011110000011) == 0b10011101110000);  // example from textbook
    REQUIRE(next1(0b11011001111100) == 0b11011010001111);  // example from textbook
}

