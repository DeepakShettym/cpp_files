#include<queue>
#include<stack>
#include<math.h>
#include<vector>
#include<map>
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


int findMaxDepth(TreeNode<int> *root) 
{
    if(root == NULL){
        return 0;
    }


    int left = findMaxDepth(root->left);
    int right = findMaxDepth(root->right);

    return max(left , right) + 1;
}


bool isBalancedBT(TreeNode<int>* root){
    if(root == NULL){
        return true;
    }

    int leftHeight  = findMaxDepth(root->left);
    int rightHeight = findMaxDepth(root->right);


    if(abs(leftHeight - rightHeight) > 1){
        return false;
    }


    int left = isBalancedBT(root->left);

    int right = isBalancedBT(root->right);


    if(!left || !right){
        return false;
    }

    return true;
}

int findMaxDepth2(TreeNode<int> *root) 
{
    if(root == NULL){
        return 0;
    }


    int left = findMaxDepth2(root->left);
    int right = findMaxDepth2(root->right);

    if(left == -1 || right == -1){
        return -1;
    }

    if(abs(left - right) > 1){
        return -1;
    }

    return max(left , right) + 1;
}

bool isBalancedBT2(TreeNode<int>* root){
   return (findMaxDepth2(root) != -1);
}

vector<int> zigZagTraversal(TreeNode<int>*root)
{
    vector<int> result;
    if(root == NULL){
        return result;
    }
    queue<TreeNode<int>*> q;

    

    bool zigzag = true;


    q.push(root);

    while(!q.empty()){
        

        int size = q.size();
        vector<int> ans(size);


        for(int i = 0 ; i < size ; i++){
            TreeNode<int>* front = q.front();
            q.pop();

            int index = (zigzag) ? i  : (size  -  i) - 1;

            ans[index] = front->data;


            if(front->left) q.push(front->left);

            if(front->right) q.push(front->right);

        }


        for(auto &item : ans){
            result.push_back(item);
        }

        zigzag = !zigzag;
    }


    return result;
}

vector<int> getTopView(TreeNode<int> *root)
{
    vector<int> ans;

    if(root == NULL){
        return ans;
    }

    map<int , int> mmap;

    queue<pair<TreeNode<int>* , int>>q;
    q.push({root , 0});

    while(!q.empty()){
        pair<TreeNode<int>* , int> fornt = q.front();
        q.pop();

        TreeNode<int>* node = fornt.first;
        int col = fornt.second;


        if(mmap.find(col) == mmap.end()){
            mmap[col] = node->data;
        }


        if(node->left) q.push({node->left , col - 1});

        if(node->right) q.push({node->right , col + 1});


    }

    for(auto &item : mmap){
        ans.push_back(item.second);
    }


    return ans;


}

vector<int> bottomView(TreeNode<int> * root){
    vector<int> ans;

    if(root == NULL){
        return ans;
    }


    map<int , int> mmap;

    queue<pair<TreeNode<int>* , int>> q;
    q.push({root , 0});
    while(!q.empty()){

        pair<TreeNode<int>* , int> front = q.front();
        q.pop();

        TreeNode<int>* node = front.first;
        int col = front.second;

        mmap[col] = node->data;


        if(node->left) q.push({node->left , col - 1});

        if(node->right) q.push({node->right , col + 1});
    }

        for(auto &item : mmap){
            ans.push_back(item.second);
        }


        return ans;
}

vector<int> getLeftView(TreeNode<int> *root)
{   
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

                if(i == 0){
                    ans.push_back(node->data);
                }

                if(node->left) q.push(node->left);

                if(node->right) q.push(node->right);
            }
        }

        return ans;
}
