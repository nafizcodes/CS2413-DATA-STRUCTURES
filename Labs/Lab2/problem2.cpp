#include<iostream>
using namespace std;

class BOOK{
    private:
    int BOOK_NO;
    char BOOKTITLE[20];
    float PRICE;

    float TOTAL_COST(int N){       
        //Name : TOTAL_COST
        //Input : number of books
        //output : total cost        
        //Purpose: Function to calculate the total cost of books
        float cost;
        cost = N * PRICE;
        return cost;
    }


    public:
    void INPUT(){
        //Name : INPUR
        //Input:void
        //Output:void
        //Purpose: asks for user input

        cout << "Enter the Book No: ";
        cin >> BOOK_NO;
        cout << "Enter the Book Title: ";
        cin >> BOOKTITLE;
        cout << "Enter the price of each copy: ";
        cin >> PRICE;
    }


    void PURCHASE(){
        //Name : PURCHASE
        //Input: void
        //Output: void
        //Purpose : Displays the cost
        int N;
        cout << "Enter the number of copies to be purchased: ";
        cin >> N;
    
        
        cout << "TOTAL COST($) IS: " << TOTAL_COST(N);


    }
};

int main(){
    
    BOOK mybook;

    mybook.INPUT();
    mybook.PURCHASE();


    return 0;
}