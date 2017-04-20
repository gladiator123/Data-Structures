#include<bits/stdc++.h>

using namespace std;

template<typename T>
class Heap {

    vector<T> hp;
    unordered_map<T,int> rank;
    public:

    Heap(int sz): hp(sz+1) {}

    void insert(const T elem){
        if(rank.find(elem)==rank.end())return;

        int index = rank[elem] = hp.size();
        hp.push_back(elem);
        up(index);
    }
    T pop(){
        T ret=hp[1];
        swap(hp[1],hp[length()-1]);
        swap(rank[hp[1]],rank[hp[length()-1]]);
        rank.erase(hp[length()-1]);
        hp.resize(hp.size()-1);
        down(1);
        return ret;
    }
    void up(int index){
        while (index>1 && hp[index]>hp[index/2]){
            swap(hp[index],hp[index/2]);
            index/=2;
        }  
    }
    void down(int index){
        int left=index*2;
        int right=left+1;
        int n=length();
        if(left<n && hp[left]>hp[index] && hp[left]>hp[right]){
            swap(rank[hp[left]],rank[hp[index]]);
            swap(hp[left],hp[index]);
            down(left);
        }else if(right<n && hp[right]>hp[index]){
            swap(rank[hp[right]],rank[hp[index]]);
            swap(hp[right],hp[index]);
            down(right);
        }else{
            return;
        }
    }

    T& get_max(){
        if (length()>0) return hp[1];
    }

    int length(){
        return hp.size();
    }
} ;

int main(){

}
