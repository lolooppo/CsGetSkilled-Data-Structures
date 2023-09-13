struct node{
    int data{0};
    node* next{nullptr};
    node(int data):data(data){}
};

class linkedList{
private:
    node *head{nullptr},*tail{nullptr};
    int length{0};

    //print reversed in a recursive manner
    void print_reverse(node *temp){
        if(temp==nullptr)
            return;
        print_reverse(temp->next);
        cout<<temp->data<<" ";
    }

    //get the maximum
    int max(node* temp){
        if(!temp->next)
            return temp->data;
        return std::max(temp->data,max(temp->next));
    }

    //get the minimum
    int min(node* temp){
        if(!temp->next)
            return temp->data;
        return std::min(temp->data,min(temp->next));
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

    //return the node of the given position
    node* get(int pos){
        node* temp = head;
        int cnt{1};

        while(temp){
            if(cnt == pos)
                return temp;
            cnt++;
            temp = temp->next;
        }
        //not found
        return nullptr;
    }

    //return the node of the given position from back
    node* get_back(int pos){
        int cnt{1};
        node* temp{head};

        while(temp){
            if(length-cnt+1 == pos){
                return temp;
            }
            cnt++,temp = temp->next;
        }
        //not found
        return nullptr;
    }

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

    //reverse
    void reverse(){
        //no need to reverse one node
        if(length<=1)
            return;

        tail = head;
        node* prev = head;
        head = head->next;

        while(head){
            node* nxt = head->next;
            head->next = prev;
            prev = head;
            head = nxt;
        }

        head = prev;
        tail->next = nullptr;
        return;
    }

    //get the maximum
    int max(){
        //check if it is empty;
        if(!head)
            return INT_MIN;
        node* temp{head};
        return max(temp);
    }

    //get the minimum
    int min(){
        //check if it is empty;
        if(!head)
            return INT_MAX;
        node* temp{head};
        return min(temp);
    }

    //sort elements o(n) time- o(n) memory
    void sort(){
        priority_queue<int,vector<int>,greater<int>>pq;
        node* temp{head};

        while(temp){
            pq.push(temp->data);
            temp = temp->next;
        }

        temp = head;
        while(temp){
            temp->data = pq.top();
            pq.pop();
            temp = temp->next;
        }
    }

    //remove duplicates
    void unique(){
        map<int,bool>mp;
        node* temp{head};
        int cnt{1};

        while(temp){
            if(mp[temp->data]){
                temp = temp->next;
                Delete_pos(cnt);
            }
            else{
                mp[temp->data] = true;
                cnt++;
                temp = temp->next;
            }
        }
    }

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

    //calling parameterized reverse print function
    void print_reverse(){
        node *temp = head;
        //call the function with dummy head
        print_reverse(temp);
        cout<<"\n";
    }

    //get the actual length
    int size(){
        return length;
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