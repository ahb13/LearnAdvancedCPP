
template<bool C, typename T, typename E>
struct IF {
    typedef T RET;
};

template<typename T, typename E>
struct IF<false, T, E> {
    typedef E RET;
};





