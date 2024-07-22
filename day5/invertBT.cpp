
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL)return NULL;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode*node=q.front();
            q.pop();
            TreeNode*temp=node->left;
            node->left=node->right;
            node->right=temp;
            if(node->left)q.push(node->left);
            if(node->right)q.push(node->right);
        }
        return root;
    }
};
// *************************************************
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL)return root;

        // TreeNode*left=NULL;TreeNode*right=NULL;
        if(root->left)invertTree(root->left);
        if(root->right)invertTree(root->right);
        
        TreeNode*temp=root->left;
        root->left=root->right;
        root->right=temp;
        return root;
    }
};