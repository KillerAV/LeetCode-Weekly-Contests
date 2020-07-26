#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

class TreeNode{
public:
	TreeNode *left, *right;
	int value;
	TreeNode(int value){
		this->value=value;
		left=right=NULL;
	}
};

vector<int> func(TreeNode *root, int distance, int &ans, int height=0)
{
    vector<int> a;
    if(!root)
        return a;
    if(!root->left && !root->right)
    {
        a.push_back(height);
        return a;
    }
    
    vector<int> left=func(root->left,distance,ans,height+1);
    vector<int> right=func(root->right,distance,ans,height+1);
    sort(left.begin(),left.end());
    sort(right.begin(),right.end());
    for(int i=0;i<left.size();i++)
    {
        int index=upper_bound(right.begin(),right.end(),distance-(left[i]-2*height))-right.begin();
        ans+=index;
    }
    vector<int> temp;
    for(int i=0;i<left.size();i++)
        temp.push_back(left[i]);
    for(int i=0;i<right.size();i++)
        temp.push_back(right[i]);
    return temp;
}
int countPairs(TreeNode* root, int distance) {
    
    int ans=0;
    func(root,distance,ans);
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
    	int n,r;
    	cin>>n>>r;
    	TreeNode *root = new TreeNode(r);
    	unordered_map<int,TreeNode*> M;
    	M[r]=root;
    	for(int i=0;i<n-1;i++)
    	{
    		int x,y,dir;
    		cin>>x>>y>>dir;
    		TreeNode *a,*b;
    		if(M.count(x))
    			a=M[x];
    		else
    		{
    			a=new TreeNode(x);
    			M[x]=a;
    		}
    		if(M.count(y))
    			b=M[y];
    		else
    		{
    			b=new TreeNode(y);
    			M[y]=b;
    		}
    		if(dir==0)
    			a->left=b;
    		else
    			a->right=b;
    	}
    	int distance;
    	cin>>distance;

    	cout<<countPairs(root,distance)<<endl;
    }
}
