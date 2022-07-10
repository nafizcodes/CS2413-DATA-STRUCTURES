/*Author: Nafiz Imtiaz
Program : Sorting using different sort types
Course: CS 2413 HW 6
*/ 

#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

typedef struct queue *queuePointer;
struct queue{
    int val;
    queuePointer next;
};
queuePointer front[10], rear[10];

class Sort{
public:
    int Menu()
    {
        int choice;
        cout << "\n\t\t\t     M E N U\n\n";
        cout << "Input Data (0), Insertion Sort (1), Selection Sort (2),\n";
        cout << "Bubble Sort (3), Quick Sort (4), Radix Sort (5)\n";
        cout << "Exit Program (6)\n\n";
        cout << "\t\t\t Choose?  ";
        cin >> choice;
        return choice;
    }

    void InputData(vector<int> &arr)
    {
        int input;
        char ch;
        while (1)
        {   
            scanf("%d%c", &input, &ch);
            arr.push_back(input);
            if (ch == '\n')
                break;
        }
    }

    void displayArray(vector<int> &arr)
    {
        cout << endl;
        for (int x : arr)
            cout << x << " ";
        cout << endl;
    }

    void swap(int *x, int *y)
    {
        int t = *x;
        *x = *y;
        *y = t;
    }

    void insertion_sort(vector<int> &arr)
    {
        int temp, j;
        for (int i = 1; i < arr.size(); i++)
        {
            temp = arr.at(i);
            j = i - 1;
            while (j >= 0 && arr.at(j) > temp)
            {
                arr.at(j + 1) = arr.at(j);
                j = j - 1;
            }
            arr.at(j + 1) = temp;
        }
    }

    void selection_sort(vector<int> &arr)
    {
        int minimumInd, temp, n = arr.size();
        for (int i = 0; i < n - 1; i++)
        {
            minimumInd = i;
            for (int j = i; j < n; j++)
                minimumInd = arr.at(minimumInd) > arr.at(j) ? j : minimumInd;
            temp = arr.at(i);
            arr.at(i) = arr.at(minimumInd);
            arr.at(minimumInd) = temp;
        }
    }

     void bubble_sort(vector<int> &arr)
    {
        int n = arr.size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n - i - 1; j++)
                if (arr.at(j) > arr.at(j + 1))
                    swap(&arr.at(j), &arr.at(j + 1));
    }

    int partition(vector<int> &arr, int low, int high)
    {
        int pivot = arr.at(high);
        int i = (low - 1);

        for (int j = low; j <= high - 1; j++)
        {
            // If current element is smaller than or equal to pivot
            if (arr.at(j) <= pivot)
            {
                i++;
                swap(&arr.at(i), &arr.at(j));
            }
        }
        swap(&arr.at(i + 1), &arr.at(high));
        return i + 1;
    }

    void quick_sort(vector<int> &arr, int low, int high)
    {
        if (low < high)
        {
            int pi = partition(arr, low, high);
            quick_sort(arr, low, pi - 1);
            quick_sort(arr, pi + 1, high);
        }
    }

    void addQueue(int i, int value)
    {
        queuePointer tmp = (queuePointer)malloc(sizeof(*tmp));
        tmp->next = NULL;
        tmp->val = value;
        if (front[i])
            rear[i]->next = tmp;
        else
            front[i] = tmp;
        rear[i] = tmp;
    }

    int deleteQueue(int i)
    {
        int value;
        queuePointer tmp;
        tmp = front[i];
        // To check if queue is empty
        if (!tmp)
            return -1;
        value = tmp->val;
        front[i] = tmp->next;
        delete tmp;
        return value;
    }

    void radix_sort(vector<int> &arr)
    {
        int i, j, k, radix, digits, tmp;
        int maxVal = arr[0];

        // return if invalid size
        if (arr.size() < 1)
            return;

        for (int x : arr)
            maxVal = maxVal < x ? x : maxVal;

        // count number of digits
        for (radix = 1, digits = 0; maxVal >= radix; digits++, radix *= 10)
            ;

        for (i = 0, radix = 1; i < digits; i++, radix *= 10)
        {
            for (j = 0; j < arr.size(); j++)
                addQueue((arr[j] / radix) % 10, arr[j]);

            /* take them out from each queue to the original test array */
            for (j = 0, k = 0; j < 10; j++)
                for (tmp = deleteQueue(j); tmp != -1; tmp = deleteQueue(j), k++)
                    arr[k] = tmp;
        }
    }
};

int main()
{
    vector<int> arr;
    int choice;
    Sort a;

    while (1)
    {
        choice = a.Menu();
        switch (choice)
        {
        case 0:
            arr.clear();  //clears existing data in array
            cout << "Enter the sequence of data: ";
            a.InputData(arr);
            a.displayArray(arr);
            break;
        case 1:
            if (arr.size() == 0)
                cout << "Input Not Found !";
            else
            {
                a.insertion_sort(arr);
                cout <<"Insertion Sort: ";
                a.displayArray(arr);

            }
            break;
        case 2:
            if (arr.size() == 0)
                cout << "Input Not Found !";
            else
            {
                a.selection_sort(arr);
                cout <<"Selection Sort: "; 
                a.displayArray(arr);
            }
            break;
        case 3:
            if (arr.size() == 0)
                cout << "Input Not Found !";
            else
            {
                a.bubble_sort(arr);
                cout << "Bubble Sort: ";
                a.displayArray(arr);
            }
            break;
        case 4:
            if (arr.size() == 0)
                cout << "Input Not Found !";
            else
            {
                a.quick_sort(arr, 0, arr.size() - 1);
                cout << " Quick Sort: ";
                a.displayArray(arr);
            }
            break;
        case 5:
            if (arr.size() == 0)
                cout << "Input Not Found !";
            else
            {
                a.radix_sort(arr);
                cout << "Radix Sort: ";
                a.displayArray(arr);
            }
            break;
        case 6:
            cout << "Program Ends!" ;
            return 0;
            break;
        default:
            cout << "INVALID INPUT !\n";
        }
    }
    return 0;
}
