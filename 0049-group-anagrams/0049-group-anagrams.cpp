class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        unordered_map<string, vector<string>>count;

        for(int i=0 ; i<strs.size() ; i++){
            string temp=strs[i];
            sort(temp.begin(), temp.end());

            count[temp].push_back(strs[i]);
        }

        for(auto it : count){
            ans.push_back(it.second);
        }

        return ans;


    }
};