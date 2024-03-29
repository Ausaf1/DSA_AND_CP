class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.length();
        int m = t.length();
        int l = 0,r = 0;
        while(l < n && r < m){
            if(s[l] == t[r]) l++,r++;
            else r++;
        }
        return l == n;
    }
};