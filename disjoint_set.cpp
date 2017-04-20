#include<bits/stdc++.h>
using namespace std;

template <typename T>
class DisjointSets{
	vector<T> data;
	vector<int> parent;
	vector<int>rank;
public:
	DisjointSets(int zs):data(sz),parent(sz) {
		for(auto i=0;i<sz;i++)parent[i]=i;
	}
	void push(const T elem){
		data.push_back(elem);
		parent.push_back(data.size()-1);
		rank.push_back(0);
	}
	int Find(int index){
		if(parent[index]==index)return index;
		return parent[index]=find(parent[index]);
	}
	bool Union(int index1,int index2){
		int par1=Find(index1);
		int par2=Find(index2);
		if(par1==par2)return false;
		if(rank[par1]==rank[par2]){
			rank[par1]++;
			parent[par1]=par2;
		}
		else if(rank[par1]<rank[par2])parent[par1]=par2;
		else parent[par2]=par1;
	}
}



int main(){}