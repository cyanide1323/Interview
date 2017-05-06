// cpp program to find the lca of a binary tree
#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *left,*right;
}*root;

node* newNode(int var){

        node *temp = new node;
        temp->data = var;
        temp->left=temp->right=NULL;

        return temp;
}

node* findLCA(node *root,int n1,int n2){

    if(!root) return NULL;

    if(root->data==n1 || root->data==n2) return root;

    node *left = findLCA(root->left,n1,n2);
    node *right = findLCA(root->right,n1,n2);

    if(left && right) return root;

    return left!=NULL?left:right;
}

int main(){
    node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    cout << "LCA(4, 5) = " << findLCA(root, 4, 5)->data;
    cout << "\nLCA(4, 6) = " << findLCA(root, 4, 6)->data;
    cout << "\nLCA(3, 4) = " << findLCA(root, 3, 4)->data;
    cout << "\nLCA(2, 4) = " << findLCA(root, 2, 4)->data;
    return 0;
}
