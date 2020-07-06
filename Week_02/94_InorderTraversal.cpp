//
// Created by miaochl on 2020-07-01.
//
#include "Util.h"

void inorderTraversal(TreeNode* pNode, vector<int>& res) {
    if (pNode == NULL) {
        return;
    }

    inorderTraversal(pNode->left, res);
    res.push_back(pNode->val);
    inorderTraversal(pNode->right, res);
}
// 1.递归中序遍历
vector<int> Solution::inorderTraversal_1(TreeNode* root)
{
    vector<int> res;
    if (root) {
        inorderTraversal(root, res);
    }

    return res;
}

// 2.辅助栈迭代中序遍历
vector<int> Solution::inorderTraversal_2(TreeNode* root)
{
    vector<int> res;
    stack<TreeNode*> stk;
    TreeNode* pNode = root;
    while (pNode != NULL || stk.size() > 0) {
        while (pNode) {
            stk.push(pNode);
            pNode = pNode->left;
        }
        pNode = stk.top();
        stk.pop();
        res.push_back(pNode->val);
        pNode = pNode->right;
    }
    return res;
}

void preorderTraversal(TreeNode* pNode, vector<int>& res) {
    if (pNode == NULL) {
        return;
    }

    res.push_back(pNode->val);
    preorderTraversal(pNode->left, res);
    preorderTraversal(pNode->right, res);
}

// 1.递归先序遍历
vector<int> Solution::preorderTraversal_1(TreeNode* root)
{
    vector<int> res;
    if (root) {
        preorderTraversal(root, res);
    }

    return res;
}
// 2.辅助栈迭代先序遍历
vector<int> Solution::preorderTraversal_2(TreeNode* root)
{
    vector<int> res;
    stack<TreeNode*> stk;
    TreeNode* pNode = root;
    while (pNode || stk.size()) {
        while (pNode) {
            res.push_back(pNode->val);
            if (pNode->right) {
                stk.push(pNode->right);
            }
            pNode = pNode->left;
        }
        pNode = stk.top();
        stk.pop();
    }
    return res;
}






void postorderTraversal(TreeNode* pNode, vector<int>& res) {
    if (pNode == NULL) {
        return;
    }

    postorderTraversal(pNode->left, res);
    postorderTraversal(pNode->right, res);
    res.push_back(pNode->val);
}

// 1.递归后序遍历
vector<int> Solution::postorderTraversal_1(TreeNode* root)
{
    vector<int> res;
    if (root) {
        postorderTraversal(root, res);
    }

    return res;
}

// 2.辅助栈迭代后序遍历
vector<int> Solution::postorderTraversal_2(TreeNode* root)
{
    vector<int> res;
    stack<TreeNode*> stk;
    unordered_map<TreeNode*, bool> umap;
    TreeNode* pNode = root;
    while (pNode || stk.size()) {
        while (pNode) {
            stk.push(pNode);
            pNode = pNode->left;
        }

        while (stk.size() && umap[stk.top()] == true) {
            pNode = stk.top();
            res.push_back(pNode->val);
            stk.pop();
        }

        if (stk.size()) {
            umap[stk.top()] = true;
            pNode = stk.top()->right;
        }
    }

    return res;
}