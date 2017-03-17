#include<bits/stdc++.h>

using namespace std;
class Trie{

private:
     Trie* root;
     int color;
public:

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
            ptr=&(ptr->root[s[i]-'a']);
        }
        ptr->color=1;

    }
    bool search(string s)const {
        const Trie* ptr=this;
        for(int i=0;i<s.size();i++){
            if(!ptr->root)return false;
            ptr=&(ptr->root[s[i]-'a']);
        }
        if(ptr->color)return true;
        return false;
    }
    bool search_prefix(string s)const{
        const Trie* ptr=this;
        for(int i=0;i<s.size();i++){
            if(!ptr->root)return false;
            ptr=&(ptr->root[s[i]-'a']);
        }
        return true;
    }
};

int main(){
    Trie test;

    test.insert("friend");
    cout<<test.search("friend")<<endl;
    cout<<test.search("friends")<<endl;
    cout<<test.search_prefix("fre");
}
