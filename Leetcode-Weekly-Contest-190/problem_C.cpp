#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

class TreeNode {
public:
	TreeNode *left, *right;
	int val;
	TreeNode(int val) {
		left=right=0;
		this->val=val;
	}
};
int func(TreeNode *root, int *arr)
{
    if(!root)
        return 0;
    arr[root->val]++;
    if(!root->left && !root->right)
    {
        int odd=0;
        for(int i=0;i<10;i++)
            if(arr[i]%2==1)
                odd++;
        arr[root->val]--;
        if(odd<=1)
            return 1;
        return 0;
    }
    int left=func(root->left,arr);
    int right=func(root->right,arr);
    arr[root->val]--;
    return left+right;
}
int pseudoPalindromicPaths (TreeNode* root) {
    int arr[10]={0};
    return func(root,arr);
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
    	TreeNode *root=NULL;
    	int N,root_node;
    	cin>>root_node>>N;
    	TreeNode *node[N+1];
    	for(int i=1;i<=N;i++)
    		node[i]=new TreeNode(i);
    	for(int i=1;i<=N;i++)
    	{
    		int left,right;
    		cin>>left>>right;
    		if(left!=-1)
    			node[i]->left=node[left];
    		if(right!=-1)
    			node[i]->right=node[right];
    	}

    	cout<<pseudoPalindromicPaths(node[root_node])<<endl;
    }
}