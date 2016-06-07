//Implement 2 Stacks in an array.
#include<iostream>
using namespace std;
static int top1=5;
static int top2=4;
void pushinStack1(int arr[],int value){
    top1--;
    if(top1==-1){
        cout << "Stack1 OVERFLOW!" << endl;
    }
    else{
        arr[top1]=value;
    }
    return;
}
void pushinStack2(int arr[],int value){
    top2++;
    if(top2==10){
        cout << "Stack2 OVERFLOW!" << endl;
    }
    else{
        arr[top2]=value;
    }
    return;
}
void popfromStack1(int arr[]){
    if(top1==4){
        cout << "Stack1 UNDERFLOW!" << endl;
    }
    else{
        top1++;
    }
}
void popfromStack2(int arr[]){
    if(top2==5){
        cout << "Stack2 UNDERFLOW!" << endl;
    }
    else{
        top2--;
    }
}
int gettop1(int arr[]){
    return arr[top1];
}
int gettop2(int arr[]){
    return arr[top2];
}
int main(){
    int arr[10]={0},choice1,value;
    char choice2;
    while(1){
        cout << "Choose: \n1.Push in Stack1\n2.Pop from Stack1\n3.Push in Stack2\n4.Pop from Stack2\n5.Get Top1\n6.Get Top2" << endl;
        cin >> choice1;
        switch(choice1){
        case 1:
            cout << "Enter value : ";
            cin >> value;
            pushinStack1(arr,value);
            break;
        case 2:
            popfromStack1(arr);
            break;
        case 3:
            cout << "Enter value : ";
            cin >> value;
            pushinStack2(arr,value);
            break;
        case 4:
            popfromStack2(arr);
            break;
        case 5:
            cout << gettop1(arr) << endl;
            break;
        case 6:
            cout << gettop2(arr) << endl;
            break;
        }
        cout << "Want to continue? y/n? : ";
        cin >> choice2;
        if(choice2=='n'){
            break;
        }
    }
    return 0;
}
