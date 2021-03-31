#include "Direction.hpp"
using ariel::Direction;
#include <string>
#include <map>

using namespace std;

namespace ariel{
    class Board
    {
    private:
        typedef pair<unsigned int, unsigned int> location;
        map<location,char> myBoard;

    public:
        Board();
      //  ~Board();

        void post(unsigned int row, unsigned int column, Direction direction, string s);
        string read(unsigned int row, unsigned int column, Direction direction, unsigned int len);
        void show();
    };
};

