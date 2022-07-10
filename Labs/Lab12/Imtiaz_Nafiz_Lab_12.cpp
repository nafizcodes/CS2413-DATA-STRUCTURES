#include <iostream>
using namespace std;

void bubbleSort(int arr[], int size);
void printArray(int arr[],int n);

int main() {
  int data[] = {4,7,1,9,2,5};
 
  int size = sizeof(data) / sizeof(data[0]);
  cout << "Unsorted array: ";
  printArray(data, size);
  cout << endl;

  bubbleSort(data , size);
  cout << "Sorted Array: ";
  printArray(data, size);
} 

void bubbleSort(int arr[], int size){
  int i,j;
  int temp;
  for (i = 0; i < size - 1; i++){
    for(j = 0; j < size - i - 1; j++)
    {
        if(arr[j]>arr[j+1])
        {
          temp = arr[j];
          arr[j] = arr[j+1];
          arr[j+1] = temp;
        }
    }
  } 
}

void printArray(int arr[], int n){
  for(int i=0; i<n ; ++i){
    cout << arr[i] << " ";
  }
}
