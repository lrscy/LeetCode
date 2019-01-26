/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int l = 0, r = 0, ret = 0;
        dfs( root, ret );
        ret = max( ret, l + r );
        return ret;
    }
    
    int dfs( TreeNode *root, int& m ) {
        if( !root ) return 0;
        int l = dfs( root->left, m );
        int r = dfs( root->right, m );
        m = max( m, l + r );
        return max( l, r ) + 1;
    }
};
