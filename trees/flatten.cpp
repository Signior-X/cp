/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


TreeNode* Solution::flatten(TreeNode* A) {
    if (A == NULL) return A;

    TreeNode *root = A;

    while(root != NULL) {
        // Loop to the extream right of the left subtree
        if (root -> left != NULL) {

            TreeNode *p = root -> left;
            while(p -> right != NULL) p = p -> right;

            p -> right = root -> right;
            root -> right = root -> left;
            root -> left = NULL;

        }

        root = root -> right;
    }

    return A;
}
