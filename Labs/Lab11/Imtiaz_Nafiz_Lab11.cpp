#include <iostream>
using namespace std;

void Mergesort(int array[], int l, int r);
void Merge(int array[], int l, int mid, int r);

int main() {
  int array[] = {5,3,7,1,4,10,2,6};

  int arr_size = sizeof(array) / sizeof(array[0]);

  cout<<"Unsorted array: "; 
  for (int i=0; i<arr_size; i++){
    cout<< array[i] << " "; 
  }
  cout<< endl;

  Mergesort(array,0,arr_size - 1);
  cout << "Sorted array: ";
  for (int i=0; i<arr_size; i++){
    cout << array[i] << ' ';

  }
  cout <<endl;
}

void Merge(int array[], int l, int mid, int r){
  int s1 = mid - l + 1;
  int s2 = r - mid;

  int a[s1];
  int b[s2];


  for (int i=0; i< s1; i++){
    a[i] = array[l+i];
  }
  
  for (int i=0; i< s2; i++){
    b[i] = array[mid + 1 + i];
  }

  int i=0;
  int j=0;
  int k=l;

  while(i<s1 && j<s2){
    if (a[i]<b[j]){
      array[k]=a[i];
      k++;
      i++;
    }
    else{
      array[k] = b[j];
      k++;
      j++;
    }
  }

  while(i<s1){
    array[k]=a[i];
      k++;
      i++;
  }

  while(j<s2){
    array[k] = b[j];
      k++;
      j++;
  }
}

void Mergesort(int array[], int l, int r){

  if (l<r){
    int mid = (l+r)/2;
    Mergesort(array, l, mid);
    Mergesort(array, mid+1, r);

    Merge(array, l, mid, r);
  }
}

