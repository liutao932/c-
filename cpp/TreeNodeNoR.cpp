#include<iostream>
#include<string>
#include<stack>
using namespace std;

struct TreeNode
{
    TreeNode(const int val = int())
        :_left(nullptr)
        , _rigth(nullptr)
        , _val(val)
    {

    }
    TreeNode* _left;
    TreeNode* _rigth;
    int _val;
};
void TreeForntR(TreeNode* root)
{
    if (root == nullptr) return;
    cout << root->_val << " ";
    TreeForntR(root->_left);
    TreeForntR(root->_rigth);
}
void TreeForntNoR(TreeNode* root)
{
    stack<TreeNode*> st;
    st.push(root);
    while (!st.empty())
    {
        TreeNode* tmp = st.top();
        cout << tmp->_val << " ";
        st.pop();
        if (tmp->_rigth)
            st.push(tmp->_rigth);
        if (tmp->_left)
            st.push(tmp->_left);
    }
}
void TreeMidR(TreeNode* root)
{
    if (root == nullptr) return;
    TreeMidR(root->_left);
    cout << root->_val << " ";
    TreeMidR(root->_rigth);
}
void TreeMidNoR(TreeNode* root)
{
    stack<TreeNode*> st;
    while (!st.empty() || root != nullptr)
    {
        if (root != nullptr)
        {
            st.push(root);
            root = root->_left;
        }
        else
        {
            root = st.top();
            st.pop();
            cout << root->_val << " ";
            root = root->_rigth;
        }
    }
}
void TreeBehindR(TreeNode* root)
{
    if (root == nullptr) return;
    TreeBehindR(root->_left);
    TreeBehindR(root->_rigth);
    cout << root->_val << " ";
}
void TreeBehindNoR(TreeNode* root)
{
    stack<TreeNode*> node, ret;
    node.push(root);
    while (!node.empty())
    {
        TreeNode* tmp = node.top();
        node.pop();
        ret.push(tmp);
        if (tmp->_left)
            node.push(tmp->_left);
        if (tmp->_rigth)
            node.push(tmp->_rigth);
    }
    while (!ret.empty())
    {
        cout << ret.top()->_val << " ";
        ret.pop();
    }
}
int main()
{
    TreeNode* root = new TreeNode(1);
    TreeNode* B = new TreeNode(2);
    TreeNode* C = new TreeNode(3);
    TreeNode* D = new TreeNode(4);
    TreeNode* E = new TreeNode(5);
    TreeNode* F = new TreeNode(6);
    root->_left = B;
    root->_rigth = C;
    B->_left = D;
    B->_rigth = E;
    C->_left = F;
    //TreeForntR(root);
    //TreeForntNoR(root);
    //TreeBehindR(root);
    //TreeBehindNoR(root);

   // TreeMidR(root);
    TreeMidNoR(root);
}
