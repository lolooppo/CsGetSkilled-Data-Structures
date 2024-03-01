#include<bits/stdc++.h>
using namespace std;

/*****************************************************************/
/*                 Author : Alaa Omran                           */
/*                 Object : Doubly Linked List                   */
/*****************************************************************/

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

        //sort
        void sort(){
            if(!head)
                return;
            priority_queue<int,vector<int>,greater<int>>p;
            node* temp{head};
            while(temp){
                p.push(temp->data);
                temp = temp->next;
            }

            temp = head;
            while(temp){
                temp->data = p.top();
                temp = temp->next;
                p.pop();
            }
        }

        //remove duplicate
        void unique(){
            if(!head or !head->next)
                return;

            node* temp{head};
            map<int,bool>mp;
            while(temp){
                if(mp[temp->data] == true){
                    node* New = temp->next;

                    if(temp==tail){
                        pop_back();
                        return;
                    }

                    link(temp);
                    delete_node(temp);
                    temp = New;
                    length--;
                }else{
                    mp[temp->data] = true;
                    temp = temp->next;
                }
            }
        }

        //insert at index
        void insert(int idx,int val){
            if(idx<0 or idx>=length)
                return;

            if(idx==0){
                push_front(val);
                return;
            }
            if(idx==length-1){
                push_back(val);
                return;
            }

            int index{0};
            node* temp{head},*New = new node(val);
            while(temp){
                if(index==idx){
                    temp->prev->next = New;
                    temp->next->prev = New;
                    New->next = temp;
                    New->prev = temp->prev;
                    break;
                }
                index++;
                temp = temp->next;
            }
            length++;
        }

        //print forward
        void print(){
            node* temp{head};

            while(temp){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<"\n";
        }

        //print reverse
        void print_reverse(){
            node* temp{tail};

            while(temp){
                cout<<temp->data<<" ";
                temp = temp->prev;
            }
            cout<<"\n";
        }

        //size
        int size(){
            return length;
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
