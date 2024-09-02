class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b){
        
        int f[26];
        memset(f,0,sizeof(f));
        for(auto e:a)
        f[e-'a']++;
        for(auto e:b)
        f[e-'a']--;
        for(auto e:f)
        if(e!=0)
        return false;
        return 1;
    }
};