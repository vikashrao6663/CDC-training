class Solution {
public:
    bool isValid(string s) {

        stack<char> st;

        for(int i = 0; i < s.size(); i++) {

            char ch = s[i];

            // opening brackets
            if(ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            }

            // closing brackets
            else {

                if(st.empty()) return false;

                if((ch == ')' && st.top() == '(') ||
                   (ch == '}' && st.top() == '{') ||
                   (ch == ']' && st.top() == '[')) {
                    st.pop();
                }
                else {
                    return false;
                }
            }
        }

        return st.empty();
    }
};