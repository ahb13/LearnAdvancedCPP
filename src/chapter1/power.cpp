#include<iostream>
using namespace std;

template<int N>
inline int power(const int x) {
    return power<N-1>(x) * x;
}

template<>
inline int power<1>(const int x) {
    return x;
}

template<>
inline int power<0>(const int x) {
    return 1;
}

int main(int argc, char* argv[]) {
    cout<<power<15>(3)<<endl;
    return 0;
}





