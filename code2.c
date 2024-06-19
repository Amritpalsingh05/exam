#include<stdio.h>
#include<stdlib.h>
#define maxsize 1000
int list[maxsize],size;
void create(){
    int i;
    printf("enter the size of list:\n");
    scanf("%d",&size);
    if(size>maxsize){
        printf("list overflow!!!!\n");
    }
    else{
        for(i=0;i<size;i++){
            printf("enter the elements\n");
            scanf("%d",&list[i]);
        }
    }
}
void display(){
    if(size==0){
        printf("list is empty\n");
    }
    else{
        printf("list elements are:\n");
        int i;
        for(i=0;i<size;i++){
            printf("%d\n ",list[i]);
        }
    }
}
void insert(){
    if(size==0){
        printf("list is empty\n");
    }
    else{
        int pos,value,i;
        printf("enter pos\n");
        scanf("%d",&pos);
        printf("enter value\n");
        scanf("%d",&value);
        for(i=size-1;i>pos-1;i--){
            list[i+1] = list[i];
        }
        list[pos-1] = value;
        size++;
    }
}
void delete(){
    if(size==0){
        printf("list is empty\n");
    }
    else{
        int pos,i;
        printf("enter pos\n");
        scanf("%d",&pos);
        if(pos>0 && pos>=size){
            for(i=pos-1;i<size;i++){
                list[i] = list[i+1];
                size--;
            }
        }
    }
}
void search(){
    if(size==0){
        printf("list is empty\n");
    }
    else{
        int val,i;
        printf("enter the value you wqant to search\n");
        scanf("%d",&val);
        for(i=0;i<size;i++){
            if(list[i] =val){
                break;
            }
            if(i==size){
                printf("element not found\n");
            }
            else{
                printf("element found!!!!\n");
            }
        }
    }
}
int main(){
    create();
    insert();
    display();
    delete();
    display();
    search();
    return 0;
}