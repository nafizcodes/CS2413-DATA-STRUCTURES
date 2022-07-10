/*Author: Nafiz Imtiaz
CS2413course Homework 2
Filename: Imtiaz_Nafiz_HW_2.cpp
Program : Menu driven program with SLL and DLL 
 */

#include <iostream>

using namespace std;

//defining the class of the single linked list Node
class IntSLLNode{
    public:
    IntSLLNode(int i){
        info = i;
        next = 0;
    }
    int info;
    IntSLLNode* next;
};

//defining the class of single list node with functions
class IntSLL{
    public:
    IntSLLNode *head;
    IntSLLNode *tail;
    IntSLL(){
        head = 0;
        tail = 0;
    }

//Function for inserting node at the head position
    void Inserthead(int i){
        IntSLLNode *t = new IntSLLNode(i);
        if(head == 0){
            head = t;
            tail = t;
        }else{
            t->next = head;
            head = t;
        }
    }

//Function for deleting the node at the head position
    void Deletehead(){
        if(head == 0){
            cout << "empty List" << endl;
        }
        else if(head == tail){
            delete head;
            head = 0;
            tail = 0;
        }
        else{
            IntSLLNode *t = head;
            head = head->next;
            delete t;
        } 
    }


//Function for inserting the node at the tail position
    void Inserttail(int i){
        IntSLLNode *t= new IntSLLNode(i);
        if(head == 0){
            head = t;
            tail = t;
        }
       
        else{
            tail->next =  t;
            tail = t;
        }
        
    }


//Function for deleting the node at the tail position
    void Deletetail(){
        if(head == 0){
            cout << "empty List" << endl;
        }
        else if(head == tail){
            delete head;
            head = 0;
            tail = 0;
        }
        else{
            IntSLLNode *t = head;
            while(t->next != tail){
                t= t->next;
            }
            delete tail;
            tail = t;
            tail->next = 0;

        } 

    }


//Function for searching the target node and deleting it
    void searchanddelete(int i){
        int found = 0;
        IntSLLNode *t = head;
        while(t != 0){
            if(t->info == i){
                found = 1;
            }
            t = t->next;
        }
        if(found == 0){
            cout <<"Not found" << endl;

        }
        else{
            IntSLLNode *t = head->next;
            IntSLLNode *prev = head;
            while(t->info != i){
                t= t->next;
                prev = prev->next;
            }
            prev->next = t->next;
            delete t;

        }
        
    }

    
//Function for printing the single linked list
    void printList(){
        IntSLLNode *t = head;
        while(t != 0){
            cout <<t->info <<"  ";
            t = t->next;
        }
    }


};


// Defining the class of the Double Linked List Node
class IntDLLNode{
    public:
    IntDLLNode(int i){
        info = i;
        next = 0;
        prev = 0;
    }
    int info;
    IntDLLNode* next;
    IntDLLNode* prev;
};


//Defining the class of the Double linked List with functions
class IntDLL{
    public:
    IntDLLNode *head;
    IntDLLNode *tail;
    
    IntDLL(){
        head = 0;
        tail = 0;
    }


//Function for inserting node at the head position
    void Inserthead(int i){
        IntDLLNode *temp = new IntDLLNode(i);
        
        if(head == 0){
            head = temp;
            tail = temp;
        }else{
            head -> prev = temp;
            temp -> next = head;
            head = temp;
        }
    }


//Function for inserting the node at the tail position
    void Inserttail(int i){
    IntDLLNode *temp = new IntDLLNode(i);

    if (head == 0){
        head = temp;
        tail = temp;
    }else{
        temp -> prev  = tail; 
        tail -> next = temp;
        tail = temp;
    }
  }


//Function for deleting the node at the head position
    void Deletehead(){
        if (head == 0){
            cout << "Empty list" << endl;
        }
        else if (head == tail){
            delete head; 
            head = 0;
            tail = 0;
        }else {
            IntDLLNode *temp = head;
            head = head -> next;
            head -> prev = 0;
            delete temp;
        }

    }


//Function for deleting the node at the tail position
    void Deletetail(){
        if (head == 0){
            cout << "Empty List" << endl;
        }
        else if (head == tail){
            delete head;
            head = 0;
            tail = 0;
        }else{
            IntDLLNode *temp = tail;
            tail = temp -> prev ;
            tail -> next = 0;
        }
    }
    


//Function for printing the Double linked list starting from head
    void printListDLLForward(){
        IntDLLNode *t = head;
        while(t != 0){
            cout <<t->info <<"  ";
            t = t->next;
        }
    }


// Alternative function for printing the Double Linked list backwards
      void printListDLLBack(){    
        IntDLLNode *t = tail;
        while(t != 0){
            cout << t->info ;
            t = t->prev;
        }
    }


//Function for searching and deleting the node 
    void searchanddelete(int i){
        
        int found = 0;
        IntDLLNode *t = head;
        while ( t != 0){
            if ( t ->info == i){
                found = 1;
                break;
            }
            t = t-> next;
        }
        if (found == 0){
            cout << " Not found " << endl;            
        }else{
            if(t == head){
                Deletehead();
            }else if ( t == tail){
                Deletetail();
            }else{
                t->prev-> next = t-> next;
                t->next-> prev = t -> prev;
                delete t;
            }

        }
    }   
    
}; 


//Driver Function
int main(){
    IntDLL *l2 = new IntDLL(); 
    IntSLL *l1 = new IntSLL();

    cout << "\n\n               M E N U" << endl <<
        "SLL: IH(0), IT(1), DH(2), DT(3), SD(4), PS(5)" << endl <<
        "DLL: IH(6), IT(7), DH(8), DT(9), SD(10), PD(11)"<< endl <<
        "Exit Program (12)" << endl <<
        "\n               Choose? ";
    
    int value;
    cin >>value;
    int data;
  
    while (value != 12){
    
    //switch statements for each of the possible cases
    switch(value) {
    case 0 :
        cout << " Insert the number : ";
        cin >> data;
        l1->Inserthead(data);
        break; 
    case 1:
        cout << " Insert the number: ";
        cin >> data;
        l1->Inserttail(data);
        break; 
    case 2 :
        l1->Deletehead();
        break; 
    case 3:
        l1->Deletetail();
        break; 
    case 4 :
        cout << " Integer to be deleted: " ;
        cin >> data;
        l1->searchanddelete(data);
        break; 
    case 5 :
        l1->printList();
        break; 
    case 6 :
        cout << " Insert the number: ";
        cin >> data;
        l2->Inserthead(data);
        break; 
    case 7 :
        cout << " Insert the number: " ;
        cin >> data;
        l2->Inserttail(data);
        break; 
    case 8 :
        l2->Deletehead();
        break; 
    case 9 :
        l2->Deletetail();
        break; 
    case 10 :
        cout << " Integer to be deleted: " ;
        cin >> data;
        l2->searchanddelete(data);
        break;
    case 11 :
        l2->printListDLLForward();
        break; 
    case 12 :
        break; 
    default : 
        cout << "Enter the data again"<< endl;
        break;
    }   
    
    cout << "\n\n             M E N U" << endl <<
        "SLL: IH(0), IT(1), DH(2), DT(3), SD(4), PS(5)" << endl <<
        "DLL: IH(6), IT(7), DH(8), DT(9), SD(10), PD(11)"<< endl <<
        "Exit Program (12)" << endl <<
        "\n               Choose?  ";
      
    
    cin >>value;
      
    }
    cout << "END" <<endl;
   
    return 0;
}
