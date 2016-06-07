#include<iostream>
using namespace std;
int length(char str[]){
    int len;
    for(len=0;str[len]!='\0';len++){
    }
    return len;
}
void rev_string(char str[],int start, int end){
    if(start>end){
        return;
    }
    else{
        int temp;
        temp=str[start];
        str[start]=str[end];
        str[end]=temp;
        return rev_string(str,start+1,end-1);
    }
}
int main(){
    char str[100];
    cout << "Enter string : ";
    cin.getline(str,100);
    int len;
    len=length(str);
    rev_string(str,0,len-1);
    cout << "Reversed string : " << str;
    return 0;
}
