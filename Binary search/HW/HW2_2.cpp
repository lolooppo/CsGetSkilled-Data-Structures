#include<bits/stdc++.h>
using namespace std;

/***********************************************************/
/*                 Author : Alaa Omran                     */
/*                 Object : Binary Trees                   */
/***********************************************************/

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

    
    /*******************
        Home work
    *******************/
    
    //check if the given preorder is degenerate tree or not
    bool  degenerate(vector<int>& v){
        int n = v.size();
        if(!n)
            return false;
        if(n == 1 or n == 2)
            return true;
        for(int i = 2;i<n;i++){
            int c = v[i] , b = v[i-1] , a = v[i-2];
            if(b>a and c>a and (c<b or c>b)){
                 continue;
            }else if(b<a and c<a and (c<b or c>b)){
                continue;
            }else{
                return false;
            }
        }
        return true;
    }

    //destructor
    ~binary_search_tree(){
        node* temp{root};
        clear(temp);
    }
};