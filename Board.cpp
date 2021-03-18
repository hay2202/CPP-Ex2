#include "Board.hpp"
#include "Direction.hpp"
using ariel::Direction;

#include <iostream>
#include <stdexcept>
using namespace std;

namespace ariel {
    //counstructor
    Board::Board(){}

    void Board::post(unsigned int row, unsigned int column, Direction direction, string s){
        cout << "posted..!"<< endl;
    }

    string Board::read(unsigned int row, unsigned int column, Direction direction, unsigned int len){
        return "read";
    }

    void Board::show(){
        cout<< "print board!"<<endl;
    }


};