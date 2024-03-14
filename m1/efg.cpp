#include <bits/stdc++.h>
using namespace std;

vector<bool> seivesBlaBla(int n, vector<bool>& res){
	for(int i=2;i*i<n;i++){
		if(!res[i]) continue;
		for(int j=1;i*j<n;j++){
			res[i*j]=false;
		}
	}
	return res;
}

int main(){
	int n =1000000;
	vector<bool> res(n,true);
	seivesBlaBla(n,res);
	for(int i=0;i<res.size();i++){
		cout<<i<<" : "<<res[i]<<endl;
	}
	return 0;
}