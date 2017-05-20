#include <iostream>
#include <queue>

using namespace std;

struct node{
    int data;
    node *left,*right;
}*root;

node* newNode(int var){
    node* temp = new node;
    temp->data = var;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

node* make_tree(vector<int> &v,int first,int last){

        if(first>last) return NULL;

        int mid = (first+last)/2;
        node *temp = newNode(v[mid]);

        root->left= make_tree(v,first,mid-1);
        root->right=make_tree(v,mid+1,last);

    return root;
}

void level_order(node* root){
    if(root==NULL) return;
    queue<node*> q; int nodes;
    q.push(root);
    while(1){
        nodes = q.size();
        if(nodes==0) break;
        while(nodes>0){
            node *temp = q.front();
            cout<<temp->data<<" ";
            q.pop(); nodes--;
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        cout<<endl;
    }
}

int main()
{
    vector<int> v; v.clear();
    for(int i=1;i<=7;i++) v.push_back(i);
    int last = v.end()-v.begin();
    root = make_tree(v,0,last);
    level_order(root);

    return 0;
}
