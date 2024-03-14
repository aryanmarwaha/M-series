template <typename T>
class AVLTreeNode{
private:
public:
	T data;
	AVLTreeNode<T>* left;
	AVLTreeNode<T>* right;
	int height;
	AVLTreeNode(T data,int height=1){
		this->left= NULL;
		this->right= NULL;
		this->data= data;
		// height will be set to 1 by default.
		this->height= height;
	}
};

int getHeight(AVLTreeNode<int>* root){
	return (root==NULL) ? 0 : root->height;
}

int getBalanceFactor(AVLTreeNode<int>* root){
	return getHeight(root->left) - getHeight(root->right);
}

AVLTreeNode<int>* HandleLeftLeftInbalance(AVLTreeNode<int>* root){
	// rotation :
	AVLTreeNode<int>* tmp= root->left->right;
	AVLTreeNode<int>* newroot= root->left;
	root->left->right= root;
	root->left= tmp;

	// update new-heights :
	newroot->right->height= 1+ max(getHeight(newroot->right->left), getHeight(newroot->right->right));
	newroot->height= 1+ max(getHeight(newroot->left), getHeight(newroot->right));

	return newroot;
}
AVLTreeNode<int>* HandleLeftRightInbalance(AVLTreeNode<int>*root){
	// rotation :
	AVLTreeNode<int>* c = root->left->right->left;
	AVLTreeNode<int>* d = root->left->right->right;
	AVLTreeNode<int>* newroot = root->left->right;

	root->left->right->left= root->left;
	root->left->right->right= root;
	root->left->right= c;
	root->left= d;

	// update new-heights :
	newroot->left->height= 1+ max(getHeight(newroot->left->left), getHeight(newroot->left->right));
	newroot->right->height= 1+ max(getHeight(newroot->right->left), getHeight(newroot->right->right));
	newroot->height= 1+ max(getHeight(newroot->left), getHeight(newroot->right));

	return newroot;
}
AVLTreeNode<int>* HandleRightLeftInbalance(AVLTreeNode<int>*root){
	// rotation :
	AVLTreeNode<int>* c = root->right->left->left;
	AVLTreeNode<int>* d = root->right->left->right;
	AVLTreeNode<int>* newroot = root->right->left;

	root->right->left->right= root->right;
	root->right->left->left= root;
	root->right->left= d;
	root->right= c;

	// update new-heights :
	newroot->right->height= 1+ max(getHeight(newroot->right->right), getHeight(newroot->right->left));
	newroot->left->height= 1+ max(getHeight(newroot->left->right), getHeight(newroot->left->left));
	newroot->height= 1+ max(getHeight(newroot->right), getHeight(newroot->left));

	return newroot;
}
AVLTreeNode<int>* HandleRightRightInbalance(AVLTreeNode<int>*root){
	// rotation :
	AVLTreeNode<int>* tmp= root->right->left;
	AVLTreeNode<int>* newroot= root->right;
	root->right->left= root;
	root->right= tmp;

	// update new-heights :
	newroot->left->height= 1+ max(getHeight(newroot->left->left), getHeight(newroot->left->right));
	newroot->height= 1+ max(getHeight(newroot->left), getHeight(newroot->right));

	return newroot;
}

AVLTreeNode<int>* insert(AVLTreeNode<int>* root, int data){
	if(root==NULL) return new AVLTreeNode<int>(data);
	if(data < root->data){
		root->left= insert(root->left, data);
	}
	else if(data > root->data){
		root->right= insert(root->right, data);
	}
	else return root;

	// updating the height for the current node;
	root->height= 1 + max(getHeight(root->left), getHeight(root->right));
	
	int balanceFact= getBalanceFactor(root);

	// LL- inbalance :
	if(balanceFact > 1 && data < root->left->data){
		return HandleLeftLeftInbalance(root);
	}
	// LR- inbalance :
	else if(balanceFact > 1){
		return HandleLeftRightInbalance(root);
	}
	// RL- inbalance :
	else if(balanceFact < -1 && data < root->right->data){
		return HandleRightLeftInbalance(root);
	}
	// RR- inbalance :
	else if(balanceFact < -1){
		return HandleRightRightInbalance(root);
	}
	// Returning the unchanged node :
	return root;
}

void printPreOrder(AVLTreeNode<int>* root){
	if(root==NULL) return;
	cout<<root->data<<" ";
	printPreOrder(root->left);
	printPreOrder(root->right);
}

