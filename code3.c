#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* head = NULL;
//function to create node
struct node *createnode(){
    struct node* node=(struct node*)malloc(sizeof(struct node));
    printf("Enter data");
    scanf("%d",&node->data);
    node->next=NULL;
    return node;
}
//function to createlist
void createlist(){
    int i;
    int size;
    printf("Enter size of Linked list");
    scanf("%d",&size);
    struct node *temp=NULL;
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
        printf("%d ",temp->data);
        temp = temp->next;
    }

}
//count function
int count(){
    int cnt = 0;
    struct node* temp = NULL;
    temp=head;
    while(temp!=NULL){
        cnt++;
        temp = temp->next;
    }
    return cnt;
}
//insertion at begginging
void insertatbeg(){
    struct node* begnode = createnode();
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
        struct node* temp;
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
        printf("Invalid pos");
    }
    else{
        int i = 1;
        struct node* posnode = createnode();
        struct node* temp;
        temp=head;
        while(i<pos-1){
            temp = temp->next;
            i++;
        }
        posnode->next=temp->next;
            temp->next=posnode;
    }

}

//deletion at begginging
void del_at_beg(){
    struct node* temp;
    temp=head;
    if(head->next==NULL){
        head=NULL;
    }
    else{
        head=head->next;
    }
    free(temp);
}
//deletion at end
void del_at_end(){
    struct node *temp,*prevnode;

    temp=head;
    while(temp->next!=NULL){
        prevnode=temp;
        temp=temp->next;
    }
    prevnode->next=NULL;
    free(temp);


}
//deletion at pos
void del_at_pos(){
    int pos;
    printf("Enter Position");
    scanf("%d",&pos);
    struct node *temp,*delnode;
    if(pos==1){
        del_at_beg();
    }
    else if(pos>count()){
        printf("Invalid pos!!");
    }
    else if(pos==count()){
        del_at_end();
    }
    else{
        int i=1;
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
        printf("2.Insertion at End\n");
        printf("3.Insertion at any pos\n");
        printf("4.Deletion at begginging\n");
        printf("5.Deletion at End\n");
        printf("6.Deletion at any pos\n");
        printf("7.Lenght of Linked List\n");
        printf("8.Display\n");
        printf("9.Exit\n");
        printf("\n\nEnter Your Choice:-");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                insertatbeg();
                break;
            case 2:
                insertatend();
                break;
            case 3:
                insertatpos();
                break;
            case 4:
                del_at_beg();
                break;
            case 5:
                del_at_end();
                break;
            case 6:
                del_at_pos();
                break;
            case 7:
                printf("%d\n",count());
                break;
            case 8:
                display();
                break;
            case 9:
                exit(0);
                break;
            default:
                printf("Invalid choice");

        }
        system("pause");
    }


}