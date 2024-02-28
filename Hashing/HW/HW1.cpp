#include<bits/stdc++.h>
using namespace std;

class trie{
private:
    map<int , trie*>child;
    bool isLeaf{false};

public:
    trie(){

    }

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

    void get_all_strings(vector<string>& res , string str = ""){
        if(isLeaf)
            res.push_back(str);
        for(int i = 0;i<26;i++){
            if(child.count(i))
                child[i]->get_all_strings(res , str + char('a' + i));
        }
    }
};

/*
    Given a string, count how many unique substring inside it
    ○ int count_unique_substrings(const string &str)
    ● For string aaab, substrings are:
    ○ a, aa, aaa, aaab, a, aa, aab, a, ab, b
    ○ Only 7 distinct substrings
*/









//1st approach to use a hash set
int count_unique_substrings_hash_set(const string &str){
    int n = (int)str.size();
    unordered_set<string>u_s;
    for(int start = 0;start < n;start++){
        for(int end = start;end < n;end++){
            string sub = str.substr(start , end - start + 1);
            u_s.insert(sub);
        }
    }
    return (int)u_s.size();
}










//2nd to use a letter trie tree
int count_unique_substrings_trie(const string &str){
    trie tree;
    vector<string>res;
    int n = (int)str.size();
    for(int start = 0;start < n;start++){
        for(int end = start;end < n;end++){
            tree.insert_iterative(str.substr(start , end - start + 1));
        }
    }
    tree.get_all_strings(res);
    return (int)res.size();
}






void test(){
    string str1{"aaab"};            //7
    string str2{"aaaaa"};           //5
    string str3{"aaaba"};           //11
    string str4{"abcdef"};          //21

    cout<<"1st approach : \n";
    cout<<count_unique_substrings_hash_set(str1)<<"\n";
    cout<<count_unique_substrings_hash_set(str2)<<"\n";
    cout<<count_unique_substrings_hash_set(str3)<<"\n";
    cout<<count_unique_substrings_hash_set(str4)<<"\n";

    cout<<"2nd approach : \n";
    cout<<count_unique_substrings_trie(str1)<<"\n";
    cout<<count_unique_substrings_trie(str2)<<"\n";
    cout<<count_unique_substrings_trie(str3)<<"\n";
    cout<<count_unique_substrings_trie(str4)<<"\n";
}

int main(){
    test();
}
