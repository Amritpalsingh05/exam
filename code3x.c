#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* head=NULL;
//function to createnode
struct node* createnode(){
    struct node* node=(struct node*)malloc(sizeof(struct node));
    printf("Enter Data");
    scanf("%d",&node->data);
    node->next=NULL;
    return node;
}
//function to createlist
void createlist(){
    int i;
    int size;
    printf("Enter size of Linked List");
    scanf("%d",&size);
    struct node* temp = NULL;
    for(i=0;i<size;i++){
        struct node* newnode=createnode();
        if(head==NULL){
            head=temp=newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }

    }
}

//function to display
void display(){
    struct node* temp=NULL;
    temp=head;
    while(temp!=NULL){
        printf("%d",temp->data);
        temp = temp->next;
    }

}
//function to count
int count(){
    int cnt=0;
    struct node* temp=NULL;
    temp=head;
    while(temp!=NULL){
        temp=temp->next;
        cnt++;
    }
    return cnt;
}
//insertion at begginging
void insertatbeg(){
    struct node* begnode=createnode();
    begnode->next=head;
    head=begnode;
}

//insertion at end
void insertatend(){
    if(head==NULL){
        printf("Invalid");
    }
    else{
        struct node* endnode=createnode();
        struct node* temp=NULL;
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=endnode;
    }
}
//insertion at any point
void insertatpos(){
    int pos;
    printf("Enter Position");
    scanf("%d",&pos);
    if(pos==1){
        insertatbeg();
    }
    else if(pos==count()+1){
        insertatend();
    }
    else if(pos>count()){
        printf("Invalid");
    }
    else{
        int i=1;
        struct node* posnode=createnode();
        struct node* temp;
        temp=head;
        while(i<pos-1){
            
        }
    }

}

//deletion at begginging
void delatbeg(){
    struct node* temp=NULL;
    temp=head;
    if(head->next==NULL){
        head=NULL;
    }
    else{
        head=temp->next;
    }
    free(temp);
}
//deletion at end 
void delatend(){
    struct node* temp,*prevnode;
    temp=head;
    while(temp->next!=NULL){
        prevnode=temp;
        temp=temp->next;
    }
    prevnode->next=NULL;
    free(temp);
}
//deletion at pos
void delatpos(){
    int i;
    int pos;
    printf("Enter pos");
    scanf("%d",&pos);
    if(pos==1){
        delatbeg();
    }
    else if(pos=count()+1){
        delatend();
    }
    else if(pos>count()){
        printf("Invalid");
    }
    else{
        int i=1;
        struct node*temp,*delnode;
        temp=head;
        while(i<pos-1){
            temp=temp->next;
            i++;
        }
        delnode=temp->next;
        temp->next=delnode->next;
    }
}
int main(){
    createlist();
    while(1){
        system("cls");
        int choice;
        printf("1.Insertion at begginging\n");
        printf("2.Inserrtion at end\n");
        printf("3.Insertion at any pos\n");
        printf("4.Deletion at begginging\n");
        printf("5.Deletion at End\n");
        printf("6.deletion at any pos\n");
        printf("7.Lenght of Linked List\n");
        printf("8.Display\n");
        printf("9.Exit\n");
        printf("\n\nEnter your choice:-");
        scanf("%d",&choice);
        switch(choice);
            case1:
                insertatbeg();
                break;
            case2:
                insertatend();
                break;
            case3:
                insertatpos();
                break;
            case4:
                delatbeg();
                break;
            case5:
                delatend();
                break;
            case6:
                delatpos();
                break;
            case7:
                printf("%d\n",count());
                break;
            case8:
                display();
                break;
            case9:
                exit(0);
                break;
                //default:
                //printf("INvalid Choice");

    }
    system("pause");
}