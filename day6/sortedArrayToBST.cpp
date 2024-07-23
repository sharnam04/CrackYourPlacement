class Solution {
public:
    TreeNode* SortedArray(vector<int>& nums,int s,int e)
    {
        if(s>e)return NULL;
        // if(s==e)
        // {
        //     TreeNode*temp=new TreeNode(nums[s]);
        //     return temp;
        // }
        int mid=(e-s)/2 + s;
        TreeNode*node=new TreeNode(nums[mid]);
        node->left=SortedArray(nums,s,mid-1);
        node->right=SortedArray(nums,mid+1,e);
        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        return SortedArray(nums,0,n-1);
    }
};