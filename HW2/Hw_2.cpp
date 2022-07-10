#include <iostream>
using namespace std;




// To print out the menu
void menu_print(){   
    cout << "               M E N U" << endl <<
        "SLL: IH(0), IT(1), DH(2), DT(3), SD(4), PS(5)" << endl <<
        "DLL: IH(6), IT(7), DH(8), DT(9), SD(10), PD(11)"<< endl <<
        "Exit Program (12)" << endl <<
        "\n\n               Choose ?                   ";
    } 



class IntSLLNode {
    public:
    IntSLLNode() {
    next = 0;
    }
    IntSLLNode(int i, IntSLLNode *in = 0){
    info = i; next = in;
    }
    int info;
    IntSLLNode *next;
};

void Insert_head(IntSLLNode** head_ref, int new_data){
    /* 1. allocate node */
    IntSLLNode* new_node = new IntSLLNode();
 
    /* 2. put in the data */
    new_node->info = new_data;
 
    /* 3. Make next of new node as head */
    new_node->next = (*head_ref);
 
    /* 4. move the head to point to the new node */
    (*head_ref) = new_node;
}


// Given a reference (pointer to pointer) to the head 
// of a list and an int, appends a new node at the end
void Intsert_tail( IntSLLNode** head_ref, int new_info) 
{ 
   
    // 1. allocate node
    IntSLLNode* new_node = new IntSLLNode();
   
    // Used in step 5
    IntSLLNode *last = *head_ref;
   
    // 2. Put in the data
    new_node->info = new_info; 
   
    // 3. This new node is going to be 
    // the last node, so make next of 
    // it as NULL
    new_node->next = NULL; 
   
    // 4. If the Linked List is empty,
    // then make the new node as head
    if (*head_ref == NULL) 
    { 
        *head_ref = new_node; 
        return; 
    } 
   
    // 5. Else traverse till the last node
    while (last->next != NULL) 
        last = last->next; 
   
    // 6. Change the next of last node
    last->next = new_node; 
    return; 
} 
 
//deleteHead function
/* Link list node */
/* Function to remove the first node
   of the linked list */
void removeFirstNode()
{
    if (head == 0)
        cout << "List is empty";
    else if (head == tail){
        delete head;
        head = 0;
        tail = 0;
    }
    else {

        IntSLLNode* temp = IntSLLNode;
        head = head->next;
 
    delete temp;
 

    }
    // Move the head pointer to the next node
   
    return head;
}


//deleteTail function

//print

//search and delete function



int main2(){

    menu_print();

    return 0;
}