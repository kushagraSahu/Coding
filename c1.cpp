#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int i,data1,data2,n,count2=1;
        long long int count=0;
        cin>>n;
        cin>>data1;
        for(i=1;i<n;i++){
            cin>>data2;
            if(data2>=data1){
                count2++;
            }
            else{
                count+=((count2)*(count2+1))/2;
                count2=1;
            }
            data1=data2;
        }
        count+=((count2)*(count2+1))/2;
        cout<<count<<endl;
    }
    return 0;

}
