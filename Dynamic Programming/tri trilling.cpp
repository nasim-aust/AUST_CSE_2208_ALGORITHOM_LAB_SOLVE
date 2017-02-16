#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
using namespace std;
long long unsigned dp[31];
long long unsigned int f(int n){
    if(dp[n] != -1){
        return dp[n];
    }
    return dp[n] = 4*f(n-2) -f(n-4);
}
int main()
{
    memset(dp, -1, sizeof(dp));
    dp[0] = 1;
    dp[1] = 0;
    dp[2] = 3;
    dp[3] = 0;
    dp[4] = 11;
    int n;
    cin>>n;
    while(n!=-1){
        cout<<f(n)<<endl;
        cin>>n;
    }
    return 0;
}
