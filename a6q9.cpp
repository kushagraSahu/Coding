//Find substrings which are palindrome.
#include<iostream>
using namespace std;
static int count = 0;
int length(char str[100]){
    int len;
    for(len=0;str[len]!=NULL;len++){
    }
    return len;
}
int main(){
    char str[100];
    cout << "Enter string" << endl;
    cin.getline(str,100);
    int len,i,j,m,n,k;
    len = length(str);
    for(i=0;i<len;i++){
        for(j=i+1;j<len;j++){
           // cout << "Starting with first letter" << str[i] << endl;
            if(str[i]==str[j]){
//                cout << str[j] << endl;
                for(m=i+1,n=j-1;str[m]==str[n]&&m<=n;m++,n--){
                }
                if(m>n){
                    if(!count){
                        cout << "Substrings which are palindrome: " << endl;
                    }
                    for(k=i;k<=j;k++){
                        cout << str[k];
                    }
                    cout << endl;
                    count++;
                }
            }
            //cout << "Changing first letter" << endl;
        }
        //cout << "Reached" << endl;
    }
    if(!count){
        cout << "None of the substrings are palindrome!" << endl;
    }
    cout << "No. of substring which are palindrome : " << count;
    return 0;
}
