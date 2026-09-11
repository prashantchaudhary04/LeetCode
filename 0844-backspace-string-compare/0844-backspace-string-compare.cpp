class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.size() - 1;
        int j = t.size() - 1;

        while (i >= 0 || j >= 0) {

            int skip = 0;

            while (i >= 0 && (s[i] == '#' || skip > 0)) {
                if (s[i] == '#')
                    skip++;
                else
                    skip--;

                i--;
            }

            skip = 0;

            while (j >= 0 && (t[j] == '#' || skip > 0)) {
                if (t[j] == '#')
                    skip++;
                else
                    skip--;

                j--;
            }

            if (i >= 0 && j >= 0) {
                if (s[i] != t[j])
                    return false;
            }
            else if (i >= 0 || j >= 0) {
                return false;
            }

            i--;
            j--;
        }

        return true;
    }
};