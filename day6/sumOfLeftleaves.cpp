class Solution {
private :
int sumleft(TreeNode* root,int flag)
{
   if(root==NULL)return 0;
   if(root->left==NULL && root->right==NULL )return (flag*root->val);

   return sumleft(root->left,1)+sumleft(root->right,0);
}
public:
    int sumOfLeftLeaves(TreeNode* root) {

    return sumleft(root,0);
    }
};