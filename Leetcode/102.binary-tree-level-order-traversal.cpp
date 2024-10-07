/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> result;
    
    vector<vector<int>> levelOrder(TreeNode *root) {
        queue<TreeNode *> q;
        if(root){
            q.push(root);
        }

        while(!q.empty()){
            vector<int> curVec;
            int size = q.size();

            for(int i = 0; i < size; i++){
                TreeNode * front = q.front();
                q.pop();
                curVec.push_back(front->val);
                if(front->left)
                    q.push(front->left);
                if(front->right)
                    q.push(front->right);
            }
            result.push_back(curVec);
        }
    return result;
    }
};
// @lc code=end
