#include<bits/stdc++.h>
using namespace std;

                /***************************************************
                            Object : trie data structure
                            Author : @Alaa Omran
                 ***************************************************/

 /**************
    Home Work 7
 **************/
//implement a modified trie that provides suffix function
class suffix_trie{
private:
    map<int , suffix_trie*> child;
    bool isLeaf{false};

public:
    suffix_trie(){
        //memset(child , 0 ,sizeof(child));
    }

    void insert_iterative(string str){
        suffix_trie* tmp = this;

        for(int idx = (int)str.size() - 1 ;idx > -1 ; idx--){
            int currentChar = str[idx] - 'a';
            if(tmp->child.count(currentChar) == 0){
                tmp->child[currentChar] = new suffix_trie();
            }
            tmp = tmp->child[currentChar];
        }
        tmp->isLeaf = true;
    }





    //7                              implement suffix function
    bool suffix_iterative(string str){
        suffix_trie* tmp = this;

        for(int idx = (int)str.size() - 1 ;idx > -1 ; idx--){
            int currentChar = str[idx] - 'a';
            if(tmp->child.count(currentChar) == 0)
                return false;
            tmp = tmp->child[currentChar];
        }
        return true;
    }
};
