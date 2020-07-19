#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

int closestToTarget(vector<int>& arr, int target) {
    int N=arr.size();
    int count[32]={0};
    int X=arr[0];
    int ans=abs(X-target),start=-1;
    
    set<int> done;
    for(int i=0;i<N;i++)
    {
        if(!done.count(i))
        {
            int x=arr[i],j=0;
            while(x)
            {
                if(x%2==1)
                    count[j]++;
                x/=2;
                j++;
            }
            done.insert(i);
        }
        
        X=0;
        int mult=1;
        for(int j=0;j<30;j++,mult*=2)
            if(count[j]==(i-start))
                X+=mult;
        ans=min(ans,abs(target-X));
        
        if(X<=target)
        {
            start++;
            int x=arr[start],j=0;
            while(x)
            {
                if(x%2==1)
                    count[j]--;
                x/=2;
                j++;
            }
            i--;
        }                
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
    	int N;
    	cin>>N;
    	vector<int> arr(N);
    	for(int i=0;i<N;i++)
    		cin>>arr[i];
    	int target;
    	cin>>target;
    	cout<<closestToTarget(arr,target)<<endl;
    	
    }
}
