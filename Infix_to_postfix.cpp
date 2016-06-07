#include<iostream>
#include<stack>
using namespace std;
stack<int> S1,S2;
static int j=0;
char str_final[100];
void putinArray(char value){
    str_final[j]=value;
    cout << str_final[j];
    //str_final[i+1]=NULL;
    j++;
}
int main(){
    char str[100];
    cin.getline(str,100);
    for(int i=0;str[i]!=NULL;i++){
        if(str[i]=='('){
            S1.push(str[i]);
        }
        else if(str[i]=='*'||str[i]=='/'){
            while(S1.top()=='*'||S1.top()=='/'){
                putinArray(S1.top());
                S1.pop();
            }
            S1.push(str[i]);
        }
        else if(str[i]=='+'||str[i]=='-'){
            while(S1.top()=='+'||S1.top()=='-'||S1.top()=='*'||S1.top()=='/'){
                putinArray(S1.top());
                S1.pop();
            }
            S1.push(str[i]);
        }
        else if(str[i]==')'){
            while(S1.top()!='('){
                putinArray(S1.top());
                S1.pop();
            }
            S1.pop();
        }
        else{
            putinArray(str[i]);
        }
    }
    cout << endl;
    int value;
    for(int i=0;str_final[i]!=NULL;i++){
        if(str_final[i]=='+'){
            value=S2.top();
            S2.pop();
            value+=S2.top();
            //cout << value;
            //while(!S2.empty()){
                S2.pop();
            S2.push(value);
        //  cout << S2.top()<<endl;
            //cout << value;
        }
        else if(str_final[i]=='-'){
            value=S2.top();
            S2.pop();
            value=S2.top()-value;
           //cout << value;
            S2.pop();
            S2.push(value);
        //    cout << S2.top()<<endl;
            cout << value;
        }
        else if(str_final[i]=='*'){
            value=S2.top();
            S2.pop();
            value*=S2.top();
           // cout << value;
            S2.pop();
            S2.push(value);
          //  cout << S2.top()<<endl;
           // cout << value;
        }
        else if(str_final[i]=='/'){
            value=S2.top();
            S2.pop();
            value/=S2.top();
          //  cout << value;
            S2.pop();
            S2.push(value);
           // cout << S2.top() << endl;
           cout << value;
        }
        else{
            S2.push(str_final[i]);
        }
       // cout << value << endl;
    }
    return 0;
}
