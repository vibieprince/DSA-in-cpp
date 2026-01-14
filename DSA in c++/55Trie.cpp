#include<iostream>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch){
        data = ch;
        for(int i=0;i<26;i++)
            children[i] = NULL;
        isTerminal = false;
    }
};

class Trie{
    public:
    TrieNode* root;
    Trie(){
        root = new TrieNode('\0');
    }
    void insertUtil(TrieNode* root,string word){
        // Base Case
        if(word.length()==0){
            root->isTerminal = true;
            return;
        }
           
        
        // Assuming the character would be in Capital
        int index = word[0]-'A';
        TrieNode* child;

        // Present
        if(root->children[index] != NULL)
            child = root->children[index];
        
        // Absent
        else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        // Recursive call
        insertUtil(child,word.substr(1));
    }
    void insertWord(string word){
        insertUtil(root,word);
    }

    bool searchUtil(TrieNode* root,string word){
        if(word.length()==0)
            return root->isTerminal;

        int index = word[0] - 'A';

        TrieNode* child;
        if(root->children[index] != NULL)
            child = root->children[index];
        else
            return false;
        return searchUtil(child,word.substr(1));
    }
    bool searchWord(string word){
        return searchUtil(root,word);
    }
    bool removeUtil(TrieNode *root,string word,int i){
        if(i==word.length()){
            if(!root->isTerminal) return false;
            root->isTerminal = false;
            for(int k=0;k<26;k++)
                if(root->children[k] != NULL) return false;
            return true;
        }

        int index = word[i] - 'A';
        TrieNode* child = root->children[index];
        if(child==NULL) return false;
        bool shouldDeleteChild = removeUtil(child,word,i+1);
        if(shouldDeleteChild){
            delete child;
            root->children[index] = NULL;
        }
        if(root->isTerminal) return false;
        for(int k=0;k<26;k++)
            if(root->children[k] != NULL) return false;
        return true;
    }

    void removeWord(string word){
        removeUtil(root,word,0);
    }
};
int main(){
    Trie *t = new Trie();
    t->insertWord("ARM");
    t->insertWord("DO");
    // t->removeWord("DO");
    t->insertWord("TIME");
    if(t->searchWord("DO"))
        cout<<"DO is present";
    else
        cout<<"DO is not present";
}