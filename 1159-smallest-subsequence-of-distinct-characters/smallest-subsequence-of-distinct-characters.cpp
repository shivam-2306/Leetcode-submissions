class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> charCount(26, 0);
        for (auto i : s) {
            charCount[i - 'a']++;
        }

        vector<bool> visited(26, false);
        stack<char> st;

        st.push(s[0]);
        visited[s[0] - 'a'] = true;
        charCount[s[0] - 'a']--;

        for (int i = 1; i < s.length(); i++) {

            charCount[s[i] - 'a']--;

            if (visited[s[i] - 'a']) {
                continue;
            }

            while (!st.empty() && st.top() > s[i]) {
                int temp = st.top() - 'a';

                if (charCount[temp] > 0) {
                    st.pop();
                    visited[temp] = false;
                } else {
                    break;
                }
            }

            st.push(s[i]);
            visited[s[i] - 'a'] = true;
        }

        string result;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        reverse(result.begin(), result.end());
        return result;
    }
};