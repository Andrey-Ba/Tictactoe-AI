#pragma once

#include <iostream>
#include <limits>
#include "minmaxutil.hpp"

// Generic minmax algorithm with purning.
// S - State of the problem.
// M - Move of the problem.

namespace myproject{
    template<typename S, typename M>
    class minmax{
        private:
        minmaxutil<S,M> *util;

        public:
        minmax(minmaxutil<S,M> &u): util(&u){}

        M AlphaBetaSearch(){
            std::tuple<M,int> v = MaxValue(util->getState(), M(), std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
            return std::get<0>(v);
        }

        private:
        std::tuple<M,int> MaxValue(const S &state, const M &move, int alpha, int beta){
            if(util->TerminalTest(state)){return std::tuple<M,int>(move,util->utility(state));}
            int v = std::numeric_limits<int>::min();
            M m;
            for(std::tuple<S,M> as: util->succerssors(state))
            {
                int temp = std::max(v, std::get<1>(MinValue(std::get<0>(as), std::get<1>(as), alpha, beta)));
                if(temp > v){v = temp;m = std::get<1>(as);}
                if(v>=beta){return std::tuple<M,int>(m, v);}
                alpha = std::max(alpha, v);
            }
            return std::tuple<M,int>(m, v);
        }

        std::tuple<M,int> MinValue(const S &state, const M &move, int alpha, int beta){
            if(util->TerminalTest(state)){return std::tuple<M,int>(move,util->utility(state));}
            int v = std::numeric_limits<int>::max();
            M m;
            for(std::tuple<S,M> as: util->succerssors(state))
            {
                int temp = std::min(v, std::get<1>(MaxValue(std::get<0>(as), std::get<1>(as), alpha, beta)));
                if(temp < v){v = temp;m = std::get<1>(as);}
                if(v<=alpha){return std::tuple<M,int>(m, v);}
                beta = std::min(beta, v);
            }
            return std::tuple<M,int>(m, v);
        }
    };
}