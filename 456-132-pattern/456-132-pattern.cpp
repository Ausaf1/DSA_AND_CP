class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int a = INT_MIN;
        stack<int> s;
        for(int i = nums.size() - 1;i >= 0;i--){
            if(nums[i] < a)
                return true;
            while(!s.empty() && nums[i] > s.top()){
                a = s.top();
                s.pop();
            }
            s.push(nums[i]);
        }
        return false;
    }
};