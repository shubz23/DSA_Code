class Solution {
  public:
    int *checkDoorStatus(int N) {
        int* doors = new int[N];  
        
        for (int i = 0; i < N; ++i) {
            doors[i] = 0;
        }

        for (int i = 1; i <= N; ++i) {
            for (int j = i; j <= N; j += i) {
                doors[j - 1] = 1 - doors[j - 1];  
            }
        }

        return doors;
    }
};