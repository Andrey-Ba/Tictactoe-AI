#pragma once

#include <iostream>
#include <array>

#include "xo.hpp"

class tictactoe{
    private:
        std::array<std::array<xo,3>,3> board;
        unsigned int move;
        xo whowon;
    
    public:
        tictactoe():move(1),whowon(xo::empty)
        {
            for(unsigned long i = 0; i < 3; i++)
            {
                for(unsigned long j = 0; j < 3; j++)
                {
                    board.at(i).at(j) = xo::empty;
                }
            }
        }
        tictactoe(const tictactoe& other):board(other.board),move(other.move),whowon(other.whowon){}
        tictactoe(const tictactoe& other, unsigned long i):board(other.board),move(other.move),whowon(other.whowon){
            domove(i);
        }

        void domove(const unsigned long i);
        void checkifwon();
        bool isdone() const;
        const xo& getwinner() const;
        const unsigned int& getmovenum() const {return move;}
        bool possiblemove(const unsigned long i) const;

        tictactoe& operator=(const tictactoe& other);
        friend std::ostream& operator<<(std::ostream& os, const tictactoe& ttt);
};