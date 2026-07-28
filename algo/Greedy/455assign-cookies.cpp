class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end(), greater<int>());
        sort(s.begin(), s.end(), greater<int>());
        int count=0;
        for(int i=0;i<g.size();i++){
            for(int j=0;j<s.size();j++){
                if(s[j]){
                    if(g[i]<=s[j]){
                        s[j]=0;
                        count++;
                        break;
                    }else{
                        break;
                    }
                }
            }
        }
        return count;
    }
};
/*使用快慢指针，从而减少重复判断
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int num = 0;
        int i = 0, j = 0;
        while (i < g.size() && j < s.size()) {
            if (g[i] <= s[j]) {
                i++;
                j++;
                num++;
            } else {
                j++;
            }
        }
        return num;
    }
};
*/