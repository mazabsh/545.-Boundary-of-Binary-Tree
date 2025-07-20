#include<iostream> 
#include<vector> 
#include<stack> 

using namespace std; 

struct TreeNode{
public: 
     int val; 
     TreeNode* left; 
     TreeNode* right; 
     TreeNode(): val(0), left(nullptr), right(nullptr){}
     TreeNode(int _val): val(_val), left(nullptr), right(nullptr){}
     TreeNode(int _val, TreeNode* _left, TreeNode* _right): val(_val), left(_left), right(_right){}
};
class Solution{
public: 
     bool isLeaf(TreeNode* node){
       return node->left == nullptr && node->right == nullptr; 
     }
     void addLeaves(vector<int>& res, TreeNode* node){
       if(isLeaf(node)) res.push_back(node->val); 
       else {
         if(node->left!=nullptr) addLeaves(res, node->left); 
         if(node->right!=nullptr) addLeaves(res, node->right); 
       }
     }
     vector<int> boundaryOfBinaryTree(TreeNode* root) {
       vector<int> res; 
       if(root==nullptr) return res; 
       if(!isLeaf(root)) res.push_back(root->val); 
       TreeNode* t = root->left; 
       while(t!=nullptr){
         if(!isLeaf(t)) res.push_back(t->val); 
         if(t->left!=nullptr) t = t->left; 
         else t = t->right; 
         
       }
       addLeaves(res, root); 
       stack<int> s; 
       t = root->right; 
       while(t!=nullptr){
         if(!isLeaf(t)) s.push(t->val); 
         if(t->right !=nullptr) t = t->right; 
         else t = t->left; 
       }
       while(!s.empty()){
         res.push_back(s.top()); 
         s.pop(); 
       }
       return res; 
     }
};
int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2); 
    root->right = new TreeNode(3); 
    root->left->left = new TreeNode(4); 
    root->left->right = new TreeNode(5); 
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(8);
    root->right->left = new TreeNode(6); 
    root->right->left->left = new TreeNode(9); 
    root->right->left->right = new TreeNode(10); 
    Solution sol; 
    vector<int> res = sol.boundaryOfBinaryTree(root); 
    for(int n:res) cout << n << " , "; 
    cout << endl; 
    
    return 0; 
}
