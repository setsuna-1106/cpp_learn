class Solution {
public:
    int balancedStringSplit(string s) {
        int R=0,L=0,count=0;
        for(char c:s){
            if(c=='R') R++;
            else L++;
            if(R&&R==L){
                count++;
                R=0;
                L=0;
            }
        }
        return count;
    }
};