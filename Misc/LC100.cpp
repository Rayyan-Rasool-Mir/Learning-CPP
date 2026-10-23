#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <numeric>
#include <cmath>
#include <climits>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int getSize(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    return 1 + getSize(root->left) + getSize(root->right);
}

bool check(TreeNode *p, TreeNode *q)
{
    if (p == nullptr && q == nullptr)
    {
        return true;
    }

    if (p == nullptr || q == nullptr)
    {
        return false;
    }

    if (p->val != q->val)
    {
        return false;
    }

    return check(p->left, q->left) && check(p->right, q->right);
}

bool isSameTree(TreeNode *p, TreeNode *q)
{
    int ps = getSize(p);
    int qs = getSize(q);

    if (ps != qs)
    {
        return false;
    }

    return check(p, q);
}

int main() {
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);

    cout << boolalpha << isSameTree(p, q) << endl;

    return 0;
}