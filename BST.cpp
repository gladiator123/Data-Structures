#include<bits/stdc++.h>

typedef long long ll ;
using namespace std;

template<typename T>
class BST{

    BST* right;
    BST* left;
    BST* parent;
    bool isempty;
public:
    T data;

    BST(T tmp=0):data(tmp),right(nullptr),left(nullptr),parent(nullptr),isempty(true){
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
            BST<T>* nptr=new BST<T>(tmp);
            if(tmp> ptr->data)ptr->right=nptr;
            else if(tmp< ptr->data) ptr->left=nptr;
            nptr->parent=ptr;
        }
    }
    bool findbool(T tmp){
        if(isempty)  throw logic_error( "the tree is empty" );
        BST<T>* ptr=this;
        while (ptr){
            if(ptr->data==tmp)return true;
            else if (ptr->data>=tmp)ptr=ptr->left;
            else ptr=ptr->right;
        }
        return false;
    }
    BST<T>* find(T tmp){
        if(isempty)  throw logic_error( "the tree is empty" );
        BST<T>* ptr=this;
        while (ptr){
            if(ptr->data==tmp)return ptr;
            else if (ptr->data>=tmp)ptr=ptr->left;
            else ptr=ptr->right;
        }
        return nullptr;
    }
     void display( BST<T>* dis){
        if(!dis)return;
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
    int direction(BST<T>* ptr){
        if(!ptr->parent)return 0;
        if((ptr->parent)->right==ptr)return 1;
        return -1;
    }
    BST<T>* min(){
        BST<T>* ptr=this;
        while (ptr->left){
            ptr=ptr->left;
        }
        return ptr;
    }
    void remove(T toDel){
        BST<T>* ptr=find(toDel);
        if(!ptr)return;
        int dir=direction(ptr);
        if(!ptr->left){
            if(ptr->right){
                if(dir==1)ptr->parent->right=ptr->right;
                else if(dir==-1)ptr->parent->left=ptr->right;
                ptr->right->parent=ptr->parent;
            }else{
                if(dir==1)ptr->parent->right=nullptr;
                else if(dir==-1)ptr->parent->left=nullptr;
            }
            ptr->right=nullptr;
            ptr->parent=nullptr;
            delete ptr;
        }else{
            if(!ptr->right){
                if(dir==1)ptr->parent->right=ptr->left;
                else if(dir==-1)ptr->parent->left=ptr->left;
                ptr->left->parent=ptr->parent;

                ptr->parent=nullptr;
                delete ptr;
            }else{
                BST<T>*ext=ptr->right->min();
                ptr->data=ext->data;
                int dir2=direction(ext);
            ////////////////////////////////    BST<T>*  to fill
                if(ext->right){
                    if(dir==1)ext->parent->right=nullptr;
                    else if(dir==-1) ext->parent->left=nullptr;
                }

                ext->right=nullptr;
                ext->left=nullptr;
                ext->parent=nullptr;
                delete ext;
            }
        }
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

    cout<<test.findbool(0);
    cout<<test.findbool(2);
    cout<<test.findbool(3);
    cout<<test.findbool(10)<<endl;
    test.remove(3);
    cout<<test.findbool(5)<<endl;
    cout<<"------------------------"<<endl;
    BST<int>*ptr=&test;
    test.display(ptr);
    cout<<"tree_depth= "<<test.tree_depth(ptr)<<endl;

    cout<<"------------------------"<<endl;
    pair<ll,ll> ret=test.surround(0);
    cout<<ret.first<<" "<<ret.second<<endl;
}
