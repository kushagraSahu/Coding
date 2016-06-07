#include<iostream>
using namespace std;
int length(char str[]){
    int len;
    for(len=0;str[len]!=NULL;len++){
    }
    return len;
}
void join(char str1[],int p,char str2[],int q){
    int i,j;
    char arr[100];
    for(i=0;i<p;i++){
        arr[i]=str1[i];
    }
    for(i=p,j=0;i<p+q;i++,j++){
        arr[i]=str2[j];
    }
    cout << "Combined string : ";
    /*for(i=0;i<p+q;i++){
        cout << arr[i];
    }*/
    cout << arr;
    return;
}
int main(){
    char str1[100],str2[100];
    cout << "Enter first string : ";
    cin.getline(str1,100);
    cout << "Enter second string : ";
    cin.getline(str2,100);
    int len1,len2;
    len1 = length(str1);
    len2 = length(str2);
    join(str1,len1,str2,len2);
    return 0;
}
