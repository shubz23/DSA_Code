
class Solution
{
    public:
    //Function to return list containing first n fibonacci numbers.
    vector<long long> printFibb(int n) 
    {
        vector<long long> fibSeries(n);

        // The first two Fibonacci numbers are 1 and 1.
        if (n >= 1) fibSeries[0] = 1;
        if (n >= 2) fibSeries[1] = 1;

        // Calculate the remaining Fibonacci numbers.
        for (int i = 2; i < n; ++i) {
            fibSeries[i] = fibSeries[i - 1] + fibSeries[i - 2];
        }

        return fibSeries;
    }
};




