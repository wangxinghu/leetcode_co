// Source : https://oj.leetcode.com/problems/balanced-binary-tree/
// Author : Hao Chen
// Date   : 2014-06-28

/********************************************************************************** 
* 
* Given a binary tree, determine if it is height-balanced.
* 
* For this problem, a height-balanced binary tree is defined as a binary tree in which 
* the depth of the two subtrees of every node never differ by more than 1.
* 
*               
**********************************************************************************/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode *root) {
        if (root==NULL) return true;
        
        int left = treeDepth(root->left); 
        int right = treeDepth(root->right);
        
        if (left-right>1 || left-right < -1) {
            return false;
        }
        return isBalanced(root->left) && isBalanced(root->right);
    }
    
    int treeDepth(TreeNode *root) {
        if (root==NULL){
            return 0;
        }
        
        int left=1, right=1;
        
        left += treeDepth(root->left);
        right += treeDepth(root->right);
        
        return left>right?left:right;
    }

};
