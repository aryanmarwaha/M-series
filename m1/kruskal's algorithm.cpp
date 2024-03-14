#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Edge{
public:
	int v1,v2,weight;
	Edge(int v1, int v2, int weight=0){
		this->v1 = v1;
		this->v2 = v2;
		this->weight = weight;
	};
	~Edge(){};
	void print(){
		cout<<this->v1<<" -"<<this->weight<<"-> "<<this->v2<<endl;
	}
};

bool cmp(Edge* a, Edge* b){
	return a->weight < b->weight;
}
vector<Edge*> kruskalsAlgorithm(vector<Edge*> &edges){
	sort(edges.begin(), edges.end(), cmp);
	unordered_map<int,int> parent;
	for(auto i: edges){
		parent[i->v1] = i->v1;
		parent[i->v2] = i->v2;
	}
	int i=0,count=0,pv1,pv2;
	vector<Edge*> res;
	while(count<parent.size()-1){
		pv1= parent[edges[i]->v1];
		pv2= parent[edges[i]->v2];
		while(parent[pv1] != pv1){
			pv1= parent[pv1];
		}
		while(parent[pv2] != pv2){
			pv2= parent[pv2];
		}
		if(pv1!=pv2){
			res.push_back(edges[i]);
			parent[edges[i]->v1] = parent[edges[i]->v2];
			count++;
		}
		i++;
	}
	return res;
}

int main(){
	int n,v1,v2,w;
	cin>>n;
	vector<Edge*> edges;
	while(n){
		cin>>v1;
		cin>>v2;
		cin>>w;
		edges.push_back(new Edge(v1,v2,w));
		n--;
	}
	cout<<endl<<endl;
	vector<Edge*> minSpanTree = kruskalsAlgorithm(edges);
	for(int i=0;i<minSpanTree.size();i++){
		minSpanTree[i]->print();
	}
	return 0;
}