
class Solution {
public:
long long mat[3][3], ans[3][3];
       void mul(long long ans[3][3], long long mat[3][3], long long m)
       {
        long long ans1[3][3]; 
        memset(ans1,0,sizeof(ans1));
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                for(int k=0; k<3; k++)
                {
                    ans1[i][j] += (ans[i][k]*mat[k][j]);   
                    ans1[i][j] %= m;    
                }
            }
        }
        
        for(int i=0; i<3; i++)
            for(int j=0; j<3; j++)
                ans[i][j]=ans1[i][j];
    }
    
    void mat_exp(long long n, long long m)
    {
        while(n>0)
        {
            if(n&1)
            mul(ans, mat, m);  
            mul(mat,mat,m);   
            n /= 2;            
                                   
        }
    }

    long long genFibNum(long long a, long long b, long long c, long long n, long long m) {
        memset(ans,0,sizeof(ans));   
        ans[0][0] = ans[1][1] = ans[2][2] = 1;   
        mat[0][0] = a;   
        mat[0][1] = b;
        mat[0][2] = mat[1][0] = mat[2][2] = 1;
        mat[1][1] = mat[1][2] = mat[2][0] = mat[2][1] = 0;
        if(n<=2)
            return (1%m);   
        else
        {
            mat_exp(n-2,m);   
            return (ans[0][0] + ans[0][1] + c*ans[0][2])%m;   
        }
    }
};
    