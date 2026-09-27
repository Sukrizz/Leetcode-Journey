class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();

        // match[i] = index of the bracket matching i
        vector<int> match(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(i);
            }
            else if (s[i] == ')') {
                int open = st.top();
                st.pop();

                match[i] = open;
                match[open] = i;
            }
        }

        string ans;

        int i = 0;
        int direction = 1;

        while (i >= 0 && i < n) {

            if (s[i] == '(' || s[i] == ')') {
                // Jump to matching bracket
                i = match[i];

                // Change direction
                direction = -direction;
            }
            else {
                ans += s[i];
            }

            i += direction;
        }

        return ans;
    }
};
