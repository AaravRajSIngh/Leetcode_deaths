class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp;
        unordered_set<int> child;

        for (auto &x : descriptions) {
            int p = x[0];
            int c = x[1];
            int lf = x[2];

            if (!mp.count(p)) mp[p] = new TreeNode(p);
            if (!mp.count(c)) mp[c] = new TreeNode(c);

            if (lf)
                mp[p]->left = mp[c];
            else
                mp[p]->right = mp[c];

            child.insert(c);
        }

        for (auto &it : mp) {
            if (!child.count(it.first))
                return it.second;
        }

        return nullptr;
    }
};