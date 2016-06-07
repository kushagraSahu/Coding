#include<iostream>
using namespace std;
class Distance{
    int feet;
    float inches;
public:
    Distance() : feet(0),inches(0.0){
        cout << "1st constructor called!" << endl;
    }
    Distance(int ft, float in): feet(ft),inches(in){
        cout << "2nd constructor called!" << endl;
    }
    void getdist(){
        cout << "Enter feet: ";
        cin >> feet;
        cout << "Enter inches: ";
        cin >> inches;
    }
    void show_dist(){
        cout << feet << "\'-" << inches << endl;
    }
    Distance operator + (Distance d) const{
        int ft=feet+d.feet;
        float in=inches+d.inches;
        if(in>=12.0){
            in-=12.0;
            ft++;
        }
        return Distance(ft,in);
    }
    ~Distance(){
        cout << "Destructor called!" << endl;
    }
};
int main(){
    Distance d1(11,6.25),d2;
    d2.getdist();
    Distance d3=d1+d2;
    d3.show_dist();
    Distance d4=d1+d2+d3;
    d1.show_dist();
    d2.show_dist();
    d3.show_dist();
    d4.show_dist();
}
