#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int data;
    struct TreeNode*right;
    struct TreeNode*left;
    TreeNode(int val)
    {
        data=val;
        right=NULL;
        left=NULL;
        
    }
};
//preorder postorder and inorder in one go
class Solution {

public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<pair<TreeNode*,int>> st; 
        st.push({root, 1}); 
        vector<int> pre, in, post;
        if(root == NULL) return post;

        while(!st.empty()) {
            auto it = st.top(); 
            st.pop(); 

            // this is part of pre
            // increment 1 to 2 
            // push the left side of the tree
            if(it.second == 1) {
                pre.push_back(it.first->data); 
                it.second++; 
                st.push(it); 

                if(it.first->left != NULL) {
                    st.push({it.first->left, 1}); 
                }
            }

            // this is a part of in 
            // increment 2 to 3 
            // push right 
            else if(it.second == 2) {
                in.push_back(it.first->data); 
                it.second++; 
                st.push(it); 

                if(it.first->right != NULL) {
                    st.push({it.first->right, 1}); 
                }
            }
            // don't push it back again 
            else {
                post.push_back(it.first->data); 
            }
        } 

        return post; 
    }
};
//to find maximum depth of a binary tree
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0; 
        
        int lh = maxDepth(root->left); 
        int rh = maxDepth(root->right); 
        
        return 1 + max(lh, rh); 
    }
};
//to find whether it is a balanced binary tree
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return dfsHeight (root) != -1;
    }
    int dfsHeight (TreeNode *root) {
        if (root == NULL) return 0;
        
        int leftHeight = dfsHeight (root -> left);
        if (leftHeight == -1) return -1;
        int rightHeight = dfsHeight (root -> right);
        if (rightHeight == -1) return -1;
        
        if (abs(leftHeight - rightHeight) > 1)  return -1;
        return max (leftHeight, rightHeight) + 1;
    }
};
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans; 
        if(root == NULL) return ans; 
        queue<TreeNode*> q; 
        q.push(root); 
        while(!q.empty()) {
            int size = q.size();
            vector<int> level; 
            for(int i = 0;i<size;i++) {
                TreeNode *node = q.front(); 
                q.pop(); 
                if(node->left != NULL) q.push(node->left); 
                if(node->right != NULL) q.push(node->right); 
                level.push_back(node->data); 
            }
            ans.push_back(level); 
        }
        return ans; 
    }
};
class Solution {//iterative preorder traversal

public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        if(root == NULL) return preorder; 
       
        stack<TreeNode*> st; 
        st.push(root);
        while(!st.empty()){
            root = st.top();
            st.pop(); 
            preorder.push_back(root->data); 
            if(root->right != NULL){
                st.push(root->right);
            }
            if(root->left!= NULL){
                st.push(root->left);
            }
        }
        return preorder; 
    }
};
class Solution {//iterative inorder traversal

public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st; 
        TreeNode* node = root;
        vector<int> inorder; 
        while(true) {
            if(node != NULL) {
                st.push(node); 
                node = node->left; 
            }
            else {
    
                if(st.empty() == true) break; 
                node = st.top(); 
                st.pop(); 
                inorder.push_back(node->data); 
                node = node->right; 
            }  
        }
        return inorder; 
    }
};
class Solution {//iterative postorder traversal using 2 stacks


public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        if(root == NULL) return postorder;
        stack<TreeNode*> st1, st2; 
        st1.push(root); 
        while(!st1.empty()) {
            root = st1.top(); 
            st1.pop();
            st2.push(root); 
            if(root->left != NULL) {
                st1.push(root->left); 
            }
            if(root->right != NULL) {
                st1.push(root->right); 
            }
        }
        while(!st2.empty()) {
            postorder.push_back(st2.top()->data); 
            st2.pop(); 
        }
        return postorder;
    }
};
// to find diameter of a binary tree
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }
private:
    int height(TreeNode* node, int& diameter) {
        if (!node) {
            return 0;
        }
        int lh = height(node->left, diameter);
        int rh = height(node->right, diameter);
        diameter = max(diameter, lh + rh);
        return 1 + max(lh, rh);
    }
};
int main()
{
    struct TreeNode*root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);

}