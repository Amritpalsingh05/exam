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
        printf("Element added\n");
    }
}
void pop(){
    if(top==-1){
        printf("stack underflow\n");
    }
    else{
        top--;
        printf("Element deleted\n");
    }
}
void peek(){
    if(top==-1){
        printf("stack underflow/n");
    }
    else{
        printf("%d",stk[top]);
    }
}
int main(){
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    push(60);
    push(70);
    push(80);
    push(90);
    push(100);
    peek();
    pop();
    peek();
    push(69);
    push(79);
}