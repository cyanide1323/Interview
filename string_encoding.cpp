// amazon program 

#include <bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node *next;
};

node* newNode(int data){
	node *temp = new node;
	temp->data = data;
	temp->next = NULL;
	return temp;
}

bool palindrome(node **head, node *end){

	if(end->next==NULL)
		return ((*head)->data == end->data) ; 
	
	bool flag= palindrome(head,end->next);
	(*head) = (*head)->next;

	return (flag and ((*head)->data == end->data));
}

int main(){
	
	// construct the linked list
	node *head = newNode(1);
	head->next = newNode(1);
	

	if(palindrome(&head,head)) printf("%s\n", "Yes it is" );
	else printf("%s\n", "No it is not");
	return 0;
}