#include <bits/stdc++.h>
using namespace std;

struct Node {
    int info;
    Node *left, *right;
    Node(int x) : info(x), left(nullptr), right(nullptr) {}
};

typedef Node* Tree;

void init() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}

void inputNodes(Tree &T, int x) {
    if (!T) {
        T = new Node(x);
        return;
    }
    Node* current = T;
    while (true) {
        if (x < current->info) {
            if (current->left) {
                current = current->left;
            } else {
                current->left = new Node(x);
                break;
            }
        } else {
            if (current->right) {
                current = current->right;
            } else {
                current->right = new Node(x);
                break;
            }
        }
    }
}

void inputTree(Tree &T, int n) {
    while (n--) {
        int x;
        cin >> x;
        inputNodes(T, x);
    }
}

Tree findLCA(Tree root, int a, int b) {
    while (root) {
        if (root->info > a && root->info > b) {
            root = root->left;
        } else if (root->info < a && root->info < b) {
            root = root->right;
        } else {
            break;
        }
    }
    return root;
}

pair<int, int> findMinMaxOnPath(Tree root, int a, int b) {
    Tree lca = findLCA(root, a, b);
    int MIN = INT_MAX, MAX = INT_MIN;

    // Traverse from LCA to a
    Tree p = lca;
    while (p->info != a) {
        MIN = min(MIN, p->info);
        MAX = max(MAX, p->info);
        if (a < p->info) {
            p = p->left;
        } else {
            p = p->right;
        }
    }
    MIN = min(MIN, p->info);
    MAX = max(MAX, p->info);

    // Traverse from LCA to b
    p = lca;
    while (p->info != b) {
        MIN = min(MIN, p->info);
        MAX = max(MAX, p->info);
        if (b < p->info) {
            p = p->left;
        } else {
            p = p->right;
        }
    }
    MIN = min(MIN, p->info);
    MAX = max(MAX, p->info);

    return {MIN, MAX};
}

int main() {
    init();
    Tree T = nullptr;
    int n;
    cin >> n;
    inputTree(T, n);
    int s, e;
    cin >> s >> e;
    pair<int, int> result = findMinMaxOnPath(T, s, e);
    cout << result.first << " " << result.second << endl;
    return 0;
}