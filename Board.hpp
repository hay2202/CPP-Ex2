#include "Direction.hpp"
using ariel::Direction;
#include <string>
#include <vector> 
using namespace std;

namespace ariel{
    class Board
    {
    private:
        vector<unsigned int> board;

    public:
        Board(/* args */);
      //  ~Board();

        void post(unsigned int row, unsigned int column, Direction direction, string s);
        string read(unsigned int row, unsigned int column, Direction direction, unsigned int len);
        void show();
    };
};

