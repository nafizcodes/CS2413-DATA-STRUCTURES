/* #include <iostream> 

int main(){   //int because we returning 0
    std:: cout << "Hello World!";    //std::cout   is a function that is in iostream
return 0;   
}
*/

// function example

#include <iostream>
using namespace std;
int addition(int a, int b)
{
int r;
r = a + b;
return r;
}
int main()
{
int z;
z = addition(5, 3);
cout << "The result is " << z;
return 0;
}
