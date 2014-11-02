#include <iostream>
#include <ctime>

struct S1{
    char ch;
    int id;
    bool is;
};

struct S2{
    int id;
    char ch;
    bool is;
};

static const long kMaxCount = 100000000;
int main(){
    // first test the align ways
    std::cout << sizeof(S1) << std::endl;
    std::cout << sizeof(S2) << std::endl;


    // test the align velocity
    char* p1 = new char[kMaxCount]();
    std::cout << (long)p1 << std::endl;

    int *ip1 = (int*)p1;
    clock_t t1 = clock();
    for(long i = 0; i < kMaxCount/4; ++i){
        ip1[i] = i;
    }
    t1= (clock() - t1);

    char* p2 = new char[kMaxCount]();
    p2 = p2 + 1;
    std::cout << (long)p2 << std::endl;

    int* ip2 = (int*)p2;
    clock_t t2 = clock();
    for(long i = 0; i < kMaxCount/4; ++i){
        ip2[i] = i;
    }
    t2 = clock() - t2;

    std::cout << t2 <<"\t" << t1 << std::endl;
}
