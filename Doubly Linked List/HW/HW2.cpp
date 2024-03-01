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
            Home Work 2
        ******************/

        //remove value
        void remove(int val){
            if(!head)
                return;
            node* temp{head};

            if(head->data == val){
                pop_front();
                return;
            }
            if(tail->data == val){
                pop_back();
                return;
            }

            while(temp){
                if(temp->data == val){
                    link(temp);
                    delete_node(temp);
                    length--;
                    return;
                }
                temp = temp->next;
            }

        }

        //remove position
        void remove_position(int pos){
            int cnt{1};
            node* temp{head};

            if(pos<0 or pos>length)
                return;
            if(pos==1){
                pop_front();
                return;
            }
            if(pos==length){
                pop_back();
                return;
            }

            while(temp){
                if(cnt==pos){
                    link(temp);
                    delete_node(temp);
                    break;
                }
                temp = temp->next;
                cnt++;
            }

            length--;
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
