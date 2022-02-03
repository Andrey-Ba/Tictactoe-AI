#pragma once

enum class xo{
    o,
    x,
    empty
};

inline std::ostream& operator<<(std::ostream& os,const xo& m)
{
    if(m == xo::x){os << 'x';}
    else if(m == xo::o){os << 'o';}
    else{os << ' ';}
    return os;
}