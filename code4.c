//doubly Linked List 
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
	struct node* prv;
};
struct node* head=NULL,*tail=NULL;
struct node* createnode(){
	struct node* node=(struct node*)malloc(sizeof(struct node));
	printf("Enter data");
	scanf("%d",&node->data);
	node->next=NULL;
	node->prv=NULL;
	return node;
}
void createlist(){
	int size;
	int i;
	printf("Enter Size: ");
	scanf("%d",&size);
	for(i=0;i<size;i++){
		struct node* newnode=createnode();
		if(head==NULL){
			tail=head=newnode;
		}
		else{
			tail->next=newnode;
			tail->prv=tail;
			tail=newnode;
		}
	}
}
void displaybeg(){
	struct node* temp=head;
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp=temp->next;
	}
}
void displayend(){
	struct node* temp=tail;
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp=temp->prv;
	}
}
int count(){
	int cnt=0;
	struct node*temp=head;
	while(temp!=NULL){
		temp=temp->next;
		cnt++;
	}
	return cnt;
}
void delbeg(){
	struct node* temp=head;
	head=head->next;
	head->prv=NULL;
	free(temp);
}
void delend(){
	struct node*temp;
	temp=tail;
	tail=tail->prv;
	free(temp);
}
void delpos(){
	int pos;
	int i=1;
	printf("Enter Pos ");
	scanf("%d ",&pos);
	if(head==NULL){
		printf("Linked List is empty ");
	}
	else if(pos>count()){
		printf("Invaild Position");
	}
	else if(pos==1){
		delbeg();
	}
	else if(pos==count()+1){
		delend();
	}
	else{
		struct node* temp=head;
		while(i<pos-1){
			temp=temp->next;
		}
		struct node* delnode=temp->next;
		struct node* updatenode=delnode->next;
		temp->next=updatenode;
		updatenode->prv=temp;
		free(delnode);
	}
}
void insbeg(){
	struct node* insnode=createnode();
	head->prv=insnode;
	insnode->next=head;
	head=insnode;
}
void insend(){
	struct node* insend=createnode();
	tail->next=insend;
	insend->prv=tail;
	tail=insend;
	
}
void insany(){
	int pos,i=1;
	printf("Enter pos ");
	scanf("%d ",&pos);
	if(head==NULL){
		printf("Linked List is empty ");
	}
	else if(pos>count()){
		printf("Invaild Position");
	}
	else if(pos==1){
		insbeg();
	}
	else if(pos==count()+1){
		insend();
	}
	else{
		struct node* insany=createnode();
		struct node* temp=head;
		while(i<pos-1){
			temp=temp->next;
		}
		struct node* temp1=temp->next;
		temp->next=insany;
		insany->prv=temp;
		insany->next=temp1;
		temp1->prv=insany;
	}
}




