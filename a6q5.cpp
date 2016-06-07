#include<iostream>
using namespace std;
int length(char str[]){
    int len;
    for(len=0;str[len]!=NULL;len++){
    }
    return len;
}
int main(){
    char str1[100],str2[100];
    int i,j,k,len1,len2,key;
    cout << "Enter string 1 : ";
    cin.getline(str1,100);
    cout << "Now enter string 2 : ";
    cin.getline(str2,100);
    len1 = length(str1);
    len2 = length(str2);
    if(len1>len2){
        cout << "Going nuts?" << endl;
    }
    else{
        for(i=0;i<len2;i++){
            j=0;
            if(str1[j]==str2[i]){
                for(k=i;j<len1;j++,k++){
                    if(str2[k]!=str1[j]){
                        break;
                    }
                    else{
                        if(j==(len1-1)){
                            key = j;
                            cout << "Position of rightmost occurrence of First string in Second string is : " << k+1;
                            break;
                        }
                    }
                }
            }
        }
        if(key!=(len1-1)){
            cout << "First string does not occur in Second string";
        }
    }
    return 0;
}
