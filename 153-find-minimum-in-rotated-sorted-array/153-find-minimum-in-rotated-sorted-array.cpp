class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n-1;
        while(l<r){
            int mid = l+(r-l)/2;
            if(nums[l]<nums[r]) 
                return nums[l];
            else if(nums[mid]>=nums[l])
                l = mid+1;
            else 
                r = mid;
        }
        return nums[l];
    }
};