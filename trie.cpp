#include<bits/stdc++.h>

using namespace std;
class Trie{

public:
     Trie* root;
    int color;
    Trie(){
        root=nullptr;
        color=0;
    }
    ~Trie(){
    }

    void insert(string s){
        Trie* ptr=this;
        for(int i=0;i<s.size();i++){
            if(ptr->root==nullptr){
                ptr->root=new Trie[26];
            }
             cout<<s[i]<<endl;
            ptr=&(ptr->root[s[i]-'a']);
        }
        ptr->color=1;

    }
    bool search(string s){
        Trie* ptr=this;
        for(int i=0;i<s.size();i++){
            if(!ptr->root)return false;
            ptr=&(ptr->root[s[i]-'a']);
        }
        if(ptr->color)return true;
        return false;
    }
};

int main(){
    Trie test;

    test.insert("friend");
    cout<<test.search("friends");
}
