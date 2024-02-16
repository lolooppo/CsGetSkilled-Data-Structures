#include<bits/stdc++.h>
using namespace std;
class trie{
private:
    static const int MAX_CHAR = 26;
    trie* child[MAX_CHAR];
    bool isLeaf{false};

public:
    trie(){
        memset(child , 0 ,sizeof(child));
    }

    void insert(string str , int idx = 0){
        if(idx == (int)str.size())
            isLeaf = true;
        else{
            int currentChar = str[idx] - 'a';
            if(child[currentChar] == 0)
                child[currentChar] = new trie();

            child[currentChar]->insert(str , idx + 1);
        }
    }

    bool exist(string str , int idx = 0){
        if(idx == (int)str.size())
            return isLeaf;

        int currentChar = str[idx] - 'a';
        if(child[currentChar] == 0)
            return false;

        return child[currentChar]->exist(str , idx + 1);
    }

    bool prefix(string str , int idx = 0){
        if(idx == (int)str.size())
            return true;

        int currentChar = str[idx] - 'a';
        if(child[currentChar] == 0)
            return false;

        return child[currentChar]->prefix(str , idx + 1);
    }







                                        /***********************
                                        * Home Works Solutions *
                                        ************************/


    //1                             implement the insert function but the iterative style
    void insert_iterative(string str){
        trie* tmp = this;

        for(int idx = 0 ;idx < (int)str.size(); idx++){
            int currentChar = str[idx] - 'a';
            if(tmp->child[currentChar] == 0)
                tmp->child[currentChar] = new trie();
            tmp = tmp->child[currentChar];
        }
        tmp->isLeaf = true;
    }





    //2                             implement the exist function but the iterative style
    bool exist_iterative(string str){
        trie *tmp = this;

        for(int idx = 0;idx<(int)str.size();idx++){
            int currentChar = str[idx] - 'a';
            if(tmp->child[currentChar] == 0)
                return false;
            tmp = tmp->child[currentChar];
        }
        return tmp->isLeaf;
    }





    //3                             implement the prefix function but the iterative style
    bool prefix_iterative(string str){
        trie* tmp = this;

        for(int idx = 0;idx<(int)str.size();idx++){
            int currentChar = str[idx] - 'a';
            if(tmp->child[currentChar] == 0)
                return false;
            tmp = tmp->child[currentChar];
        }
        return true;
    }



    //4                     leetcode problem ===> my solution(https://leetcode.com/problems/replace-words/solutions/4739024/easy-solution-c-beats-99-9/)
    
    
    
    
    
};