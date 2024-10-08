/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
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
    vector<int> rightSideView(TreeNode *root) {
        vector<int> result;
        queue<TreeNode *> q;

        if(root){
            q.push(root);
        }

        while(!q.empty()){
            int len = q.size();

            for(int i = 0; i < len; i++){
                TreeNode * front = q.front();
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);

                if(i == len-1){
                    result.push_back(front->val);
                }

                q.pop();
            }
        }
        return result;
    }
};
// @lc code=end
