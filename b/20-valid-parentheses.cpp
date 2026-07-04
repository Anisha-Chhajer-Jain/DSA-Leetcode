class Solution {
public:
    bool isValid(string s) {
        vector<char> st;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push_back(c);
            } 
            else {
                if (st.empty()) return false;
                
                char last = st.back();
                if ((c == ')' && last == '(') || 
                    (c == '}' && last == '{') || 
                    (c == ']' && last == '[')) {
                    st.pop_back(); 
                } else {
                    return false;
                }
            }
        }
        return st.empty();
    }
};
