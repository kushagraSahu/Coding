//Do it with string modification method also!?
#include<iostream>
using namespace std ;
int length(char str[]){
    int length;
    for(length=0;str[length]!=0;length++);
    return length ;
}
void rem_consecutive_dup(char str[],int len,int i){
    if(i>=len){
        return;
    }
    if(i<len){
        if(str[i]!=str[i+1]){
            cout << str[i];
            rem_consecutive_dup(str,len,i+1);
        }
        else if(str[i]==str[i+1]){
            cout << str[i];
            rem_consecutive_dup(str,len,i+2);
        }
    }
}
int main(){
    int len;
    char str[100];
    cin.getline(str,100);
    len = length(str);
    rem_consecutive_dup(str,len,0);
    return 0;
}
