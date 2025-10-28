#include<iostream>
using namespace std;

class TrieNode {
    public: 
    char data;
    TrieNode* childNode[26];

    bool isTerminal = false;

    TrieNode(char ch){
        data = ch;

        for(int i = 0 ; i < 26 ; i++){
            childNode[i] = NULL;
        }

        isTerminal = false;
    }

   

};


class Trie {
    public: 
    TrieNode* root;

    Trie(){
        root = new TrieNode('\0');
    }

    void insertIntoTrie(TrieNode* root , string word){
        if(word.length() == 0){
            root->isTerminal = true;
            cout << "created" << endl;
            return;
        }

        TrieNode* child;
        
        int index = word[0] - 'a';

        if(root->childNode[index] != NULL ){
          child = root->childNode[index];
        }else{
             child = new TrieNode(word[0]);
             root->childNode[index] = child;
           
        }

         insertIntoTrie(root->childNode[index] , word.substr(1)); 


    }

    bool searchInTrie(TrieNode* root , string word){
        if(word.length() == 0){
            return root->isTerminal;
        }

        int index = word[0] - 'a';

        if(root->childNode[index] == NULL){
            return false;
        }

         return searchInTrie(root->childNode[index] , word.substr(1));
    }

    bool search(string word){
        return searchInTrie(root ,word);
    }

    void insert(string word){
      insertIntoTrie(root,word);
    }

};


int main(){

    Trie* t = new Trie();
    t->insert("arm");
    t->insert("do");
    t->insert("time");

    if(t->search("doo")){
        cout << "present" << endl;
    }else{
        cout << "sorrry" << endl;
    }

    
    return 0;
}


