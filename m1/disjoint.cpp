#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
private:
	vector<int> rank;
	vector<int> parent;

	int findParent(int a){
		if(a == parent[a]){
			return a;
		}
		else return parent[a] = findParent(parent[a]);
	}

public:
	DisjointSet(int n){
		this->rank.resize(n+1,0);
		this->parent.resize(n+1);
		for(int i=0;i<n+1;i++){
			this->parent[i] = i;
		}
	};
	~DisjointSet(){};

	void insertEdge(int u, int v){
		int uP = findParent(u);
		int vP = findParent(v);
		if(uP==vP) return;
		if(rank[uP] < rank[vP]){
			parent[u] = vP;
		}
		if(rank[uP] > rank[vP]){
			parent[v] = uP;
		}
		else{
			parent[uP] = vP;
			rank[vP]++;
		}
	};

	bool isSameComponent(int u, int v){
		int uP = findParent(u);
		int vP = findParent(v);
		if(uP == vP) return true;
		return false;
	};
};

int main(){
	DisjointSet *g1 = new DisjointSet(6);
	g1->insertEdge(0,1);
	g1->insertEdge(0,2);
	cout<<"1,2: "<<g1->isSameComponent(1,2)<<endl;
	g1->insertEdge(4,5);
	cout<<"4,0: "<<g1->isSameComponent(4,0)<<endl;
	g1->insertEdge(2,5);
	cout<<"5,0: "<<g1->isSameComponent(5,0)<<endl;

	return 0;
}