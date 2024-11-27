class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        if (root == nullptr) {
            return true; 
        }
        queue<TreeNode*> q;
        q.push(root);
        bool flag = true; 
        
        while (!q.empty()) {
            int x = q.size(); 
            int prev = flag ? INT_MIN : INT_MAX; 
            
            for (int i = 0; i < x; i++) {
                TreeNode* frontNode = q.front();
                q.pop();
                
                if (flag) {
                    if (frontNode->val % 2 == 0 || frontNode->val <= prev) {
                        return false;
                    }
                } else {
                    if (frontNode->val % 2 != 0 || frontNode->val >= prev) {
                        return false;
                    }
                }
                
                prev = frontNode->val; 
                
                if (frontNode->left) q.push(frontNode->left);
                if (frontNode->right) q.push(frontNode->right);
            }
            
            flag = !flag;
        }
        
        return true; 
    }
};
