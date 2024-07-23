class Solution {
public:
    bool checkSymm(TreeNode* root1,TreeNode* root2)
    {
        if(root1==NULL || root2==NULL)return root1==root2;
        if(root1->val!=root2->val)return false;

        return checkSymm(root1->left,root2->right) && checkSymm(root1->right,root2->left);
    }
    bool isSymmetric(TreeNode* root) {
        return checkSymm(root->left,root->right);
    }
};