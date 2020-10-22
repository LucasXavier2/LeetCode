//111. Minimum Depth of Binary Tree
//Description - https://leetcode.com/problems/minimum-depth-of-binary-tree/
//22/10/2020

//Solution 1 - Recursive
class Solution {
private:
    int minDepthAux(TreeNode* root, int depth) {
        if (!root->left && !root->right) {
            return depth;
        }
        depth++;
        
        int left = INT_MAX;
        int right = INT_MAX;
        
        if (root->left) left = minDepthAux(root->left, depth);
        if (root->right) right = minDepthAux(root->right, depth);
        return min(left, right);
    }
    
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        int depth = 1;

        return minDepthAux(root, depth);
    }
};


//Solution 2 - BFS
class Solution {    
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        queue<pair<TreeNode*, int>> nodes_depth;
        nodes_depth.push(pair(root, 1));
        
        while (!nodes_depth.empty()) {
            TreeNode* node = nodes_depth.front().first;
            int depth = nodes_depth.front().second;
            nodes_depth.pop();
            
            if (!node->left && !node->right) return depth;
            if (node->left) nodes_depth.push(pair(node->left, depth + 1));
            if (node->right) nodes_depth.push(pair(node->right, depth + 1));
        }
        
        return 0;
    }
};


