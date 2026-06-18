class Solution {
public:
    string decodeString(string s) {
        stack<int> numStack;
        stack<string> strStack;

        string currStr = "";
        int num = 0;

        for(char ch : s) {

            if(isdigit(ch)) {
                num = num * 10 + (ch - '0');
            }

            else if(ch == '[') {
                numStack.push(num);
                strStack.push(currStr);

                num = 0;
                currStr = "";
            }

            else if(ch == ']') {
                int repeat = numStack.top();
                numStack.pop();

                string prev = strStack.top();
                strStack.pop();

                string temp = "";

                for(int i = 0; i < repeat; i++) {
                    temp += currStr;
                }

                currStr = prev + temp;
            }

            else {
                currStr += ch;
            }
        }

        return currStr;
    }
};