class Solution {
public:
    bool check(TreeNode* root, TreeNode* subRoot)
    {
        if(root==NULL && subRoot==NULL)return true;
        if(root==NULL || subRoot==NULL)return false;

        if(root->val!=subRoot->val)return false;
        else return (check(root->left,subRoot->left)&&check(root->right,subRoot->right));
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL && subRoot==NULL)return true;

        if(root==NULL || subRoot==NULL)return false;

        if(root->val==subRoot->val)
        {
            if(check(root,subRoot))return true;
        }
        return isSubtree(root->left,subRoot)||isSubtree(root->right,subRoot);
    }
};