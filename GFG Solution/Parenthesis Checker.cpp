class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack<char> s;
        unordered_map<char, char> matchingBrackets = {{')', '('}, {'}', '{'}, {']', '['}};
        
        for (char c : x) {
            if (matchingBrackets.find(c) == matchingBrackets.end()) {
               
                s.push(c);
            } else {
               
                if (s.empty() || s.top() != matchingBrackets[c]) {
                    return false;
                }
                s.pop();
            }
        }
        
        return s.empty();
    }

};