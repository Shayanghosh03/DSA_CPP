#include<iostream>
using namespace std;

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

    // INSERT
    void insertUtil(TrieNode* root, string word) {
        if(word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'A';

        // Uppercase safety
        if(index < 0 || index >= 26) return;

        TrieNode* child;

        if(root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]); 
            root->children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }

    void insertWord(string word) {
        insertUtil(root, word);
    }

    // SEARCH
    bool searchUtil(TrieNode* root, string word) {
        if(word.length() == 0) {
            return root->isTerminal;
        }

        int index = word[0] - 'A';

        if(index < 0 || index >= 26) return false;

        TrieNode* child = root->children[index];

        if(child == NULL) return false;

        return searchUtil(child, word.substr(1));
    }

    bool searchWord(string word) {
        return searchUtil(root, word);
    }

    // DELETE (Proper)
    bool deleteUtil(TrieNode* root, string word) {
        if(word.length() == 0) {
            root->isTerminal = false;

            // Check if node has children
            for(int i = 0; i < 26; i++) {
                if(root->children[i] != NULL) {
                    return false;
                }
            }
            return true;
        }

        int index = word[0] - 'A';

        if(index < 0 || index >= 26) return false;

        TrieNode* child = root->children[index];

        if(child == NULL) return false;

        bool shouldDeleteChild = deleteUtil(child, word.substr(1));

        if(shouldDeleteChild) {
            delete child;
            root->children[index] = NULL;

            // Check if current node can be deleted
            if(root->isTerminal) return false;

            for(int i = 0; i < 26; i++) {
                if(root->children[i] != NULL) {
                    return false;
                }
            }
            return true;
        }

        return false;
    }

    void deleteWord(string word) {
        deleteUtil(root, word);
    }
};

int main() {
    Trie* t = new Trie();

    t->insertWord("ABCDE"); 
    t->insertWord("TIME");
    t->insertWord("DO");
    t->insertWord("HELLO");

    cout << "Before Delete: " << t->searchWord("TIME") << endl;

    t->deleteWord("TIME");

    cout << "After Delete: " << t->searchWord("TIME") << endl;

    return 0;
}