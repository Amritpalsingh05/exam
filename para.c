#include<stdio.h>
#include<string.h>
#define Max 100
char stk[Max];
char str[100];
int top=-1;
int flag=0;
int main(){
    int i;
    printf("Enter parenthesis to check ");
    gets(str);
    int len=strlen(str);
    for(i=0;i<len;i++){
        if(str[i]=='('||str[i]=='{'||str[i]=='['){
            top++;
            stk[top]=str[i];
        }
        else if(str[i]=='}'||str[i]==']'||str[i]==')'){
                char ch=str[i];
                if(ch==')'){
                    ch='(';
                }
                else if(ch=='}'){
                    ch='{';
                }
                else{
                    ch='[';
             }
            if(ch==stk[top]){
            top--;
        }
    }
    else{
        flag=1;
    }
}
if(top==-1 && flag==0){
    printf("Balanced");
}
else{
    printf("Unbalanced");
}
}