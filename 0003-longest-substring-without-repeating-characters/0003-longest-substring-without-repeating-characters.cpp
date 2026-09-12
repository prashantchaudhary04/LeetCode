class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int>temp;

        int left=0;
        int ans=0;

        for(int right=0 ; right<s.size() ; right++){
            char ch=s[right];
            if(temp.count(ch) && temp[ch]>=left){
                left=temp[ch]+1;
            }

            temp[ch]=right;
            ans=max(ans, right-left+1);
        }

        return ans;
    }
};