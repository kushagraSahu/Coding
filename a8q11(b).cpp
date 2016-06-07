//Remove duplicates with string modification method.
#include<iostream>
using namespace std;
int length(char str[]){
    int len;
    for(len=0;str[len]!='\0';len++){
    }
    return len;
}
void transfer_duplicate(char str[],int j, int len){
    if(j==len-1){
        return;
    }
    else{
        char temp;
        temp=str[j];
        str[j]=str[j+1];
        str[j+1]=temp;
        transfer_duplicate(str,j+1,len);
    }
}
void rem_dup(char str[],int i,int len){
    if(str[i]=='0'){
        str[i]='\0';
        return;
    }
    if(str[i]==str[i+1]){
        str[i+1]='0';
        transfer_duplicate(str,i+1,len);
        cout << str;
        return rem_dup(str,i+2,len);
    }
    else{
        return rem_dup(str,i+1,len);
    }
}
int main(){
    char str[100];
    int len;
    cout << "Enter string consisting duplicates : ";
    cin.getline(str,100);
    len=length(str);
    rem_dup(str,0,len);
    cout << "String after removing consecutive duplicates : " << str;
    return 0;
}
