class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size()-1;
        int l = 0, r = n;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(nums[mid]==target)
                return true;
            else if(nums[mid]==nums[l] && nums[mid] == nums[r])
                l++, r--;
            else if(nums[mid]>=nums[l]){
                if(target>=nums[l] && target <nums[mid])
                    r = mid-1;
                else 
                    l = mid+1;
            } else {
                if(target>nums[mid] && target<=nums[r]){
                    l = mid+1;
                } else 
                    r = mid-1;
            }
        }
        return false;
    }
};