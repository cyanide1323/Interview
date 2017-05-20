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

int height(node *root){

    if(!root) return 0;
    int lheight = height(root->left);
    int rheight = height(root->right);

    return max(lheight,rheight)+1;
}

// slow method of finding diameter of binary tree
int diameter(node *root){

    if(!root) return 0;

    int lheight = height(root->left);
    int rheight = height(root->right);

    int ldiameter = diameter(root->left);
    int rdiameter = diameter(root->right);

    return max(lheight+rheight+1,max(ldiameter,rdiameter));
}

// fast method of finding diameter of binary tree
int l=0,r=0;
int diameteropt(node *root,int *height){

    int ldiameter=0,rdiameter=0,lheight=0,rheight=0;
    if(!root){
        *height=0;
        return 0;
    }
   ldiameter = diameteropt(root->left,&lheight);
   rdiameter = diameteropt(root->right,&rheight);

   *height = max(lheight,rheight)+1;
   return max(max(ldiameter,rdiameter),lheight+rheight+1);
}

int main(){
    node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    cout<<"Diameter of binary tree is "<<diameteropt(root,0)<<endl;
    return 0;
}
