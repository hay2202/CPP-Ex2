//
// Created by Hay Asa on 22/03/2021.
//

#include "Board.hpp"
#include "Direction.hpp"
using ariel::Direction;
#include <utility>
#include <iostream>
#include <stdexcept>
using namespace std;
#include <string>

namespace ariel {
    //constructor
    Board::Board() = default;


    void Board::post(unsigned int row, unsigned int column, Direction direction, string s){
        int len = s.length();
        if (direction == Direction::Horizontal){
            for (size_t i = 0; i < len; ++i) {
                pair<unsigned int, unsigned int> location= make_pair(row, column);
                myBoard[location] = s.at(i);
                column++;
            }
        }
        else{
            for (size_t i = 0; i < len; ++i) {
                pair<unsigned int, unsigned int> location= make_pair(row, column);
                myBoard[location] = s.at(i);
                row++;
            }
        }

    }

    string Board::read(unsigned int row, unsigned int column, Direction direction, unsigned int len){
        string ans;
        if (direction == Direction::Horizontal){
            for (int i = 0; i < len; ++i) {
                pair<unsigned int, unsigned int> location= make_pair(row, column);
                if (myBoard[location] == 0){
                    ans+="_";
                }
                else{
                    ans+=myBoard[location];
                }   
                column++;
            }
        }
        else{
            for (int i = 0; i < len; ++i) {
                pair<unsigned int, unsigned int> location= make_pair(row, column);
                if (myBoard[location] == 0){
                    ans+="_";
                }    
                else{
                    ans+=myBoard[location];
                }  
                row++;
            }
        }

        return ans;
    }

    void Board::show(){
        unsigned int temp = 0;
        for(auto i :myBoard){
            cout<< i.second ;
            if (i.first.first != temp)
            {
                temp = i.first.first;
                cout << endl;
            }
        }
    }
};