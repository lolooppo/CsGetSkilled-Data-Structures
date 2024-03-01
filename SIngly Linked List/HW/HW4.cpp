#include<bits/stdc++.h>
using namespace std;

struct node{
    int data{0};
    node* next{nullptr};
    node(int data):data(data){}
};


class linkedList{
private:
    node *head{nullptr},*tail{nullptr};
    int length{0};

public:

    //add to the last
    void push_back(int val){
        //create a node with the given value
        node *temp = new node(val);

        //check if it is the first node
        if(!head){
            head = tail = temp;
        }
        else{
            tail->next = temp;
            tail = temp;
        }
        ++length;
    }

    //add to the first
    void push_front(int val){
        node *temp = new node(val);
        //check if it is the first node
        if(!head){
            head = tail = temp;
        }
        else{
            temp->next = head;
            head = temp;
        }
        ++length;
    }

    //delete the last element
    void pop_back(){
        //check if it is already empty
        if(!head)
            return;

        //keep the iterating with previous and current node to set the new tail
        node* prev{nullptr},* curr{head};
        while(curr){
            //check if we reached before the last
            if(!curr->next){
                tail = prev;
                if(tail){
                    tail->next = nullptr;
                }
                else{
                    tail = head = nullptr;
                }
                delete curr;
                break;
            }
            prev = curr;
            curr = curr->next;
        }
        length--;
    }

    //delete the first element
    void pop_front(){
        //check if it is already empty
        if(!head)
            return;

        node *dummy = head;
        head = head->next;
        delete dummy;
        //check if the list became empty
        if(!head){
            head = tail = nullptr;
        }
        length--;
    }









    /***********************
        Home Work 4
    ***********************/
    //left rotation
    void left_rotate(int k){
        //not useful rotations
        if(length<=1 or k%length==0)
            return;
        //remove all cycles
        k%=length;
        //create a cycle
        tail->next = head;

        node* nth = get(k);
        tail = nth;
        head = nth->next;
        tail->next = nullptr;
    }

    //right rotation
    void right_rotate(int k){
        //not useful rotations
        if(length<=1 or k%length==0)
            return;
        //remove all cycles
        k%=length;
        //create a cycle
        tail->next = head;

        node* nth1 = get_back(k+1) , *nth2 = get_back(k);
        head = nth2;
        tail = nth1;
        tail->next = nullptr;

    }


    //destructor
    ~linkedList(){
        node* temp{head};

        while(temp){
            node *dummy = temp;
            temp = temp->next;
            delete dummy;
        }
    }
};
