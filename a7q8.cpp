#include<iostream>
using namespace std;
int length(char str[]){
    int len;
    for(len=0;str[len]!='\0';len++){
    }
    return len;
}
void remove_duplicates(char str[100],int len){
    int i,j;
    char fin_str[100];
    for(i=0;i<len;i++){
        for(j=i+1;j<len;j++){
            if(str[i]==str[j]){
                str[j]='^';
            }
        }
    }
    for(i=0,j=0;i<len;i++){
        if(str[i]!='^'){
            fin_str[j]=str[i];
            j++;
        }
    }
    cout << "Final array without duplicates : ";
    for(i=0;i<j;i++){
        cout << fin_str[i];
    }
    return;
}
int main(){
    char str[100];
    cout << "Enter string : ";
    cin.getline(str,100);
    int len = length(str);
    remove_duplicates(str,len);
    cout << "_____" << endl;
    cout << str;
    return 0;
}
