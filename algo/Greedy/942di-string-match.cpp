class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n=s.size();
        int i=0;
        vector<int> ans;
        
        for(char c:s){
            if(c=='I'){
                ans.push_back(i);
                i++;
            }
            if(c=='D'){
                ans.push_back(n);
                n--;
            }
        }
        ans.push_back(i);
        return ans;
    }
};