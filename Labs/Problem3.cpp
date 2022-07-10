#include <iostream>

using namespace std;

int main(){
    int n;
    cout << "Please enter the number upto which sum is required: ";
    cin >> n ;
    int sum = 0 ;
    int i;
    for (i=0 ; i<n ; i++){
        sum = sum + i  ;
    }
    cout << "Sum of series is " << sum << ".\n";

    return 0;
}

