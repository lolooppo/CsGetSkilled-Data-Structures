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










    /***************************
            Home Work 7
    ***************************/
    //delete the first occuranc of given value
    void Delete(int val){
        node* curr{head},*prev{nullptr};
        int cnt = 1;

        while(curr){
            if(curr->data == val){
                if(cnt==1){
                    pop_front();
                    return;
                }
                else{
                    prev->next = curr->next;
                    delete curr;
                    //check if we got a new tail as prev
                    if(!prev->next){
                        tail = prev;
                    }
                    --length;
                    return;
                }
            }
            cnt++,prev = curr,curr = curr->next;
        }
    }

    //delete node of given position
    void Delete_pos(int pos){
        if(pos>length or length<1)
            return;

        if(pos==1){
            pop_front();
            return;
        }else if(pos==length){
            pop_back();
            return;
        }

        int cnt = 2;
        node* curr{head->next},*prev{head};
        while(curr){
            if(cnt==pos){
                prev->next = curr->next;
                delete curr;
                break;
            }
            cnt++,prev = curr,curr = curr->next;
        }
        length--;
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
