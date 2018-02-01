#include <iostream>
using namespace std;


template<int N>
class Fact {
    public:
        enum{value = N * Fact<N-1>::value};
};

template<>
class Fact<0> {
    public:
        enum{value=1};
};


int main(int argc, char* argv[]) {
    cout<<Fact<10>::value<<endl;
}
