#include<bits/stdc++.h>

using namespace std;

template<typename T>
class Heap {

    vector<T> hp;

    public:

    Heap(int sz): hp(sz) {}

    void insert(const T elem){
        hp.push_back(elem);
        int par_index=(hp.size()-1)/2,cur_index=hp.size();
        T& parent=hp[par_index];
        while(parent<elem){
            swap(hp[par_index],hp[cur_index]);
            cur_index=par_index;
            if(cur_index==0)break;
            par_index=(hp.size()-1)/2;
        }
    }
    T& get_max(){
        return hp[0];
    }


} ;




int main(){

}
