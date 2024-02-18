#include<bits/stdc++.h>
using namespace std;

                /***************************************************
                            Object : trie data structure
                            Author : @Alaa Omran
                 ***************************************************/


class trie{
private:
    map<int , trie*>child;
    bool isLeaf{false};

public:
    trie(){

    }

    void insert(string str , int idx = 0){
        if(idx == (int)str.size())
            isLeaf = true;
        else{
            int currentChar = str[idx] - 'a';
            if(child.count(currentChar) == 0)
                child[currentChar] = new trie();

            child[currentChar]->insert(str , idx + 1);
        }
    }

    bool exist(string str , int idx = 0){
        if(idx == (int)str.size())
            return isLeaf;

        int currentChar = str[idx] - 'a';
        if(child.count(currentChar) == 0)
            return false;

        return child[currentChar]->exist(str , idx + 1);
    }

    bool prefix(string str , int idx = 0){
        if(idx == (int)str.size())
            return true;

        int currentChar = str[idx] - 'a';
        if(child.count(currentChar) == 0)
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
            if(tmp->child.count(currentChar) == 0)
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
            if(tmp->child.count(currentChar) == 0)
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
            if(tmp->child.count(currentChar) == 0)
                return false;
            tmp = tmp->child[currentChar];
        }
        return true;
    }



    //4                     leetcode problem ===> my solution(https://leetcode.com/problems/replace-words/solutions/4739024/easy-solution-c-beats-99-9/)




    //5                     implement a function that prints the tree words
    void get_all_strings(vector<string>& res , string str = ""){
        if(isLeaf)
            res.push_back(str);
        for(int i = 0;i<26;i++){
            if(child.count(i))
                child[i]->get_all_strings(res , str + char('a' + i));
        }
    }






    //6                     implement an auto complete function
    void auto_complete_v1(vector<string>& res ,const string& word , string str = "" , int idx = 0){
        if(isLeaf and idx >= (int)word.size())
            res.push_back(str);
        for(int i = 0;i<26;i++){
            if(  child.count(i) and (idx >= (int)word.size()    or    word[idx] == (char)('a' + i))  )
                child[i]->auto_complete_v1(res , word , str + (char)('a' + i) , idx + 1);
        }
    }
    //another version of problem 6
    void auto_complete_v2(vector<string>& res ,const string& word){
        trie* tmp = this;
        for(int i = 0;i<(int)word.size();i++){
            int currentChild = word[i] - 'a';
            if(tmp->child.count(currentChild) == 0)
                return;
            tmp = tmp->child[currentChild];
        }
        tmp->get_all_strings(res , word);
    }

};








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



    //8                              implement the sub path exist function
    bool subpath_exist(const vector<string>& path){
        paths_trie* tmp = this;
        for(int idx = 0;idx < (int)path.size();idx++){
            if(tmp->child.count(path[idx]) == 0)
                return false;
            tmp = tmp->child[path[idx]];
        }
        return true;
    }





    //9                     leetcode problem ===> my solution(https://leetcode.com/problems/implement-magic-dictionary/solutions/4743981/trie/)
};
