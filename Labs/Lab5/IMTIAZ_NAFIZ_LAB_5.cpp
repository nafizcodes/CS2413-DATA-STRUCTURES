#include <iostream>
#include <queue>

using namespace std;

int main(){
  int nofshares;
  int price;
  char input;
  int netGain = 0;
  int initialshareprice;

//Defining the queues
  queue <int> shareNum;
  queue <int> sharePrice;

while (input != 'e' ){
  //asking the user for input
  
  cout << endl<< "Enter 'b' to buy , 's' to sell,  'n' for net gain and 'e' to exit the program"<<endl;
  cin >> input ;


//switch cases for different options
  switch (input){
    case 'b':
    cout << "How many shares you want to buy: ";
    cin >> nofshares;

    cout << "Price of each share: $" ;
    cin >> price;

    shareNum.push(nofshares);
    sharePrice.push(price);
    break;

    case 's':
    cout << "How many shares you want to sell: ";
    cin >> nofshares;

    cout << "Price of each share: $" ;
    cin >> price;

    shareNum.push(-nofshares);
    sharePrice.push(price);
    break;

    case 'n':
      initialshareprice = sharePrice.front();
      while (!shareNum.empty()){
        netGain = netGain + (shareNum.front() * (initialshareprice - sharePrice.front()));
        shareNum.pop();
        sharePrice.pop();
      }
      cout << "Netgain is $" << netGain;
      break;

    case 'e':
    cout << "Program ends !" <<endl;
    break;

    default:
    cout << "Try again" <<endl ;
     cout << "Enter 'b' to buy , 's' to sell,  'n' to see net gain and 'e' to exit the program"<<endl;
     break;
  }

}
    return 0;
}