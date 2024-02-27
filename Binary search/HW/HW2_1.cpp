#include <bits/stdc++.h>
using namespace std;

// tree node
struct node{
    int data;
    node *left{nullptr} , *right{nullptr};
    node(int data):data(data){}
};


//tree class
class binary_search_tree{
private:
    node* root{nullptr};

    //print sorted
    void print(node* temp){
        if(temp->left)
            print(temp->left);
        cout<<temp->data<<" ";
        if(temp->right)
            print(temp->right);
    }

    //add to the tree
    void add(int data,node* temp){
        if(data<temp->data){
            if(temp->left){
                add(data,temp->left);
            }else{
                temp->left = new node(data);
            }
        }else{
            if(temp->right){
                add(data,temp->right);
            }else{
                temp->right = new node(data);
            }
        }
    }



    //clear
    void clear(node *temp){
        if(!temp)
            return;
        clear(temp->left);
        clear(temp->right);
        delete temp;
    }


    //queries of ancestors
    pair<bool,int> get_ancestors(node* parent , node* child , int data){
        if(child->data == data){
            if(!parent)
                return make_pair(false,-1);//root case(it has not ancestor)
            return make_pair(true,parent->data);
        }
        if(child->data>data and child->left){
            return get_ancestors(child,child->left,data);
        }else if(child->data<data and child->right){
            return get_ancestors(child,child->right,data);
        }
        return make_pair(false,-1);
    }

    

public:
    //constructor
    binary_search_tree(int data):root(new node(data)){}

    //print sorted
    void print(){
        node* temp{root};
        print(temp);
        cout<<"\n";
    }

    //add to the tree
    void add(int data){
        node* temp{root};
        add(data,temp);
    }


      /*************
    	Home work 
      **************/
    //queries of ancestors
    vector<pair<bool,int>> get_ancestors(vector<int>& q){
        vector<pair<bool,int>>ans;
        node* temp{root};
        for(int i = 0;i<(int)q.size();i++){
            ans.push_back(get_ancestors(nullptr,temp,q[i]));
        }
        return ans;
    }

    //destructor
    ~binary_search_tree(){
        node* temp{root};
        clear(temp);
    }
};