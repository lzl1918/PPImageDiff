#include<bits/stdc++.h>

using namespace std;
using vec = vector<int>;
using vec2 = vector<vec>;

vec LCS(vec& s1, vec& s2, int len) {
    vec2 mark, dp;
    for(int i = 0; i <= len; i++) {
        mark.push_back(vec(len+1, 0));
        dp.push_back(vec(len+1, 0));
    }
    for(int i = 0; i <= len; i++) {
        mark[i][0] = 1;
        mark[0][i] = -1;
    }
    for(int i = 1; i<=len; i++)  
    {  
        for(int j = 1; j<=len; j++)  
        {  
            if(s1[i-1]==s2[j-1])  
            {  
                dp[i][j] = dp[i-1][j-1]+1;  
                mark[i][j] = 0;  
            }  
            else if(dp[i-1][j]>=dp[i][j-1])  
            {  
                dp[i][j] = dp[i-1][j];  
                mark[i][j] = 1;  
            }  
            else  
            {  
                dp[i][j] = dp[i][j-1];  
                mark[i][j] = -1;  
            }  
        }  
    }
    //printf("lcs = %d\n",dp[len][len]);
    
    //backtrack
    vec res, vis = vec(10, 0); // record all the index of number non-matched
    int pos1 = len, pos2 = len;
    while(pos1 > 0 && pos2 > 0) {
        if(!mark[pos1][pos2]) {
            //printf("%d\n",s1[pos1]);
            vis[pos1] = 1; //only mark the non-matching index of first array
            pos1--; pos2--;
        }
        else if(mark[pos1][pos2] == 1) pos1--;
        else pos2--;
    }
    for(int i = 1; i <= len; i++)
        if(!vis[i]) res.push_back(i);
    return res;
}

int main() {
    vec v1 = {1,2,3,4,5}, v2 = {2,2,3,5,2};
    vec res = LCS(v1, v2, 5);
    for(auto idx: res) printf("%d ",idx);
}
