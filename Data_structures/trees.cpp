#include<queue>
#include<stack>
using namespace std;


template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
};



vector<int> levelOrder(TreeNode<int> * root){
    vector<int> ans;
    if(root == NULL){
        return ans;
    }
    
    queue<TreeNode<int>*> q;
    q.push(root);

    while(!q.empty()){
        int size = q.size();

        for(int i = 0 ; i < size ; i++){
            TreeNode<int>* node = q.front();
            q.pop();

            ans.push_back(node->data);

            if(node->left) q.push(node->left);

            if(node->right) q.push(node->right);
        }
    }

    return ans;



}

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

    vector<int> preOrder(Node* root) {
        vector<int> ans;
        
        if(root==NULL){
            return ans;
        }
        stack<Node*> st;
        st.push(root);

       
        while(!st.empty()){
          Node* top = st.top();
          st.pop();
          
          ans.push_back(top->data);
          
          if(top->right) st.push(top->right);
          if(top->left) st.push(top->left);
       }
       
        return ans;
    }

    vector<int> inOrder(Node* root) {
        vector<int> ans;
        if(root == NULL){
            return ans;
        }
        // code here
        stack<Node*> st;
        
        
        
        Node* node = root;
        
        
        while(true){
            if(node != NULL){
                st.push(node);
                node = node->left;
            }else{
                
                if(st.empty() == true)       break;

                Node* top = st.top();
                st.pop();
                
                ans.push_back(top->data);
                node = node->right;
            }
        }
        
        
        return ans;
    }


    vector<int> postOrder(Node* root) {
        // code here
        vector<int> ans;
        
        if(root == NULL){
            return ans;
        }
        
        stack<Node*> st1;
        stack<Node*> st2;
        st1.push(root);
        
        while(!st1.empty()){
            Node* top = st1.top();
            st1.pop();
            
            st2.push(top);
            
            if(top->left) st1.push(top->left);
            
            if(top->right) st1.push(top->right);
            
        }
        
        while(!st2.empty()){
            ans.push_back(st2.top()->data);
            st2.pop();
        }
        
        return ans;
    }

    vector<vector<int>> getTreeTraversal(TreeNode<int> *root){
    vector<vector<int>> ans;

    vector<int> pre , ino , pos;

    stack<pair<TreeNode<int>* , int>> st;

    st.push({root , 1});

    while(!st.empty()){
        pair<TreeNode<int>* ,int> top = st.top();
        st.pop();
        TreeNode<int>* node = top.first;
        int num = top.second;

        if(num == 1){
            pre.push_back(node->data);
            num++;
            st.push({node ,num });

            if(node->left) st.push({node->left , 1});
        }else if(num == 2){
            ino.push_back(node->data);
            num++;
            st.push({node , num});

            if(node->right) st.push({node->right , 1});
        }else{
            pos.push_back(node->data);
        }
    }


    ans.push_back(ino);
    ans.push_back(pre);
    ans.push_back(pos);


    return ans;



}
