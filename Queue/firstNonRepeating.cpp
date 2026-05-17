// Stream First Non-repeating
#include<iostream>
#include<queue>
#include<map>
#include<unordered_map>>
using namespace std;
class Solution {
  public:
    string firstNonRepeating(string &s) {
        // code here
        unordered_map<char, int> count;
        queue<int> q;
        string ans = "";
        for(int i = 0; i < s.length(); i++) {
            char ch = s[i];
            count[ch]++;
            q.push(ch);
            while(!q.empty()) {
                if(count[q.front()] > 1) {
                    q.pop();
                } else {
                    ans.push_back(q.front());
                    break;
                }
            }
            if(q.empty()) {
                ans.push_back('#');
            }
        }
        return ans;
    
    }
};