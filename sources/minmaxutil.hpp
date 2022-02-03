#pragma once

#include <iostream>
#include <list>
#include <tuple>

// Abstract class which, given a class that implements its methods, can be used in my minmax algorithm.
// S - State of the problem.
// M - Move of the problem.

template<typename S, typename M>
class minmaxutil
{
    public:
    // Return current state.
    virtual S getState()=0;
    
    // Return all possible moves of a given state.
    virtual std::list<std::tuple<S,M>> succerssors(const S& state)=0;

    // Return a utility of a terminal state.
    virtual int utility(S state)=0;

    // Return if a given state is terminal state.
    virtual bool TerminalTest(S state)=0;

};