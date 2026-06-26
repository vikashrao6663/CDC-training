class Codec {
public:

    // Serialize
    void dfsSerialize(TreeNode* root, string &s) {
        if(root == NULL) {
            s += "null,";
            return;
        }

        s += to_string(root->val) + ",";
        dfsSerialize(root->left, s);
        dfsSerialize(root->right, s);
    }

    string serialize(TreeNode* root) {
        string s = "";
        dfsSerialize(root, s);
        return s;
    }

    // Deserialize
    TreeNode* dfsDeserialize(queue<string> &q) {

        if(q.front() == "null") {
            q.pop();
            return NULL;
        }

        TreeNode* root = new TreeNode(stoi(q.front()));
        q.pop();

        root->left = dfsDeserialize(q);
        root->right = dfsDeserialize(q);

        return root;
    }

    TreeNode* deserialize(string data) {

        string temp = "";
        queue<string> q;

        for(char c : data) {
            if(c == ',') {
                q.push(temp);
                temp = "";
            } else {
                temp += c;
            }
        }

        return dfsDeserialize(q);
    }
};