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









    /*****************************
            Home Work 6
    ****************************/
    //get index of given value
    int find(int val){
        int idx = 0;
        node* temp{head};
        while(temp){
            if(temp->data == val){
                return idx;
            }

            idx++,temp = temp->next;
        }
        //-1 if not found
        return -1;
    }

    //get the last index of given value
    int find_last(int val){
        int idx = 0,last = -1;
        node* temp{head};
        while(temp){
            if(temp->data == val){
                //keep the last index
                last = idx;
            }
            idx++,temp = temp->next;
        }
        //-1 if not found
        return last;
    }

    //give the target priority than its previous (swap them)
    int improved_find(int val){
        int idx = 0;
        node* curr{head},*prev{nullptr};

        while(curr){
            if(curr->data == val){
                //if it is the first element do not swap with previous(null)
                if(prev){
                    swap(prev->data,curr->data);
                    idx--;//the new index
                }
                return idx;
            }
            idx++,prev = curr,curr = curr->next;
        }
        //-1 if not exist
        return -1;
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
