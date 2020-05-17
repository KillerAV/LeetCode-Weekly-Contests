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
void func(TreeNode *root, int &count, int maxValue=INT_MIN)
{
    if(!root)
        return;
    
    if(root->val>=maxValue)
        count++;
    func(root->left,count,max(maxValue,root->val));
    func(root->right,count,max(maxValue,root->val));
}
int goodNodes(TreeNode* root) { 
    int count=0;
    func(root,count);
    return count;
    
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

    	cout<<goodNodes(node[root_node])<<endl;
    }

}