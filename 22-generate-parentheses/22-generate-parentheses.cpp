class Solution {
public:
    vector<string> ans;
    void f(int op, int cl, string s, int n) {
        if(op == n && cl == n) {
            ans.push_back(s);
            return;
        }
        if(op<n) {
            s.push_back('(');
            f(op+1, cl, s, n);
            s.pop_back();
        }
        if(cl<n && op>cl) {
            s.push_back(')');
            f(op, cl+1, s, n);
            s.pop_back();
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        f(0, 0, "", n);
        return ans;
    }
};