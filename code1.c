#include<stdio.h>
#include<stdlib.h>
#define maxsize 10
int stk[maxsize],top=-1;
void push(int a){
    if(top==maxsize-1){
        printf("stack overflow\n");
    }
    else{
        top++;
        stk[top] = a;
        printf("element added\n");
    }
}
void pop(){
    if(top==-1){
        printf("stack underflow\n");
    }
    else{
        top--;
        printf("element deleted\n");
    }
}
void peek(){
    if(top==-1){
        printf("stack underflow\n");
    }
    else{
        printf("%d",stk[top]);
    }
}
int main(){
    push(60);
    push(70);
    push(80);
    push(90);
    push(10);
    push(20);
    push(30);
    push(45);
    push(50);
    push(40);
    push(55);
    peek();
}