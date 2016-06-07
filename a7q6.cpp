#include<iostream>
using namespace std ;
int length(char str[]){
    int len;
    for(len=0;str[len]!='\0';len++);
    return len ;
}
void squeeze(char str[],int l){
    int j;
    int k = 0;
    char arr[100] ;
    for(j=0;j<l;j++){
        if(str[j]!=' '){
            arr[k] = str[j] ;
            k++ ;
        }
        else{             //Here leaving the whitespace.
            continue ;
        }
    }
    int p;
    for(p=0;p<k;p++){
        cout << arr[p] ;
    }
    return ;
}
int main()
{
    int i ;
    char str[100];
    cin.getline(str,100) ;
    i = length(str) ;
    squeeze(str,i);
    return 0 ;
}
