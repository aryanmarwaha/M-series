#include <bits/stdc++.h>
using namespace std;

template <typename T>
class BinTreeNode{
public:
	T data;
	BinTreeNode<T> *left;
	BinTreeNode<T> *right;
	BinTreeNode(T data){
		this->data= data;
		this->left=NULL;
		this->right=NULL;
	};
	~BinTreeNode(){
		delete this->left;
		delete this->right;
	}
	
};
BinTreeNode<int>* createBSTHelper(vector<int>& arr,int s,int e){
	if(s>e) return NULL;
	int mid= (s+e)/2;
	BinTreeNode<int>* root= new BinTreeNode<int>(arr[mid]);
	root->left=createBSTHelper(arr,s,mid-1);
	root->right=createBSTHelper(arr,mid+1,e);
	return root;
}
BinTreeNode<int>* createBST(){
	vector<int> arr;
	int n,tmp;
	cin>>n;
	while(n){
		cin >> tmp;
		arr.push_back(tmp);
		n--;
	}
	sort(arr.begin(),arr.end());
	BinTreeNode<int>* root= createBSTHelper(arr,0,arr.size()-1);
	return root;
}
BinTreeNode<int>* createBinaryTreePreOrder(){
	int data;
	cin>>data;
	if(data==-1) return NULL;
	BinTreeNode<int>* root= new BinTreeNode<int>(data);
	root->left= createBinaryTreePreOrder();
	root->right= createBinaryTreePreOrder();
	return root;
}
BinTreeNode<int>* createBinaryTreeLevelOrder(){
	int data;cout<<"data for root-node: "; cin>>data;
	BinTreeNode<int>* root= NULL;
	queue<BinTreeNode<int>*> q1;
	if(data!=-1){
		root= new BinTreeNode<int>(data);
		q1.push(root);
	}
	while(!q1.empty()){
		BinTreeNode<int>* front= q1.front();
		q1.pop();
		cout<<"Left child for "<<front->data<<": ";
		cin>>data;
		if(data!=-1){
			front->left= new BinTreeNode<int>(data);
			q1.push(front->left);
		}
		cout<<"right child for "<<front->data<<": ";
		cin>>data;
		if(data!=-1){
			front->right= new BinTreeNode<int>(data);
			q1.push(front->right);
		}
	}
	return root;
}
void printTreeInOrder(BinTreeNode<int>* root){
	if(root==NULL) return;
	printTreeInOrder(root->left);
	cout<<root->data<<" ";
	printTreeInOrder(root->right);
}
void printTreePreOrder(BinTreeNode<int>* root){
	if(root==NULL) return;
	cout<<root->data<<" ";
	printTreeInOrder(root->left);
	printTreeInOrder(root->right);
}
void printTreePostOrder(BinTreeNode<int>* root){
	if(root==NULL) return;
	printTreeInOrder(root->left);
	printTreeInOrder(root->right);
	cout<<root->data<<" ";
}