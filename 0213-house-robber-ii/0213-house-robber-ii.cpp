class Solution {
private:
    int findMaxSum(vector<int> arr) {
        int n = arr.size();
        int prev = arr[0],prev2 = 0;
        for(int i = 1;i < n;i++){
            int take = arr[i];
            if(i > 1) take += prev2;
            int notTake = prev;
            int curr = max(take,notTake);
            prev2 = prev;
            prev = curr;
        }
        return prev;
}
public:
    int rob(vector<int>& nums) {
        vector<int> temp1,temp2;
        int n = nums.size();
        if(n == 1) return nums[0];
        for(int i = 0;i < n;i++){
            if(i != n-1) temp1.push_back(nums[i]);
            if(i != 0) temp2.push_back(nums[i]);
        }
        return max(findMaxSum(temp1),findMaxSum(temp2));
    }
};