#include "common.h"


template<int n, typename T>
struct cons {
enum {item = n};
typedef T next;
};

struct Nil {};

typedef cons<1, cons<2, cons<3, cons<4,Nil()> > > > V;

BEGIN_MAIN

    cout<<V::item<<endl;
    cout<<V::next::item<<endl;
    cout<<V::next::next::item<<endl;
    cout<<V::next::next::next::item<<endl;

END_MAIN





