#include <iostream>
using namespace std;

#include "hashmap.h"
#include "avlTree.h"

int test_hashmap(){
    MyMap<int> mp;
    mp.insert("a",2);
    mp.insert("b",2);
    mp.insert("c",2);
    mp.insert("d",2);
    mp.insert("a",2);
    mp.insert("ab",4);
    mp.insert("abc",2);

    cout<<mp.get_value("a")<<" ";
    cout<<mp.get_value("b")<<" ";
    cout<<mp.get_value("c")<<" ";
    cout<<mp.get_value("d")<<" ";
    cout<<mp.get_value("a")<<" ";
    cout<<mp.get_value("ab")<<" ";
    cout<<mp.get_value("abc")<<" ";
    cout<<endl;
    return 0;
}
int test_AVLTree(){
	AVLTreeNode<int>* root= NULL;
	root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);
    printPreOrder(root);
    cout<<endl;
    return 0;
}

int main(){
    // return test_AVLTree();
    return test_hashmap();
}