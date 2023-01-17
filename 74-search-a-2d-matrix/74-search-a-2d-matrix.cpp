class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size();
        int r = 0, c = cols-1;
        while(r<rows && c>=0){
            int cur = matrix[r][c];
            if(cur == target) return true;
            if(target>cur) r++;
            else c--;
        }
        return 0;
    }
};