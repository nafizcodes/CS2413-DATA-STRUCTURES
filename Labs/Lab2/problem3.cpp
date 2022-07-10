#include <iostream>
using namespace std;

class Distance{
    public:
        int feet;
        float inches;
    public:
        void set (int f, float i){
        //Name : set
        //Input: int f, float i
        //Output: void
        //Purpose: sets value to the objects
            feet = f;
            inches = i;
        }

        Distance add(Distance  newd){
        //Name : Distance
        //Input: Distance newd
        //Output: d
        //Purpose: add new distance to current distance
            Distance d;

            d.feet = feet + newd.feet;
            d.inches = inches + newd.inches;

            return d;
        }

        void disp(void){
        //Name : disp
        //Input: void
        //Output: void
        //Purpose: displays the distances 
            cout << "\nDistance is " << feet << "feet  " << inches << "inches" <<".\n";
        }
};

int main(){
    //driver function

    Distance d1, d2, dsum; 

    d1 = {15, 3.65};
    d2 = {13, 2.04}; 

    dsum = d1.add(d2);

    cout << "\ndistance 1:";
    d1.disp();
    cout << "\ndistance 2:";
    d2.disp();
    cout << "\ndistance_total:";
    dsum.disp();

    return 0;
}


