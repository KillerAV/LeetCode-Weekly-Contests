#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

int numSubmat(vector<vector<int>>& mat) {
    int N=mat.size();
    int M=mat[0].size();
    
    int dp[N][M];
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
        {
            dp[i][j]=0;
            if(i!=0)
                dp[i][j]+=dp[i-1][j];
            if(j!=0)
                dp[i][j]+=dp[i][j-1];
            if(i!=0 && j!=0)
                dp[i][j]-=dp[i-1][j-1];
            dp[i][j]+=mat[i][j];
        }
    
    int ans=0;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            for(int k=i;k<N;k++)
            {
                int start=j,end=M-1,index=j-1;
                while(start<=end)
                {
                    int mid=(start+end)/2;
                    int temp=dp[k][mid];
                    if(i!=0)
                        temp-=dp[i-1][mid];
                    if(j!=0)
                        temp-=dp[k][j-1];
                    if(i!=0 && j!=0)
                        temp+=dp[i-1][j-1];
                    if(temp==(k-i+1)*(mid-j+1))
                    {
                        index=mid;
                        start=mid+1;
                    }
                    else
                        end=mid-1;
                }
                ans+=index-j+1;
            }
                
    return ans;
}
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    while(T--)
    {
    	int N,M;
    	cin>>N>>M;
    	vector<vector<int>> mat(N);
    	for(int i=0;i<N;i++)
    	{
    		vector<int> temp(M);
    		for(int i=0;i<M;i++)
    			cin>>temp[i];
    		mat[i]=temp;
    	}
    	cout<<numSubmat(mat)<<endl;
    }    
}
