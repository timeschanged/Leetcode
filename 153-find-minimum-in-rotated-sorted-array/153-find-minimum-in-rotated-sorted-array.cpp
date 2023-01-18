class Solution {
public:
    int find_left(int x, int n){
        if(x == 0) return n-1;
        else return x-1;
    } 
    int find_right(int x, int n){
        if(x == n-1) return 0;
        return x+1;
    }
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            int left = find_left(mid, n);
            int right = find_right(mid, n);
            if(nums[mid]>nums[left] && nums[mid]>nums[right])
                return nums[right];
            else if(nums[mid]>=nums[l])
                l = mid+1;
            else 
                r = mid-1;
        }
        return (nums[0]>nums[n-1]?nums[n-1]:nums[0]);
    }
};