#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

int dp[500][500];
int func(vector<int>& nums1, vector<int>& nums2, int i=0, int j=0) {
    if(i==nums1.size() || j==nums2.size())
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    int opt1=func(nums1,nums2,i+1,j+1)+nums1[i]*nums2[j];
    int opt2=func(nums1,nums2,i,j+1);
    int opt3=func(nums1,nums2,i+1,j);
    int ans=max(opt1,max(opt2,opt3));
    dp[i][j]=ans;
    return ans;
}
int maxDotProduct(vector<int>& nums1, vector<int>& nums2, int i=0, int j=0) {
    for(int i=0;i<nums1.size();i++)
        for(int j=0;j<nums2.size();j++)
            dp[i][j]=-1;
    bool p1=0,p2=0,n1=0,n2=0;
    int max1=INT_MIN,min1=INT_MAX,max2=INT_MIN,min2=INT_MAX;
    for(int i=0;i<nums1.size();i++)
    {
        if(nums1[i]<0)
            n1=1;
        else
            p1=1;
        max1=max(max1,nums1[i]);
        min1=min(min1,nums1[i]);
    }
    for(int i=0;i<nums2.size();i++)
    {
        if(nums2[i]<0)
            n2=1;
        else
            p2=1;
        max2=max(max2,nums2[i]);
        min2=min(min2,nums2[i]);
    }
    
    if(!p1 && !n2)
        return max1*min2;
    else if(!n1 && !p2)
        return min1*max2;
    else
        return func(nums1,nums2); 
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
        int N1,N2;
        cin>>N1>>N2;
        vector<int> A(N1),B(N2);
        for(int i=0;i<N1;i++)
            cin>>A[i];
        for(int i=0;i<N2;i++)
            cin>>B[i];
        cout<<maxDotProduct(A,B)<<endl;
    }
}