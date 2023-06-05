class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(),m = matrix[0].size();
        if(!matrix.size()) return 0;
        int low = 0,high = n*m - 1;
        while(low <= high){
            int mid = (low + high) >> 1;
            if(matrix[mid/m][mid%m] == target) return true;
            else if(matrix[mid/m][mid%m] > target) high = mid - 1;
            else low = mid + 1;
        }
        return false;
    }
};