#include <iostream>
#include "minmax.hpp"
#include "minmaxttt.hpp"

using namespace std;

minmaxttt ttt;
myproject::minmax<tictactoe, unsigned long> minmaxalgo(ttt);

void playerplay(){
    cout << "Player: ";
    unsigned long playermove;
    cin >> playermove;
    while (playermove == 0 || playermove > 9 || !ttt.getstateref().possiblemove(playermove)){
        cout << "Bad move"<< endl;
        cin >> playermove;
    }
    ttt.getstateref().domove(playermove);
}

void aiplay(){
    unsigned long aimove = minmaxalgo.AlphaBetaSearch();
    cout << "AI: " << aimove << endl;
    ttt.getstateref().domove(aimove);
}

void printboard(){
    cout << ttt.getstateref() << endl;
}

// Impossible ai 
int main()
{
    cout << "contorls:\n1|2|3\n4|5|6\n7|8|9\n" << endl;
    cout << "Play as x or o?" << endl;
    char p;
    while (p!='x' && p!='o'){cin >> p;}
    if(p == 'x'){ttt.setai(xo::o);}
    printboard();
    while (!ttt.getstateref().isdone())
    {
        if(ttt.getai() == xo::x){aiplay();}
        else{playerplay();}
        printboard();
        if(ttt.getstateref().isdone()){break;}
        if(ttt.getai() == xo::o){aiplay();}
        else{playerplay();}
        printboard();
    }
    if(ttt.getstateref().getwinner() == xo::empty){cout << "Draw"<<endl;}
    else{cout << ttt.getstateref().getwinner() << " Won" << endl;}
}