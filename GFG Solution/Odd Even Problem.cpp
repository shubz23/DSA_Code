
class Solution {
  public:
    string oddEven(string s) {
        int a=0, b=0;
        
        vector<int>count(27,0);
        for(int i=0;i<s.length();i++){
            count[s[i]-'a'+1]++;
        }
        
        for(int i=1;i<=26;i++){
            if(count[i]!=0 && count[i]%2==0 && i%2==0){
                a++;
            }
            else if(count[i]%2==1 && i%2==1){
                b++;
            }
        }
        int sum = a+b;
        if(sum%2==1) return "ODD";
        else return "EVEN";
    }
};