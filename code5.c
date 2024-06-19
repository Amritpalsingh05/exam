//circular linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* createnode(){
    struct node* node=(struct node*)malloc(sizeof(struct node));
    printf("Enter Data");
    scanf("%d",&node->data);
    node->next=NULL;
    struct node* head=NULL,*tail=NULL;
    return node;
}
struct node* head=NULL,*tail=NULL;
void createlist(){
    int size,i;
    printf("Enter data");
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
        printf("%d",temp->data);
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

}
void insend(){

}
void inspos(){

}
void delen(){

}
