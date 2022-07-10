#include <iostream>

using namespace std;

class IntSLLNode{
    public:
    IntSLLNode(int i){
        info = i;
        next = 0;
    }
    int info;
    IntSLLNode* next;
};

class IntSLL{
    public:
    IntSLLNode *head;
    IntSLLNode *tail;
    IntSLL(){
        head = 0;
        tail = 0;
    }
    void Inserthead(int i){
        IntSLLNode *t = new IntSLLNode(i);
        //IntSLLNode *t1 =(IntSLLNode*) malloc(sizeof(IntSLLNode));
        if(head == 0){
            head = t;
            tail = t;
        }else{
            t->next = head;
            head = t;
        }
    }

    void printList(){
        IntSLLNode *t = head;
        while(t != 0){
            cout << t->info << endl;
            t = t->next;
        }
    }


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
};


// Double Linked Lists
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

class IntDLL{
    public:
    IntDLLNode *head;
    IntDLLNode *tail;
    
    IntDLL(){
        head = 0;
        tail = 0;
    }

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
    

    //prints forward
    void printListDLLForward(){
        IntDLLNode *t = head;
        while(t != 0){
            cout << t->info << endl;
            t = t->next;
        }
    }


    // prints backwards
      void printListDLLBack(){    
        IntDLLNode *t = tail;
        while(t != 0){
            cout << t->info << endl;
            t = t->prev;
        }
    }


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
                cout << "Is deleted:" << t->info <<endl;
                t->prev-> next = t-> next;
                t->next-> prev = t -> prev;
                delete t;
            }

        }
    }   
    
}; 

int main(){
    IntDLL *l2 = new IntDLL(); 
    IntSLL *l1 = new IntSLL();

    cout << "               M E N U" << endl <<
        "SLL: IH(0), IT(1), DH(2), DT(3), SD(4), PS(5)" << endl <<
        "DLL: IH(6), IT(7), DH(8), DT(9), SD(10), PD(11)"<< endl <<
        "Exit Program (12)" << endl <<
        "\n               Choose? ";
    int value;
    cin >>value;
    int data;
    

    while (value != 12){
    
    switch(value) {
    case 0 :
        cout << " Insert: ";
        cin >> data;
        l1->Inserthead(data);
        break; //optional
    case 1:
        cout << " Insert: ";
        cin >> data;
        l1->Inserttail(data);
        break; //optional
    case 2 :
        l1->Deletehead();
        break; //optional
    case 3:
        l1->Deletetail();
        break; //optional
    case 4 :
        cout << " Insert: " ;
        cin >> data;
        l1->searchanddelete(data);
        break; //optional
    case 5 :
        l1->printList();
        break; //optional
    case 6 :
        cout << " Insert: " ;
        cin >> data;
        l2->Inserthead(data);
        break; //optional
    case 7 :
        cout << " Insert: " ;
        cin >> data;
        l2->Inserttail(data);
        break; //optional
    case 8 :
        l2->Deletehead();
        break; //optional
    case 9 :
        l2->Deletetail();
        break; //optional
    case 10 :
        cout << " Insert: " ;
        cin >> data;
        l2->searchanddelete(data);
        break; //optional
    case 11 :
        l2->printListDLLForward();
        break; //optional
    case 12 :
        break; 
    default : //Optional
        cout << "Enter the data again"<< endl;
        break;
    }   
    
    cout << "               M E N U" << endl <<
        "SLL: IH(0), IT(1), DH(2), DT(3), SD(4), PS(5)" << endl <<
        "DLL: IH(6), IT(7), DH(8), DT(9), SD(10), PD(11)"<< endl <<
        "Exit Program (12)" << endl <<
        "\n               Choose?  ";
      
    
    cin >>value;
      
    }
    cout << "END" <<endl;
   
    return 0;
}
