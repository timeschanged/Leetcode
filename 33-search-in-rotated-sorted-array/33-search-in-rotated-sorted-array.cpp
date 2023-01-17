class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(is_sorted(nums.begin(), nums.end())){
            auto it = lower_bound(nums.begin(), nums.end(), target);
            if(it==nums.end() || *it != target) return -1;
            return it-nums.begin();
        }
        int l = 0, r = n-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(nums[mid] == target){
                return mid;
            } else if(nums[mid] >= nums[l]){
                if(nums[l] <= target && nums[mid] > target) 
                    r = mid-1;
                else 
                    l = mid+1;
           } else{
                if(nums[mid] < target && nums[r] >= target) 
                    l = mid+1;
                else 
                    r = mid-1;
            } 
        }
        return -1;
    }
};