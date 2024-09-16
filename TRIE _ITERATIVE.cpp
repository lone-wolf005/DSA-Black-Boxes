#include<bits/stdc++.h>
using namespace std;
#define ll long long int

class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch) {
        data = ch;
        for(int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode('\0');
    }

    // Iterative insert function
    void insertWord(string word) {
        TrieNode* curr = root;
        for(char ch : word) {
            int index = ch - 'A';
            if(curr->children[index] == NULL) {
                curr->children[index] = new TrieNode(ch);
            }
            curr = curr->children[index];
        }
        curr->isTerminal = true;
    }

    // Iterative search function
    bool searchWord(string word) {
        TrieNode* curr = root;
        for(char ch : word) {
            int index = ch - 'A';
            if(curr->children[index] == NULL) {
                return false;
            }
            curr = curr->children[index];
        }
        return curr->isTerminal;
    }

    // Iterative query function
    string utilquery(string word) {
        TrieNode* curr = root;
        string s = "";
        for(char ch : word) {
            int index = ch - 'a';
            if(curr->children[index] == NULL) return word;
            curr = curr->children[index];
            s += ch;
            if(curr->isTerminal) return s;
        }
        return word;
    }
};

int main() {
    Trie* t = new Trie();
    cout << "JIGAR" << endl;
    t->insertWord("JIGAR");
    t->insertWord("JIGARA");
    t->insertWord("JIGARAO");

    cout << "isPresent: " << t->searchWord("JIGAR") << endl;
    cout << "isPresent: " << t->searchWord("IGAR") << endl;

    return 0;
}
