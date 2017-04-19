#include<bits/stdc++.h>

typedef long long ll ;
using namespace std;

template<typename T>
class BST{

    BST* right;
    BST* left;
    bool isempty;
public:
    T data;
    BST(){
        right=nullptr;
        left=nullptr;
        isempty=true;
    }
    BST(T tmp){
        data=tmp;
        right=nullptr;
        left=nullptr;
        isempty=true;
    }
    ~BST(){

    }
    void insert(T tmp){
        if(isempty){
            data=tmp;
            isempty=false;
        }else{
            BST<T>*ptr=this;
            BST<T>*par=nullptr;
            while(ptr){
                    par=ptr;
                if(tmp> ptr->data)ptr=ptr->right;
                else ptr=ptr->left;
            }
            ptr=par;
            if(tmp> ptr->data)ptr->right=new BST<T>(tmp);
            else if(tmp< ptr->data) ptr->left=new BST<T>(tmp);
        }
    }
    bool find(T tmp){
        if(isempty)  throw logic_error( "the tree is empty" );
        BST<T>* ptr=this;
        while (ptr){
            if(ptr->data==tmp)return true;
            else if (ptr->data>=tmp)ptr=ptr->left;
            else ptr=ptr->right;
        }
        return false;
    }
     void display( BST<T>* dis){
        if(!dis)return;
    //  cout<<"displaying the tree"<<endl;
        //cout<< *this <<end;
        display(dis->right);
        display(dis->left);
    }

    int tree_depth(BST<T>* dis){
        if(!dis)return 0;
        return max(tree_depth(dis->right)+1,tree_depth(dis->left)+1);
    }

    pair<ll,ll> surround(T tmp){
        BST* ptr=this;
        pair<ll,ll>ret={-(1<<27),1<<27};
        while(ptr){
            if(tmp<ptr->data){ret.second=ptr->data;ptr=ptr->left;}
            else {ret.first=ptr->data;ptr=ptr->right;}
        }
        return ret;
    }
};

template<typename T>
class RedBlack: public BST<T> {

};


int main(){
    BST<int> test;
    test.insert(2);
    test.insert(3);

    test.insert(-1);
    test.insert(5);

    cout<<test.find(0);
    cout<<test.find(2);
    cout<<test.find(3);
    cout<<test.find(10)<<endl;

    cout<<"------------------------"<<endl;
    BST<int>*ptr=&test;
    test.display(ptr);
    cout<<"tree_depth= "<<test.tree_depth(ptr)<<endl;

    cout<<"------------------------"<<endl;
    pair<ll,ll> ret=test.surround(0);
    cout<<ret.first<<" "<<ret.second<<endl;
}
