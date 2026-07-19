#include<iostream>
using namespace std;
class Solution {
public:
    bool valid(char ch) {
        if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
            return 1;
        }
        return 0;
    }
    char tolowerCase(char ch) {
        if((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')) {
            return ch;
        } else {
            char temp = ch - 'A' + 'a';
            return temp;
        }
    }
    bool checkPalindrome(string s) {
        int st = 0;
        int end = s.length() - 1;
        while(st < end) {
            if(s[st] != s[end]) {
                return 0;
            } else {
                st++;
                end--;
            }
        }
        return 1;
    }
    bool isPalindrome(string s) {
        string temp = "";
        for(int i = 0; i < s.length(); i++) {
            if(valid(s[i])) {
                temp.push_back(s[i]);
            }
        }
        for(int i = 0; i < temp.length(); i++) {
            temp[i] = tolowerCase(temp[i]);
        }
        return checkPalindrome(temp);
    }
};