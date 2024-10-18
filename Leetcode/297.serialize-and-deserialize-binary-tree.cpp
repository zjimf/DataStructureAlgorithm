/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    string serialize(TreeNode *root) {
        string out = "";
        serialize(root, out);
        return out;
    }

    TreeNode *deserialize(string data) {
        int pos = 0;
        return deserialize(data, pos);
    }

private:
    void serialize(TreeNode *root, string &out) {
        if (root) {
            out += to_string(root->val) + ",";
            serialize(root->left, out);
            serialize(root->right, out);
        } else {
            out += "#,";
        }
    }

    TreeNode *deserialize(const string &data, int &pos) {
        if (pos >= data.size())
            return nullptr;

        int commaPos = data.find(',', pos);
        string token = data.substr(pos, commaPos - pos);
        pos = commaPos + 1;

        if (token == "#") {
            return nullptr;
        }

        TreeNode *node = new TreeNode(stoi(token));
        node->left = deserialize(data, pos);
        node->right = deserialize(data, pos);
        return node;
    }
};

// 測試用例
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end
