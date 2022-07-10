#include <iostream>
using namespace std;

class Student{
    private:
    int admno;
    char sname[20];
    float eng, math, science, total;
    
    float ctotal(){
        //Name : ctotal
        //Input: void
        //Output: sum
        //Purpose: calculate the sum of the scores
        float sum;
        sum = eng + math + science ;
        return sum;
    }
    
    public:
        float t;
    void takeData(){
        //Name : takeData
        //Input: void
        //Output: void
        //Purpose: To take in data from user
        cout << "Enter the admno: " ;
        cin >> admno;
        cout << "Enter the name: ";
        cin >> sname ;
        cout << "Enter the eng score: " ;
        cin >> eng;
        cout << "Enter the math score: ";
        cin >> math; 
        cout << "Enter the science score: ";
        cin >> science; 

        
        
        t = ctotal();
        
    }



    void showData(){
        //Name : showData
        //Input: void
        //Output: void
        //Purpose: To show the details of the student
        cout << "\n\nStudent Deatils"<< ":\n";
        cout << "Admno is " << admno << ".\n" ;
        cout << "Name is "  << sname << ".\n";
        cout << "Eng score is " << eng << ".\n";
        cout << "Math score is " << math << ".\n";
        cout << "Science score is " << science << ".\n";
        cout << "Total is " << t << ".\n";
    }

};

int main(){
    //driver function
    Student mystudent; 
    
    mystudent.takeData();
    mystudent.showData();

return 0;
}