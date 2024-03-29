class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> mp;
        if(s.length() != t.length())
            return false;
        for(auto i : s)
            mp[i]++;
        for(auto j : t){
            if(mp[j] > 0)
                mp[j]--;
            else
                return false;
        }
        for(auto i : mp){
            if(i.second > 0)
                return false;
        }
        return true;
    }
};