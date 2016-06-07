#include<iostream>
using namespace std;
static int dec_row = 2;
int main(){
    int max_stars,current_row;
    current_row = 1;
    cout << "Enter max stars" << endl;
    cin >> max_stars;
    int n;
    n=(max_stars+1)/2-1;
    int num_stars, stars_printed, num_spaces, spaces_printed;
    int x;
    for(x=0;x<max_stars;x++){
        cout << "*";
    }
    cout << endl;
    while(current_row<=max_stars-2){
        if(current_row<=n){
            num_stars = n-current_row+1;
            for(stars_printed=0;stars_printed<num_stars;stars_printed++){
                cout << "*";
            }
            num_spaces = max_stars - 2*(n-current_row+1);
            for(spaces_printed=0;spaces_printed<num_spaces;spaces_printed++){
                cout << " ";
            }
            num_stars = n-current_row+1;
            for(stars_printed=0;stars_printed<num_stars;stars_printed++){
                cout << "*";
            }
        }
        else if(current_row>n){
            num_stars = dec_row;
            for(stars_printed=0;stars_printed<num_stars;stars_printed++){
                cout << "*";
            }
            num_spaces = max_stars - 2*(dec_row);
            for(spaces_printed=0;spaces_printed<num_spaces;spaces_printed++){
                cout << " ";
            }
            num_stars = dec_row;
            for(stars_printed=0;stars_printed<num_stars;stars_printed++){
                cout << "*";
            }
            dec_row++;
        }
        current_row++;
        cout << endl;
    }
    for(x=0;x<max_stars;x++){
        cout << "*";
    }
    return 0;
}
