
class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        int n = S.length();
        string result = "";
        int wordEnd = n;
        
        for(int i = n - 1; i >= 0; i--) {
            
            // When a dot is found or we reach the start of the string.
            if (S[i] == '.' || i == 0) {
                if (i == 0) {
                    result += S.substr(i, wordEnd - i);
                } else {
                    result += S.substr(i + 1, wordEnd - i - 1);
                    result += '.';
                    wordEnd = i;
                }
            }
        }
        return result;
    } 
};