#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node *left,*right;
};

node* newNode(int data){
	
	node *temp = new node;
	temp->data = data;
	temp->left = temp->right = NULL;

	return temp;
}

// we have to do morris inorder traversal to do it in O(1) space complexity

int MorrisTraversal(node *root){
	
	node *curr = root, *pre;
	if(!root) return -1;
	int cnt = 0;
	while(curr){
		if(curr->left==NULL){
			//cout<<curr->data<<" ";
			cnt++;
			curr=curr->right;
		}
		else{
			pre=curr->left;
			while(pre->right!=NULL and pre->right!=curr)
				pre=pre->right;

			if(pre->right==NULL){
				pre->right=curr;
				curr=curr->left;
			}
			else{
				pre->right=NULL;
				//cout<<curr->data<<"  ";
				cnt++;
				curr=curr->right;
			}
		} 
	}
	return cnt;
}

int main(){

	node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	//print(root);
	cout << MorrisTraversal(root) << endl;

	return 0;
}