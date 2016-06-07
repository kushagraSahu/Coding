//Intersection of 2 arrays!
#include<iostream>
using namespace std;
int main(){
    int arr1[10], arr2[10], intersection[20];
    int len1, len2;
    cout << "Enter length of 1st series." << endl;
    cin >> len1;
    cout << "Enter 1st series" << endl;
    int x;
    for(x=0;x<len1;x++){
        cin >> arr1[x];
    }
    cout << "Enter length of 2nd series." << endl;
    cin >> len2;
    cout << "Enter 2nd series" << endl;
    for(x=0;x<len2;x++){
        cin >> arr2[x];
    }
    int i, j, k;
    k=0;
    for(i=0;i<len1;i++){
        for(j=0;j<len2;j++){
            if(arr1[i]==arr2[j]){
                intersection[k]=arr1[i];
                k++;
            }
        }
    }
    cout << "Intersection of 2 arrays :";
    for(x=0;intersection[x]!= NULL;x++){
        cout << " " << intersection[x];
    }
    return 0;
}
