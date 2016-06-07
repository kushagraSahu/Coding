#include<iostream>
using namespace std;
void getline(){
    char str[100];
    int i;
    for(i=0;1;i++){
        str[i]=cin.get();
        if(str[i]=='\n'){
            break;
        }
    }
    for(i=0;str[i]!='\n';i++){
        cout << str[i];
    }
    return;
}
int main(){
    char str[100];
    cout << "Enter string" << endl;
    getline();
    return 0;
}
