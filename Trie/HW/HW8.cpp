#include<bits/stdc++.h>
using namespace std;

                /***************************************************
                            Object : trie data structure
                            Author : @Alaa Omran
                 ***************************************************/




 /**************
    Home Work 8
 **************/
//implement a modified trie that helps in operating systems paths checking
class paths_trie{
private:
    map<string , paths_trie*> child;
    bool isLeaf{false};

public:

    void insert_iterative(const vector<string>& path){
        paths_trie* tmp = this;
        for(int idx = 0;idx < (int)path.size();idx++){
            if(tmp->child.count(path[idx]) == 0){
                tmp->child[path[idx]] = new paths_trie();
            }
            tmp = tmp->child[path[idx]];
        }
        tmp->isLeaf = true;
    }



    //implement the sub path exist function
    bool subpath_exist(const vector<string>& path){
        paths_trie* tmp = this;
        for(int idx = 0;idx < (int)path.size();idx++){
            if(tmp->child.count(path[idx]) == 0)
                return false;
            tmp = tmp->child[path[idx]];
        }
        return true;
    }
};
