class Solution {
public:
    string defangIPaddr(string address) {
        int j = 0;
        string ans;
        for(int i = 0; address[i]!='\0';i++){
            if(address[i] == '.'){
                ans += "[.]";
            }
            else
                ans += address[i];
        }
        return ans;
    }
};