#pragma once

#include <iostream>
#include <array>

#include "tictactoe.hpp"
#include "minmaxutil.hpp"

class minmaxttt: public minmaxutil<tictactoe, unsigned long> {
    private:
        tictactoe state;
        xo ai;

    public:
        minmaxttt():ai(xo::x){}
        minmaxttt(const tictactoe& ttt): state(ttt){}
        void setai(xo a){ai = a;}
        xo& getai(){return ai;}

        tictactoe& getstateref(){
            return state;
        }

        tictactoe getState() override{
            return state;
        }

        std::list<std::tuple<tictactoe,unsigned long>> succerssors(const tictactoe& state) override{
            std::list<std::tuple<tictactoe,unsigned long>> succ;
            for(unsigned long i = 1; i < 10; i++)
            {
                if(state.possiblemove(i))
                {
                    succ.push_back(std::tuple<tictactoe,unsigned long>(tictactoe(state,i),i));
                }
            }
            return succ;
        }

        int utility(tictactoe state) override{
            if(state.getwinner() == ai){return 1;}
            if(state.getwinner() == xo::empty){return 0;}
            return -1;
        }

        bool TerminalTest(tictactoe state) override{
            return state.isdone();
        }
};