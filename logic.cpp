#include <iostream>
using namespace std;
/*
we are using namespace std
first letter of classes capital
*/
class Pieces 
{
    public:
    void virtual get()=0; // just for purely virtual functionality , dummy function

    private:

    protected:


};

class Pawn: public Pieces // 99% inheritence public
{

};

class Bishop: public Pieces // 99% inheritence public
{

};
class Knight: public Pieces // 99% inheritence public
{

};
class Rook: public Pieces // 99% inheritence public
{

};
class King: public Pieces // 99% inheritence public
{

};
class Queen: public Pieces // 99% inheritence public
{

};

class Interaction
{
    
};

class Movement // 99% inheritence public
{

};

class Board
{

};
