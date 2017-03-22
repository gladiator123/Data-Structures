#include<iostream>
#include <stdio.h>
#include <stdexcept>
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

    T& operator[](const int i) {
        if(i>=sz || i<0) throw out_of_range ("Index is out of bounds!");
        return first[i];
    }

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
    vector<string>V(4);
    V.push_back("hello");
    V.push_back("my first structure");
    cout<<V.size()<<endl;
    try{
    cout<<V[20]<<endl;
    }catch (const out_of_range& oor) {
        std::cerr << "Out of Range error: " << oor.what() <<endl;
    }
    V.print();
}
