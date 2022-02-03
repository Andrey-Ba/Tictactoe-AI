#include "tictactoe.hpp"

using namespace std;

    void tictactoe::checkifwon()
    {
        if(move == 10){return;}
        for(unsigned long i = 0; i < 3; i++)
        {
            if(board.at(i).at(0) != xo::empty && board.at(i).at(0) == board.at(i).at(1) && board.at(i).at(0) == board.at(i).at(2))
            {
                whowon = board.at(i).at(0);
            }
            if(board.at(0).at(i) != xo::empty && board.at(0).at(i) == board.at(1).at(i) && board.at(0).at(i) == board.at(2).at(i))
            {
                whowon = board.at(0).at(i);
            }
        }
        if(board.at(0).at(0) != xo::empty && board.at(0).at(0) == board.at(1).at(1) && board.at(0).at(0) == board.at(2).at(2))
        {
            whowon = board.at(0).at(0);
        }
        if(board.at(0).at(2) != xo::empty && board.at(0).at(2) == board.at(1).at(1) && board.at(0).at(2) == board.at(2).at(0))
        {
            whowon = board.at(0).at(2);
        }
    }

    void tictactoe::domove(const unsigned long i){
        if(isdone() || !possiblemove(i)){return;}
        board.at((i-1)/3).at((i-1)%3) = (xo)(move%2);
        checkifwon();
        move++;
    }

    bool tictactoe::isdone() const
    {
        return move > 9 || whowon != xo::empty;
    }

    const xo& tictactoe::getwinner() const
    {
        return whowon;
    }

    bool tictactoe::possiblemove(const unsigned long i) const
    {
        if(isdone() || i > 9){return false;}
        return board.at((i-1)/3).at((i-1)%3) == xo::empty;
    }

    tictactoe& tictactoe::operator=(const tictactoe& other){
        board = other.board;
        move = other.move;
        whowon = other.whowon;
        return *this;
    }

    std::ostream& operator<<(std::ostream& os,const tictactoe& ttt)
    {
        for(unsigned long i = 0; i < 3; i++)
        {
            for(unsigned long j = 0; j < 3; j++)
            {
                os << ttt.board.at(i).at(j);
                if(j != 2){os << '|';}
            }
            os << endl;
        }
        return os;
    }