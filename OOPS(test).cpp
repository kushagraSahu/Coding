#include<iostream>
using namespace std;
//class Box{
//    int breadth;
//    public:
//    int length;
//    int height;
//    int getbreadth(){
//        return breadth;
//    }
//    void setlength(int len){
//        length=len;
//    }
//    void setbreadth(int bre){
//        breadth=bre;
//    }
//};
//int main(){
//    Box B1;
//    B1.length=5;
//    cout << B1.length << endl;
//    B1.setbreadth(2);
//    cout << B1.getbreadth();
//    return 0;
//}
//class Line{
//    int length;
//public:
//    void setlength(int len){
//        length=len;
//    }
//    int getlength(){
//        return length;
//    }
//    Line() : length(0){//Parameterized constructor.
//        cout << "Object is being created!" << endl;
////        length=len;
//        cout << "Its length is " << length << endl;
//    }
//    ~Line(){
//        cout << "Object is being deleted!" << endl;
//    }
//};
//int main(){
//    cout << "Object going to be defined in line 42" << endl;
//    Line L;
//    L.setlength(20);
//    cout << "New length of line : " << L.getlength() << endl;
//    return 0;
//}
class Line{
    int *ptr;
public:
    Line(int length){
        cout << "Allocating memory in normal constructor" << endl;
        ptr=new int;
        ptr=length;
    }
    Line(const Line &obj){
        cout << "Allocating new memory in copy constructor" << endl;
        ptr=new int;
        *ptr=*obj.ptr;
    }
    void getlength(){
        return *ptr;
    }
};
