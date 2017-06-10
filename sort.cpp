:p#include<bits/stdc++.h>
using namespace std;

class sorting{

private:
    int sz;
    vector<int>tab;
    vector<int>first;
public:
    sorting(vector<int>entry):sz(entry.size()){
        first.resize(sz);
        tab.resize(sz);
        for(int i=0;i<sz;i++){first[i]=entry[i];tab[i]=entry[i];}
    }
    void init_res(){
        for(int i=0;i<sz;i++)tab[i]=first[i];
    }

    void selection_sort(){
        for(int i=0;i<sz-1;i++){
                int ind_min=i;
            for(int j=i+1;j<sz;j++){
                if(tab[j]<tab[ind_min])ind_min=j;
            }
            swap(tab[i],tab[ind_min]);
        }

    }

    void bubble_sort(){
        for(int i=sz-1;i>=0;i--){
            for(int j=0;j<i;j++){
                if(tab[j]>tab[j+1])swap(tab[j],tab[j+1]);
            }
        }
    }

    void merge_sort(){
    //to be completed
    }

    int partition(vector<int>&tab,int first,int last,int pivot){
        swap(tab[pivot],tab[last]);
        int j=0;
        for(int i=0;i<last;i++){
            if(tab[i]<=tab[pivot]){
                swap(tab[i],tab[j]);
                j++;
            }
        }
        return j;
    }

    int pv_find(vector<int>tab){
        return tab.size()/2;
    }

    void quick_sort(vector<int>&tab,int first,int last){
        if(first<last){
            int pivot=pv_find(tab);
            pivot=partition(tab,first,pivot-1,pivot)
            quick_sort(tab,first,pivot-1);
            quick_sort(tab,pivot+1,last);
        }

    }

    void bucket_sort(){
    //to be completed
    }
    void print_vector(){
        for(int i=0;i<sz;i++){
            cout<<tab[i]<<" ";
        }
        cout<<endl;
        init_res();
    }

    bool issorted(){
        for(int i=0;i<sz-1;i++){
            if(tab[i]>tab[i+1])return false;
        }
        return true;
    }
};

int main(){
    int myints[] = {16,2,77,29};
    vector<int> V (myints, myints + sizeof(myints) / sizeof(int) );
    sorting test(V);
    //test selection sort
    test.print_vector();
    test.selection_sort();
    test.print_vector();
    //test bubble sort
    test.print_vector();
    test.bubble_sort();
    test.print_vector();

}
