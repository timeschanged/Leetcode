#define ll long long
class Solution {
public:
    bool isValid(vector<int> &bloomDay, const int &m,const int &k, const int &days) {
        ll count = 0, size = 0;
        for(int i = 0; i<bloomDay.size(); i++) {
            if(bloomDay[i] <= days) 
                size++;
            else 
                size = 0;
            if(size == k) size = 0, count++;
            if(count == m) return true;
        }
        return false;
    }
    
    int minDays(vector<int>& bloomDay,ll m, int k) {
        int n = bloomDay.size();
        if(!n || !m || !k) return 0;
        if(m*k > n) return -1;
        ll l = INT_MAX, r = INT_MIN;
        for(int i = 0; i<n; i++) {
            if(l > bloomDay[i]) l = bloomDay[i];
            if(r < bloomDay[i]) r = bloomDay[i];
        }
        while(l<=r) {
            ll mid = l + (r-l)/2;
            
            if(isValid(bloomDay, m, k, mid)) {
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        return l;
    }
};