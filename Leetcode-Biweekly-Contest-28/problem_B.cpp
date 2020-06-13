#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

class SubrectangleQueries {
public:
    vector<vector<int>> arr;
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        arr=rectangle;
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        for(int i=row1;i<=row2;i++)
            for(int j=col1;j<=col2;j++)
                arr[i][j]=newValue;
    }
    
    int getValue(int row, int col) {
        return arr[row][col];
    }
};

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
    	vector<vector<int>> arr(N);
    	for(int i=0;i<N;i++)
    	{
    		vector<int> temp(M);
    		for(int j=0;j<M;j++)
    			cin>>temp[j];
    		arr[i]=temp;
    	}
    	SubrectangleQueries queryObject(arr);
    	int Q;
    	cin>>Q;
    	while(Q--)
    	{
    		int type;
    		cin>>type;
    		if(type==1)
    		{
    			int row1,row2,col1,col2,val;
    			cin>>row1>>col1>>row2>>col2>>val;
    			queryObject.updateSubrectangle(row1,col1,row2,col2,val);
    		}
    		else
    		{
    			int row,col;
    			cin>>row>>col;
    			cout<<queryObject.getValue(row,col)<<endl;
    		}
    	}
    }
    
}
