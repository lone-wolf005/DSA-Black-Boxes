//Radhe Radhe
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

class TrieNode{
    public:
    char data;
    TrieNode*children[26];
    bool isTerminal;

    TrieNode(char ch){
        data=ch;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isTerminal=false;
    }
};
class Trie{
    public:
    TrieNode*root;
    Trie(){
        root=new TrieNode('\0');
    }
    void insertUtil(TrieNode*root,string word){
        if(word.length()==0){
            root->isTerminal=true;
            return;
        }
        int index = word[0]-'A';
        TrieNode*child;

        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            child = new TrieNode(word[0]);
            root->children[index]=child;
        }
        insertUtil(child,word.substr(1));

    }
      void insertWord(string word){
        insertUtil(root,word);
    }  
    string query(string word,TrieNode*&root){
        TrieNode*curr = root;
        string s="";
        for(auto c:word){
            int index = c-'a';
            if(curr->children[index]==NULL)return word;
            curr = curr->children[index];
            s+=c;
            if(curr->isTerminal)return s;
        }
        return word;
    }
    string utilquery(string word){
        return query(word,root);
    }
    
    bool searchUtil(TrieNode*root,string word){
        if(word.length()==0){
            return root->isTerminal;
        }
        int index = word[0]-'A';
        TrieNode*child;
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{ return false;}
        return searchUtil(child,word.substr(1));

    }
  
    bool searchWord(string word){
        return searchUtil(root,word);
    } 
};
int main(){
  Trie * t= new Trie();
  cout<<"JIGAR"<<endl;
  t->insertWord("JIGAR");
  t->insertWord("JIGARA");
  t->insertWord("JIGARAO");

  cout<<"isPresent"<<t->searchWord("IGAR");
return 0;
}
