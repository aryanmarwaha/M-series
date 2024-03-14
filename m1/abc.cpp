#include "bintree.h"
using namespace std;

// question 1:-----------------------------------------------------------
// void maxProfit(vector<vector<int>>& items,int &maxP,int i,int currP,int remCap){
// 	if(remCap<0) return;
// 	if(maxP<currP) maxP=currP;
// 	if(i>=items.size()) return;
// 	maxProfit(items,maxP,i+1,currP,remCap);
// 	currP+=items[i][1];
// 	maxProfit(items,maxP,i+1,currP,remCap-items[i][0]);
// }
// int maxProfit(vector<vector<int>>& items,int &cap){
// 	int maxP=INT_MIN;
// 	maxProfit(items,maxP,0,0,cap);
// 	return maxP;
// }
// int main(){
// 	int n,cap;
// 	cin>>n;
// 	vector<vector<int>> items;
// 	for(int w,p;n>0;n--){
// 		cin>>w;
// 		cin>>p;
// 		items.push_back({w,p});
// 	}
// 	cin>>cap;
// 	cout<< maxProfit(items,cap)<<endl;
// 	return 0;}


// question 2:-----------------------------------------------------------
// int main(){
// 	int n;
// 	cin >> n;
// 	vector<int> arr;
// 	for(int tmp;n>0;n--){
// 		cin>>tmp;
// 		arr.push_back(tmp);
// 	}
// 	sort(tmp.begin(),tmp.end());
// 	BinTreeNode<int> *root= genBSTree(arr,0,arr.size()-1);
// }


// question 3:------------------------------------------------------------
// BinTreeNode<int>* deleteLeftMostLeafNode(BinTreeNode<int>*root){
// 	if(root==NULL) return NULL;
// 	if(root->left==NULL && root->right==NULL){
// 		delete root;
// 		return NULL;
// 	}
// 	root->left= deleteLeftMostLeafNode(root->left);
// }
// BinTreeNode<int>* deleteRightMostLeafNode(BinTreeNode<int>*root){
// 	if(root==NULL) return NULL;
// 	if(root->left==NULL && root->right==NULL){
// 		delete root;
// 		return NULL;
// 	}
// 	root->right= deleteRightMostLeafNode(root->right);
// }
// BinTreeNode<int>* deleteALLLeaves(BinTreeNode<int>* root){
// 	if(root==NULL) return NULL;
// 	if(root->left==NULL && root->right==NULL){
// 		delete root;
// 		return NULL;
// 	}
// 	root->left= deleteALLLeaves(root->left);
// 	root->right= deleteALLLeaves(root->right);
// }
// int main(){
// 	BinTreeNode<int> *root= createBST();
// 	// root=deleteRightMostLeafNode(root);
// 	// root=deleteRightMostLeafNode(root);
// 	root=deleteALLLeaves(root);
// 	printTreePostOrder(root);
// 	return 0;
// }


// question 4:-----------------------------------------------------------
// int maxProfit(vector<vector<int>>&arr,int i=0,int j=0){
// 	if(i>=arr.size() || j>=arr[0].size()) return 0;
// 	return max(maxProfit(arr,i+1,j),maxProfit(arr,i,j+1)) + arr[i][j];
// }
// int main(){
// 	int n,m;
// 	cin>>n;
// 	cin>>m;
// 	vector<vector<int>> arr;
// 	for(int i=0,tmp;i<n;i++){
// 		arr.push_back({});
// 		for(int j=0;j<m;j++){
// 			cin>>tmp;
// 			arr[i].push_back(tmp);
// 		}
// 	}
// 	cout<< maxProfit(arr)<<endl;
// }

// question 5:-----------------------------------------------------------
// void noOfWays(string &str,int i,int &ans){
// 	if(str[i]=='0') return;
// 	if((i==str.size()-1 || i==str.size()) && str[i]!='0'){
// 		ans++;
// 		return;
// 	}
// 	if((i+1<str.size() && str[i+1]!='0') || i+1==str.size()){
// 		noOfWays(str,i+1,ans);
// 	}
// 	if((i+2<str.size() && str[i+2]!='0') || i+2==str.size()){
// 		int tmp= stoi(str.substr(i,i+2));
// 		if(0<tmp && tmp<27) noOfWays(str,i+2,ans);
// 	}
// }
// int noOfWays(string &str, int i){
// 	if(i==str.length()) return 1;
// 	if(str[i]=='0'){
// 		return 0;
// 	}
// 	int ways1=noOfWays(str,i+1);

// 	int ways2=0;

// 	if(str[i]=='1' || (i+1<str.size() && str[i]=='2' && str[i+1]<'7')){
// 		ways2=noOfWays(str,i+2);
// 	}

// 	return ways1+ways2;
// }
// int main(){
// 	string str;
// 	cin>>str;
// 	int ans=0;
// 	cout<<noOfWays(str,0);
// 	// cout<<ans<<endl;
// }

// question 6:-------------------------------------------------------
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/solutions/4642593/simple-dfs-solution/
// int main(){
// 	BinTreeNode<int>*root= createBinaryTreeLevelOrder();
// 	printTreePreOrder(root);
// 	return 0;
// }

// question8:-------------------------------------------------------

int main(){
	cout<<"hello world"<<endl;
	return 0;
}
