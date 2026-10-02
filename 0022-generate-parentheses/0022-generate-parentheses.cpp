
class Solution {
public:
    void backtrack(string current, int open, int close, int n,
                   vector<string>& result) {
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }

        // Add opening parenthesis
        if (open < n) {
            backtrack(current + "(", open + 1, close, n, result);
        }

        // Add closing parenthesis
        if (close < open) {
            backtrack(current + ")", open, close + 1, n, result);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack("", 0, 0, n, result);
        return result;
    }
};