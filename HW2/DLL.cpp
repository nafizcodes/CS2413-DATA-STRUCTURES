#include <iostream>

using namespace std;

class IntDLLNode{
    public:
    IntDLLNode(int d){
        data = i;
        nt = 0;
        prev = 0;
    }
    int info;
    IntSLLNode* nt;
    IntSLLNode* prev;
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
            temp-> nt = head;
            head = tail;
            temp-> prev = 0;

        }
    }

    void Insertlast(int i){
    IntDLLNode *temp = new IntDLLNode(i);

    if (head == 0){
        head = temp;
        tail = temp;
    }else{

        temp -> prev  = tail; 
        tail -> nt = temp;

    }

    }

};