#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
};
struct node* top=NULL;
struct node* createnode(int data){
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->next=NULL;
	return newnode;
	
}
void push(int data){
	struct node *push=createnode(data);
	push->next=top;
	top=push;
}
void pop(){
	struct node *temp=top;
	top=top->next;
	free(temp);
}
void peek(){
	struct node *temp=top;
	printf("%d peek\n ",temp->data);
}
void display(){
	struct node *temp=top;
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp=temp->next;
	}
}
#include<stdio.h>
int main(){
	push(112);
	push(19);
	push(15);
	push(18);
	pop();
	peek();
	display();
}
