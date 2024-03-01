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

    //get the maximum
    int max(node* temp){
        if(!temp->next)
            return temp->data;
        return std::max(temp->data,max(temp->next));
    }

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

    //print forward
    void print(){
        //use dummy node to keep the original head
        node *temp = head;
        while(temp){
            cout<<temp->data<<" ";
            //move to the next node
            temp = temp->next;
        }
        cout<<"\n";
    }










    /*******************
        Home Work 1
    ********************/
    //get the maximum
    int max(){
        //check if it is empty;
        if(!head)
            return INT_MIN;
        node* temp{head};
        return max(temp);
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


int main(){

}
