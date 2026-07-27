class Solution {
public:
    Node* cloneGraph(Node* node) {

        if (!node) return nullptr;

        unordered_map<Node*, Node*> mp;

        queue<Node*> q;

        mp[node] = new Node(node->val);
        q.push(node);

        while (!q.empty()) {

            Node* curr = q.front();
            q.pop();

            for (Node* neigh : curr->neighbors) {

                if (mp.find(neigh) == mp.end()) {
                    mp[neigh] = new Node(neigh->val);
                    q.push(neigh);
                }

                mp[curr]->neighbors.push_back(mp[neigh]);
            }
        }

        return mp[node];
    }
};