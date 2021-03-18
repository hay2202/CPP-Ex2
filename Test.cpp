/**
 * AUTHORS: Hay Asa
 * Date: 2021-02
 */

#include "doctest.h"
#include "Direction.hpp"
using ariel::Direction;
#include "Board.hpp"
#include <string>
#include <algorithm>
using namespace std;

ariel::Board myBoard;

TEST_CASE("POST & READ") {
    myBoard.post(1,1,Direction::Horizontal,"asd");
    CHECK(myBoard.read(1,1,Direction::Horizontal,3) == "asd");
    CHECK(myBoard.read(1,3,Direction::Horizontal,2) == "d_");   
    myBoard.post(2,1,Direction::Horizontal,"abc");
    CHECK(myBoard.read(2,1,Direction::Horizontal,3) == "abc");  
    myBoard.post(2,4,Direction::Vertical,"xyz");
    CHECK(myBoard.read(2,4,Direction::Vertical,3) == "xyz"); 
    CHECK(myBoard.read(2,1,Direction::Horizontal,4) == "abcx"); 
    CHECK(myBoard.read(0,0,Direction::Horizontal,2) == "__"); 
}

TEST_CASE("CHANGE ORIGINAL POST & READ") {
    myBoard.post(1,2,Direction::Horizontal,"we");
    CHECK(myBoard.read(1,1,Direction::Horizontal,3) == "awe");   
    myBoard.post(1,1,Direction::Vertical,"pop");
    CHECK(myBoard.read(0,1,Direction::Vertical,4) == "_pop");  
    myBoard.post(4,3,Direction::Vertical,"aa");
    CHECK(myBoard.read(2,4,Direction::Vertical,3) == "xya");  
}

TEST_CASE("INVALID INPUT - POST") {
    CHECK_THROWS(myBoard.post(-1,12,Direction::Horizontal,"asd"));
    CHECK_THROWS(myBoard.post(-3,12,Direction::Horizontal,"asd"));
    CHECK_THROWS(myBoard.post(-1,-1,Direction::Horizontal,"asd"));
    CHECK_THROWS(myBoard.post(-5,0,Direction::Horizontal,"asd"));
    CHECK_THROWS(myBoard.post(-1,-1,Direction::Vertical,"asd"));
    CHECK_THROWS(myBoard.post(-5,0,Direction::Vertical,"asd"));
}

TEST_CASE("INVALID INPUT - READ") {
    CHECK_THROWS(myBoard.read(-1,12,Direction::Horizontal,2));
    CHECK_THROWS(myBoard.read(1,12,Direction::Horizontal,-2));
    CHECK_THROWS(myBoard.read(-1,0,Direction::Horizontal,2));
    CHECK_THROWS(myBoard.read(5,-1,Direction::Horizontal,2));
    CHECK_THROWS(myBoard.read(-5,0,Direction::Vertical,2));
    CHECK_THROWS(myBoard.read(5,-12,Direction::Vertical,6));

}

