#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

bool mycompare(pair<double,bool> A, pair<double,bool> B)
{
    if(A.first<B.first)
        return true;
    else if(A.first>B.first)
        return false;
    else
        return (A.second==1);
}
int helper(vector<complex<double>> &arr, double dist[100][100], int i, int r) 
{ 
    int N=arr.size();
    vector<pair<double,bool>> angles; 

    for (int j=0;j<N;j++) 
    { 
        if (i!=j && dist[i][j]<=2*r) 
        {  
            double B=acos(dist[i][j]/(2*r));
            double A=arg(arr[j]-arr[i]); 
            double alpha=A-B; 
            double beta=A+B; 
            angles.push_back({alpha,1}); 
            angles.push_back({beta,0}); 
        } 
    }
    sort(angles.begin(),angles.end(),mycompare); 
    int count=1,ans=1;
    for (auto it=angles.begin();it!=angles.end();it++) 
    { 
        if (it->second) 
            count++;
        else
            count--; 
        ans=max(ans,count);
    }
    return ans;
}
int numPoints(vector<vector<int>>& points, int r) {
    int N=points.size();
    vector<complex<double>> arr(N);
    for(int i=0;i<N;i++)
    {
        complex<double> x(points[i][0],points[i][1]);
        arr[i]=x;
    }
    double dist[100][100];
    for (int i=0;i<N-1;i++) 
        for (int j=i+1;j<N;j++) 
            dist[i][j]=dist[j][i]=abs(arr[i]-arr[j]);
    
    
    int ans=0; 
    for (int i=0;i<N;i++) 
        ans=max(ans,helper(arr,dist,i,r)); 

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
    	int N,R;
    	cin>>N>>R;
    	vector<vector<int>> arr(N);
    	for(int i=0;i<N;i++)
    	{
    		vector<int> temp(2);
    		cin>>temp[0]>>temp[1];
    		arr[i]=temp;
    	}
    	cout<<numPoints(arr,R)<<endl;

    	
    }
}