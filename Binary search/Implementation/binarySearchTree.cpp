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

    //check if exist(recursive approach)
    bool exist(int data,node* temp){
        if(data == temp->data)
            return true;
        if(data>temp->data and temp->right){
            return exist(data,temp->right);
        }else if(data<temp->data and temp->left){
            return exist(data,temp->left);
        }
        return false;
    }

    //get the least common ancestor
    int lca(int data1,int data2,node* temp){
        if(data1<temp->data and data2<temp->data)
            return lca(data1,data2,temp->left);
        if(data1>temp->data and data2>temp->data)
            return lca(data1,data2,temp->right);
        return temp->data;
    }

    //get the maximum
    int max(node* temp){
        while(temp and temp->right){
            temp = temp->right;
        }
        return temp->data;
    }

    //get the minimum
    int min(node* temp){
        while(temp and temp->left){
            temp = temp->left;
        }
        return temp->data;
    }

    //clear
    void clear(node *temp){
        if(!temp)
            return;
        clear(temp->left);
        clear(temp->right);
        delete temp;
    }

    //get the father of the given node parents vector
    node* get_next(vector<node*>& v){
        if((int)v.size() == 0)
            return nullptr;
        node* temp = v.back();
        v.pop_back();
        return temp;
    }

    //queries of ancestors
    pair<bool,int> get_ancestors(node* parent,node*child,int data){
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

    //deletion of nodes
    node* min_node(node* temp){//in case of successor
        node* dummy{temp};
        while(dummy->left){
            dummy = dummy->left;
        }
        return dummy;
    }

    node* delete_node(node* temp,int data){
        if(!temp)return nullptr;
        if(data < temp->data){
            temp->left = delete_node(temp->left,data);
        }
        else if(data > temp->data){
            temp->right = delete_node(temp->right,data);
        }
        else{
            node* dummy = temp;
            if(!temp->left and !temp->right){//has no childs
                temp = nullptr;
            }
            else if(!temp->right){//has one child
                temp = temp->left;
            }
            else if(!temp->left){//has one child
                temp = temp->right;
            }
            else{//has two childs
                node* mn = min_node(temp->right);
                temp->data = mn->data;
                temp->right = delete_node(temp->right,temp->data);
                dummy = nullptr;
            }
            if(dummy)
                delete dummy;
        }
        return temp;
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

    //check if exist(recursive approach)
    bool exist(int data){
        node* temp{root};
        bool is = exist(data,temp);
        return is;
    }

    //check if exist(iteratively)
    bool _exist(int data){
        node* temp{root};
        while(temp){
            if(temp->data == data)return true;
            if(data>temp->data)
                temp = temp->right;
            else
                temp = temp->left;
        }
        return false;
    }

    //get the minimum in the tree
    int max(){
        node* temp{root};
        int res = max(temp);
        return res;
    }

    //get the minimum in the tree
    int min(){
        node* temp{root};
        int res = min(temp);
        return res;
    }

    //get the lowest common ancestor
    int lca(int data1,int data2){
        node* temp{root};
        int res = lca(data1,data2,temp);
        return res;
    }

    //get the chain till the target node
    bool find_chain(vector<node*>& v,int data){
        node* temp{root};
        bool is{false};
        while(temp){
            v.push_back(temp);
            if(temp->data == data){
                is = true;
                break;
            }
            if(temp->data > data){
                temp = temp->left;
            }else if(temp->data < data){
                temp = temp->right;
            }
        }
        return is;
    }

    //get the successor of given node
    pair<bool,int> get_successor(int data){
        vector<node*>ancestors;
        bool is = find_chain(ancestors,data);
        if(!is)
            return make_pair(false,-1);
        node* child{nullptr}, * parent{nullptr};
        child = get_next(ancestors);
        parent = get_next(ancestors);
        //if the child has a right sub-tree so we just have to get it’s minimum
        if(child->right){
            int res = min(child->right);
            return make_pair(true,res);
        }
        //otherwise
        while(parent and parent->right == child){
            child = parent , parent = get_next(ancestors);//keep going while the child is on the right of his father
        }
        if(parent)
            return make_pair(true,parent->data);
        return make_pair(false,-1);
    }

    //get the predecessor
    pair<bool,int> get_predecessor(int data){
        vector<node*>ancestors;
        bool is = find_chain(ancestors,data);
        if(!is)
            return make_pair(false,-1);
        node* child{nullptr},* parent{nullptr};
        child = get_next(ancestors);
        parent = get_next(ancestors);
        //if the child has a right sub-tree so we just have to get it’s minimum
        if(child->left){
            int res = max(child->left);
            return make_pair(true,res);
        }
        //otherwise
        while(parent and parent->left == child){
            child = parent , parent = get_next(ancestors);//keep going while the child is on the right of his father
        }
        if(parent)
            return make_pair(true,parent->data);
        return make_pair(false,-1);
    }

    //queries of ancestors
    vector<pair<bool,int>> get_ancestors(vector<int>& q){
        vector<pair<bool,int>>ans;
        node* temp{root};
        for(int i = 0;i<(int)q.size();i++){
            ans.push_back(get_ancestors(nullptr,temp,q[i]));
        }
        return ans;
    }

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

    //delete node
    void delete_val(int data){
        if(root->data == data and !root->left and !root->right)
            return;//can not delete the structure it self
        delete_node(root,data);
    }

    //destructor
    ~binary_search_tree(){
        node* temp{root};
        clear(temp);
    }
};
