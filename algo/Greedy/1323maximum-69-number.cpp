class Solution {
public:
    int maximum69Number (int num) {
        int digit[4];
        for(int i=0;i<4;i++){
            digit[i]=num%10;
            num=num/10;
        }
        for(int i=3;i>=0;i--){
            if(digit[i]==6){
                digit[i]=9;
                break;
            }
        }
        int ans=0;
        for(int i=3;i>=0;i--){
            ans*=10;
            ans+=digit[i];
        }
        return ans;
    }
};