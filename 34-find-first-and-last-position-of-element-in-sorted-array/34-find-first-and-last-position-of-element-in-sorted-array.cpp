class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if((int)nums.size() == 0) return {-1, -1};
        int n = nums.size();
        int l = 0, r = n-1;
        vector<int> ans =  {-1, -1};
        // first value
        while(l<=r) {
            int mid=(l+r)/2;
            if(nums[mid] == target) {
                ans[0] = mid;
                r = mid-1;
            } else if(nums[mid]<target){
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        // cout << l << ' ' << r << endl;
        // if(nums[l] == target) ans[0] = l; 
        l = 0, r = n-1;
        while(l<=r){
            int mid = (l+r)/2;
            if(target == nums[mid]){
                ans[1] = mid;
                l = mid+1;
            } else if(target>nums[mid]){
                l = mid+1;
            } else {
                 r= mid-1;
            }
        } 
        // if(nums[l] == target) ans[1] = l;
        return ans;
    }
};