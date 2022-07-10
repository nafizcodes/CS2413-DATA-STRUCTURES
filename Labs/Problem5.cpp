#include <iostream>
using namespace std;

int main(){
    int array[5];
    int i;
    int result = 0; 
    for ( i=0 ; i<5; i++ ){
        cout << "Please enter the number" << i+1 << ":";
        cin >> array[i];
        result += array[i];
    }
    cout << "Result is " << result << ".\n" ;
    return 0;
}