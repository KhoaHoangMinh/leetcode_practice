#include <iostream>
#include <unordered_map>
#include <string.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int lengthOfLongestSubstring(string s) {
    int len = s.length();
    int maxLen = 0;
    unordered_set<char> charSet;
    int l = 0;

    for(int r = 0; r < len; r++) {
        if(charSet.count(s[r]) == 0) {
            charSet.insert(s[r]);
            maxLen = max(maxLen, r-l+1);
        } else {
            while(charSet.count(s[r])) {
                charSet.erase(s[l]);
                l++;
            }
            charSet.insert(s[r]);
        }
    }

    return maxLen;
}

int main() {
    cout << "Longest substring without repeating characters." << endl;
    // string s = "abcabcbb";
    string s = "abca";
    cout << lengthOfLongestSubstring(s) << endl;
    return 0;
}