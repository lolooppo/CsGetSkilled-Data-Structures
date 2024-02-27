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

    //get the least common ancestor
    int lca(int data1,int data2,node* temp){
        if(data1<temp->data and data2<temp->data)
            return lca(data1,data2,temp->left);
        if(data1>temp->data and data2>temp->data)
            return lca(data1,data2,temp->right);
        return temp->data;
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

    /*****************
        Home work
    *****************/
    //get the lowest common ancestor
    int lca(int data1,int data2){
        node* temp{root};
        int res = lca(data1,data2,temp);
        return res;
    }


    //destructor
    ~binary_search_tree(){
        node* temp{root};
        clear(temp);
    }
};
