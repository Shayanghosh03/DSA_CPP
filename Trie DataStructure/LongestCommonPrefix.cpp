#include<iostream>
#include<vector>
using namespace std;

string longestCommonPrefix(vector<string> &arr, int n)
{
    string ans = "";
    for(int i = 0; i < arr[0].length(); i++) {
        char ch = arr[0][i];
        bool match = true;
        for(int j = 1; j < n; j++) {
            if(arr[j].size() <= i || arr[j][i] != ch) {
                match = false;
                break;
            }
        }
        if(match == true) {
            ans.push_back(ch); 
        } else {
            break;             
        }
    }
    return ans;
}

// Using Tries

class TrieNode {
public:
    char data;
    TrieNode* children[26];
    int childCount;
    bool isTerminal;

    TrieNode(char ch) {
        data = ch;
        for(int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        childCount = 0;
        isTerminal = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie(char ch) {
        root = new TrieNode(ch);
    }

    void insertUtil(TrieNode* root, string word) {
        if(word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        if(index < 0 || index >= 26) return;

        TrieNode* child;

        if(root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->childCount++;
            root->children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }

    void insertWord(string word) {
        insertUtil(root, word);
    }

    void lcp(string str, string &ans) {
        TrieNode* temp = root;  // ✅ use temp pointer

        for(int i = 0; i < str.length(); i++) {
            char ch = str[i];

            if(temp->childCount == 1) {
                ans.push_back(ch);

                int index = ch - 'a';
                if(temp->children[index] == NULL) break;

                temp = temp->children[index];
            } else {
                break;
            }

            if(temp->isTerminal) {
                break;
            }
        }
    }
};

string longestCommonPrefix(vector<string> &arr, int n) {
    Trie* t = new Trie('\0');

    for(int i = 0; i < n; i++) {
        t->insertWord(arr[i]);
    }

    string first = arr[0];
    string ans = "";

    t->lcp(first, ans);

    return ans;
}