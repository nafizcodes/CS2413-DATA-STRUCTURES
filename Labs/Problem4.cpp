/*#include <iostream>

using namespace std;

int factorial(int n){                //USING NORMAL FOR LOOP WITH i
    int i;
    int result = 1;
    for (i=1; i<n+1 ; i++ ){
        result = result * i;
    }
    return result;
}

int main(){
    int num;
    cout << "Please enter the factorial number: ";
    cin >> num;
    int ans;
    ans = factorial(num);
    cout << "Factorial of " << num << " is " << ans << ".\n";
    return 0;
}
*/



//USING RECURSION
#include <iostream>
using namespace std;


int result;
int fact(int n){
    if (n == 0) {
        return 1;
    }
    else{
    result = n * fact(n-1);
    return result;
    }   
}

int main(){
    int num;
    cout << "Please enter the number of factorial: ";
    cin >> num;
    int ans;
    ans = fact(num);
    cout << "\nResult is " << ans << ".\n";
    return 0;
}

