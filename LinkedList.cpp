#include<bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    int nbr;
    Node*next;
    Node*previous;
};

class LinkedList{

    Node*head;
    Node*tail;

public:

    LinkedList(){
        head=nullptr;
        tail=nullptr;
    }

    void insert(int data){
        if(!head){
            head=new Node;
            head->next=nullptr;
            head->previous=nullptr;
            head->data=data;
            head->nbr=0;
            tail=head;
        }else{
            tail->next=new Node;
            tail->next->previous=tail;
            tail=tail->next;
            tail->nbr=tail->previous->nbr+1;
            tail->data=data;
        }
    }


    Node* Sort(Node*first,Node*last,Node* pivot){
        swap(last->data,pivot->data);
        Node* counterj=first;
        Node* counteri=first;
        while(counteri->nbr!=last->nbr){
            if(counteri->data<last->data){
                swap(counteri->data,counterj->data);
                counterj=counterj->next;
            }
            counteri=counteri->next;
        }
        swap(last->data,counterj->data);
        return counterj;
    }

    void Quick_sort(Node*first,Node*last){

        if(first->nbr>=last->nbr)return;
        int mid=(last->nbr+first->nbr)/2;
        Node* aux=first;
        int co = first->nbr;
        while(co<mid){
            aux=aux->next;
            co++;
        }
        aux=Sort(first,last,aux);
        if(aux->previous)Quick_sort(first,aux->previous);
        if(aux->next)Quick_sort(aux->next,last);


    }

    void sort_result(){
        Quick_sort(head,tail);
        display();
    }

    void display(){
        Node* aux=head;
        while(aux){
            cout<<aux->data<<" ";
            aux=aux->next;
        }
        cout<<endl;
    }
};

int main(){
    LinkedList test;
    test.insert(4);
    test.insert(6);
    test.insert(2);
    test.insert(3);
    test.display();
    test.sort_result();

}
