#include<iostream>
using namespace std;
class Counter{
    int count;
public:
    Counter() : count(0){
        cout << "1st constructor called initializing count to 0!" << endl;
    }
    Counter(int c) : count(c){
        cout << "2nd constructor called setting count to integer sent in argument!" << endl;
    }
    void get_count()const {
        cout << count << endl;
    }
//    void operator ++(){
//        cout << "Called void return type function!" << endl;
//        ++count;
//    }
    Counter operator ++ (){//Prefix Notation. For Postfix notation, we use Counter operator ++(int){}
        cout << "Called Counter return type function for PREFIX!" << endl;
        return Counter(++count);
    }
    Counter operator ++ (int){
        cout << "Called Counter return type function for POSTFIX!" << endl;
        return Counter(count++);
    }
    ~Counter(){
        cout << "Destructor Called!" << endl;
    }
};
int main(){
    Counter c1,c2;
    c1.get_count();
    c2.get_count();
    ++c1;
    c1.get_count();
    c2=++c1;
    c1.get_count();
    c2.get_count();
    c2=c1++;//Here, c1 is incremented to 3, but c2 is assigned the value of c1 before it is incremented, so c2 retains the value 2.
    c1.get_count();
    c2.get_count();
    return 0;
}
