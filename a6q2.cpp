//string compression aaabbccccds >>>> a3b3c4d1s1
#include<iostream>
using namespace std;
int length(char str[]){
    int len;
    for(len=0;str[len]!=NULL;len++){
    }
    return len;
}
int main(){
    char str[100];
    cout << "Enter string" << endl;
    cin.getline(str,100);
    int len = length(str);
    int i,j,k,count;
    i=0;
    cout << "Compressed string :  ";
    while(i<len){
        count = 1;
        for(j=i+1;str[j]==str[i];j++){
            count++;
        }
        cout << str[i] << count;
        i=j;
    }
    return 0;
}
