// objects using English measurements
#include <iostream>
using namespace std;
class Distance                    //English Distance class
{
private:
    int feet;
    float inches;
public:
    Distance() : feet(0),inches(0){//Constructor (no arguments)
        cout << "This is the constructor with no arguments!" << endl;
    }
    Distance(int ft,float in) : feet(ft),inches(in){//Constructor(two arguments)
        cout << "Object is being created however,member data have been assigned the values(int the initializer list before this constructor started to execute!" << endl;
    }
    void getdist(){              //get length from user
        cout << "Enter feet: " << endl;
        cin >> feet;
        cout << "Enter inches: " << endl;
        cin >> inches;
    }
    void showdist(){             //display distance
        cout << feet << "\'-" << inches << "\"" << endl;
    }
    void add_dist(Distance, Distance);//Declaration
};
void Distance::add_dist(Distance d4,Distance d5){
    inches=d4.inches+d5.inches;
    if(inches>=12.0){
        inches -=12.0;
        feet++;
    }
    feet+=d4.feet+d5.feet;
    d4.feet=1000;
}
int main(){
    Distance d1,d2(11,6.25);
    Distance d3;
    d1.getdist();
    d3.add_dist(d1,d2);
    cout << "Distance object d1 : ";
    d1.showdist();
    cout << "Distance object d2 : ";
    d2.showdist();
    cout << "Distance object d3 : ";
    d3.showdist();
    return 0;
}
