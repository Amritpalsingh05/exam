//circular linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
};
struct node* createnode(){
	struct node* node=(struct node*)malloc(sizeof(struct node));
	printf("Enter data ");
	scanf("%d ",&node->data);
	node->next=NULL;
	return node;
}
struct node* head=NULL,*tail=NULL;
void createlist(){
	int size,i;
	printf("Enter size ");
	scanf("%d",&size);
	for(i=0;i<size;i++){
		struct node* newnode=createnode();
		if(head==NULL){
			tail=head=newnode;
		}
		else{
			tail->next=newnode;
			tail=newnode;
			tail->next=head;
		}
	}
}
void display(){
	struct node* temp=head;
	do{
		printf("%d ",temp->data);
		temp=temp->next;
	}while(temp!=head);
}
int count(){
	int cnt=0;
	struct node* temp=head;
	do{
		temp=temp->next;
		cnt++;
	}while(temp!=head);
	return cnt;
}
void insbeg(){
	struct node* insbeg=createnode();
	insbeg->next=head;
	head=insbeg;
}
void insend(){
	struct node* insend=createnode();
	tail->next=insend;
	insend->next=head;
}
void inspos(){
	int pos,i=1;
	printf("Enter pos");
	scanf("%d",&pos);
	if(pos==1){
		insbeg();
	}
	else if(pos==count()+1){
		insend();
	}
	else if(pos>count()){
		printf("Invaild pos");
	}
	else if(head==NULL){
		printf("List is empty");
	}
	else{
		struct node* posnode=createnode();
		struct node* temp=head;
		while(i<pos-1){
			temp=temp->next;
			i++;
		};
		posnode->next=temp->next;
		temp->next=posnode;
		
	}
}
void delbeg(){
	head=head->next;
	tail->next=head;
}
void delend(){
	struct node* temp=head;
	struct node* prevnode;
	do{
		prevnode=temp;
		temp=temp->next;
	}while(temp->next!=head);
	tail=prevnode;
	tail->next=head;
}
void delpos(){
	int pos,i=1;
	printf("Enter pos");
	scanf("%d",&pos);
	if(pos==1){
		delbeg();
	}
	else if(pos==count()+1){
		delend();
	}
	else if(pos>count()){
		printf("Invaild pos");
	}
	else if(head==NULL){
		printf("List is empty");
	}
	else{
		struct node* temp=head;
		while(i<pos-1){
			temp=temp->next;
			i++;
		}
		struct node* delnode;
		delnode=temp->next;
		temp->next=delnode->next;
		free(delnode);
	}
}
