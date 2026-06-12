class Solution {
public:
    bool isPal(string t) {
        int i = 0, j = t.size() - 1;

        while(i < j) {
            if(t[i] != t[j]) return false;
            i++;
            j--;
        }

        return true;
    }

    string longestPalindrome(string s) {
        string ans = "";

        for(int i = 0; i < s.size(); i++) {
            string temp = "";

            for(int j = i; j < s.size(); j++) {
                temp += s[j];

                if(isPal(temp) && temp.size() > ans.size()) {
                    ans = temp;
                }
            }
        }

        return ans;
    }
};