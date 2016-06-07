#include<iostream>
using namespace std ;
int length(char str[]){
    int i ;
    for(i=0;str[i]!='\0';i++){}
    return i ;
}
bool checkreverse(char str1[],char str2[],int i,int len){
    if(len<0){
        return true;
    }
    if(i<len&&len-1>=0&&str1[i]==str2[len-1]){
        checkreverse(str1,str2,i+1,len-1) ;
    }
    if(str1[i]!=str2[len-1]){
        return false ;
    }
}
int main()
{
    char str1[100],str2[100] ;
    int len1,len2 ;
    cout << "Enter 1st string" << endl ;
    cin.getline(str1,100) ;
    len1 = length(str1) ;
    cout << "Enter 2nd string" <<endl ;
    cin.getline(str2,100) ;
    len2 = length(str2) ;
    if(len1!=len2){
        cout << "Strings not reverse of each other!" << endl ;
    }
    if(checkreverse(str1,str2,0,len1)){
        cout << "Strings are reverse of each other!"  ;
    }
    else{
        cout << "Strings are NOT reverse of each other!" ;
    }
    return 0 ;
}

