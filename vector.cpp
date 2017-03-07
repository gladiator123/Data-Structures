#include<iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

template <typename T>
class vector{

    int sz;
    int cap;
    T*first;
public:

    vector(int n){
        first=new T[n];
        sz=0;
        cap=n;
    }
    ~vector(){
        delete[] first;
        cap=0;
        sz=0;
    }

    T& operator[](int i) { return &first[i]; }

    int size(){ return sz;}

    void resize(int newsz){

        if(newsz>cap){
            T*second=new T[newsz];
            memcpy(second,first,sz*sizeof(T));
            swap(second,first);
            delete [] second;
            cap=newsz;
        }
    }
    void push_back(const T& t){
        if(sz==cap) resize(2*cap);
        first[sz]=t;
        sz++;
    }
    void print(){
        for(int i=0;i<sz;i++){
            cout<<first[i]<<endl;
        }
    }
};

int main(){
    vector<string>*V=new vector<string>(4);
    V->push_back("hello");
    V->push_back("my first structure");
    cout<<V->size();
    V->print();
}
