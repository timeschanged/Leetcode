class Solution {
public:
    vector<string> ans;
    map<int, string> mpp;
    void f(int i, string s,const string &dig) {
        int n = dig.size();
        if(i == n) {
            ans.push_back(s);
            return;
        }
        int nos = (dig[i]-'0');
        for(auto ch: mpp[nos]) {
            s.push_back(ch);
            f(i+1, s, dig);
            s.pop_back();
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return ans;
        mpp[2] = "abc", mpp[3] = "def", mpp[4] = "ghi", mpp[5] = "jkl", mpp[6] = "mno", mpp[7] = "pqrs", mpp[8] = "tuv", mpp[9] = "wxyz";
        f(0, "", digits);
        return ans;
    }
};