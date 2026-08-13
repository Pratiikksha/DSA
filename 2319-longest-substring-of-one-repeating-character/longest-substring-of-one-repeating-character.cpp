class Solution {
private:
    struct Node {
        char leftChar;
        char rightChar;
        int length;
        int prefix;
        int suffix;
        int best;
    };

    vector<Node> tree;

    Node mergeNodes(const Node& left, const Node& right) {
        Node res;

        res.leftChar = left.leftChar;
        res.rightChar = right.rightChar;
        res.length = left.length + right.length;

        // Prefix
        res.prefix = left.prefix;

        if (left.rightChar == right.leftChar &&
            left.prefix == left.length) {
            res.prefix = left.length + right.prefix;
        }

        // Suffix
        res.suffix = right.suffix;

        if (left.rightChar == right.leftChar &&
            right.suffix == right.length) {
            res.suffix = right.length + left.suffix;
        }

        // Best
        res.best = max(left.best, right.best);

        if (left.rightChar == right.leftChar) {
            res.best = max(res.best,
                           left.suffix + right.prefix);
        }

        return res;
    }

    void build(int node, int start, int end, const string& s) {
        if (start == end) {
            tree[node] = {
                s[start],
                s[start],
                1,
                1,
                1,
                1
            };
            return;
        }

        int mid = start + (end - start) / 2;

        build(2 * node, start, mid, s);
        build(2 * node + 1, mid + 1, end, s);

        tree[node] = mergeNodes(
            tree[2 * node],
            tree[2 * node + 1]
        );
    }

    void update(int node, int start, int end,
                int index, char ch) {

        if (start == end) {
            tree[node] = {
                ch,
                ch,
                1,
                1,
                1,
                1
            };
            return;
        }

        int mid = start + (end - start) / 2;

        if (index <= mid) {
            update(2 * node, start, mid, index, ch);
        } else {
            update(2 * node + 1, mid + 1, end, index, ch);
        }

        tree[node] = mergeNodes(
            tree[2 * node],
            tree[2 * node + 1]
        );
    }

public:
    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {
        int n = s.size();

        tree.assign(4 * n + 5, {});

        build(1, 0, n - 1, s);

        vector<int> answer;

        for (int i = 0; i < queryIndices.size(); i++) {
            update(
                1,
                0,
                n - 1,
                queryIndices[i],
                queryCharacters[i]
            );

            answer.push_back(tree[1].best);
        }

        return answer;
    }
};