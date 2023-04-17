class Solution {
public:
    const vector<string> pad = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        if(n == 0) return {};
        vector<string> ans;
        ans.push_back("");
        for(auto &dig: digits){
            vector<string> temp;
            for(auto &str: pad[dig-'0']) {
                for(auto &s: ans) {
                    temp.push_back(s + str);
                }
            }
            ans.swap(temp);
        }
        return ans;
    }
};