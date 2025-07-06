class Solution {
public:
        bool isValid(string& s) {
        if(s=="") return false;
        for (char c : s) {
            if (!isalnum(c) && c != '_') return false;
        }
        return true;
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, 
    vector<bool>& isActive) {
        int n = code.size();
        vector<int> valid(n, 0);

        for (int i = 0; i < n; i++) {
            if (isValid(code[i])) valid[i] = 1;
        }
        vector<string> ans;
        int l = 0, r = 0;

        vector<string> order = {"electronics", "grocery", "pharmacy", "restaurant"};
        for (string category: order) {
            for (int i = 0; i < n; i++) {
                if (businessLine[i] == category && isActive[i] && valid[i] == 1) {
                    ans.push_back(code[i]);
                    r++;
                }
            }
            sort(ans.begin() + l, ans.begin() + l + r);
            l = l + r;
            r = 0; 
        }
        return ans;
    }

};
