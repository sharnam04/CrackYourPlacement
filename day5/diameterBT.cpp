class Solution {
public:
    int height(int& ans,TreeNode* root)
    {
      if(root==NULL)return 0;
      int lh=height(ans,root->left);
      int rh=height(ans,root->right);

      ans=max(ans,lh+rh);
      return 1+max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        height(ans,root);
        return ans;
    }
};