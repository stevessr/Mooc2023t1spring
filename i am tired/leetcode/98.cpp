
// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool isValidBST(TreeNode *root)
    {
        if (root == nullptr)
        {
            return true;
        }
        else if (root->left == nullptr)
        {
            if (root->right == nullptr)
            {
                return true;
            }
            else
            {
                return (root->val < root->right->val)&& isValidBST(root->right);
            }
        }
        else if (root->right == nullptr)
        {
            return (root->val > root->left->val) && isValidBST(root->left);
        }else {
            return (root->val > root->left->val) && (root->val < root->right->val) && isValidBST(root->left) && isValidBST(root->right);
        }
    }
};