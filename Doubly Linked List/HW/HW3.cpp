#include<bits/stdc++.h>
using namespace std;

struct node{
    node* next{nullptr},* prev{nullptr};
    int data{0};
    node(int data):data(data){}
};

class DoublyLinkedList{
    private:
        int length{0};
        node *head{nullptr} , *tail{nullptr};

        void delete_node(node* temp){
            delete temp;
        }

        void link(node* temp){
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            //delete temp;
        }

    public:
        //constructor
        DoublyLinkedList(){}

        //add to last
        void push_back(int val){
            node* temp = new node(val);
            if(!head){
                head = tail = temp;
            }else{
                tail->next = temp;
                temp->prev = tail;
                tail = temp;
            }

            length++;
        }

        //add to first
        void push_front(int val){
            node* temp = new node(val);
            if(!head){
                head = tail = temp;
            }else{
                temp->next = head;
                head->prev = temp;
                head = temp;
            }

            length++;
        }

        //remove from back
        void pop_back(){
            if(!head)
                return;

            node* temp{tail->prev};
            delete tail;
            tail = temp;
            if(tail)
                tail->next = nullptr;
            else
                head = tail = nullptr;

            length--;
        }

        //remove from front
        void pop_front(){
            if(!head)
                return;

            node* temp{head};

            head = head->next;
            delete temp;

            if(head)
                head->prev = nullptr;
            else
                head = tail = nullptr;

            length--;
        }









        /******************
            Home Work 3
        ******************/
        //reverse
        void reverse(){
            if(!head or !head->next)
                return;
            node* temp1{head},*temp2{head->next};
            while(temp2){
                swap(temp1->next,temp1->prev);
                temp1 = temp2;
                temp2=temp2->next;
            }
            swap(temp1->next,temp1->prev);
            head = temp1;
        }


        //destructor
        ~DoublyLinkedList(){
            node* temp{head};
            while(temp){
                node* dummy{temp};
                temp = temp->next;
                delete dummy;
            }
        }
};
