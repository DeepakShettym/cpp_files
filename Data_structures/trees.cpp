#include<queue>
#include<stack>
#include<math.h>
#include<vector>
#include<map>
#include<unordered_map>
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

void solvegetLeftView(TreeNode<int>* root , int level , vector<int> &ans){
    if(root == NULL){
        return;
    }

    if(ans.size() == level) ans.push_back(root->data);

    solvegetLeftView(root->left ,level + 1 , ans);
    solvegetLeftView(root->right , level + 1 , ans);
}
vector<int> getLeftView(TreeNode<int> *root)
{      vector<int> ans;    

       if(root == NULL){
           return ans;
       } 
       solvegetLeftView(root , 0 , ans);
       return ans;
}

void solvegetRightView(TreeNode<int>* root , int level , vector<int> &ans){
    if(root == NULL){
        return;
    }

    if(ans.size() == level) ans.push_back(root->data);

    solvegetRightView(root->right , level + 1 , ans);
    solvegetRightView(root->left ,level + 1 , ans);
    
}
vector<int> getLeftView(TreeNode<int> *root)
{      vector<int> ans;    

       if(root == NULL){
           return ans;
       } 
       solvegetRightView(root , 0 , ans);
       return ans;
}

vector<int> getLeftViewiterative(TreeNode<int> *root)
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

bool solveisSymmetric(TreeNode<int>* p , TreeNode<int>* q){
   if(p == NULL || q == NULL){
        return (p == q);
   }


   return (p->data == q->data) && solveisSymmetric(p->left , q->right) && solveisSymmetric(p->right , q->left);
}

bool isSymmetric(TreeNode<int>* root)
{
        if(root == NULL){
            return true;
        }    

        return solveisSymmetric(root->left , root->right);
}

bool solvepathInATree(TreeNode<int>* root, int x, vector<int> &ans) {
    if (root == NULL) {
        return false;
    }

    ans.push_back(root->data);

    if (root->data == x) {
        return true;
    }

    if (solvepathInATree(root->left, x, ans) ||
        solvepathInATree(root->right, x, ans)) {
        return true;
    }

 
    ans.pop_back();
    return false;
}

vector<int> pathInATree(TreeNode<int> *root, int x) {
    vector<int> ans;
    if (root == NULL) {
        return ans;
    }
    solvepathInATree(root, x, ans);
    return ans;
}

  TreeNode<int>* lowestCommonAncestor(TreeNode<int>* root, TreeNode<int>* p, TreeNode<int>* q) {
    if (root == NULL || root == p || root == q) {
        return root;
    }

    TreeNode<int>* left  = lowestCommonAncestor(root->left, p, q);
    TreeNode<int>* right = lowestCommonAncestor(root->right, p, q);

    if (left == NULL) {
        return right;
    }
    if (right == NULL) {
        return left;
    }

   
    return root;
}


int widthOfBinaryTree(TreeNode<int>* root) {
        if(root == NULL){
            return 0;
        }
        queue<pair<TreeNode<int>* , long long>> q;
        int ans = 0; 
        q.push({root , 0});

        while(!q.empty()){
            int size = q.size();
            int min = q.front().second;
            int first; int last;

            for(int i = 0 ; i < size ; i++){
               TreeNode<int>* node = q.front().first;
               long long curr_id = q.front().second - min;
               q.pop();

               if(i == 0){
                first = curr_id;
               }

               if(i == size -1){
                last = curr_id;
               }

               if(node->left) q.push({node->left , (curr_id*2 + 1)});
               if(node->right) q.push({node->right , (curr_id*2 + 2)});

            }

            ans = max(ans , last - first + 1);
        }

        return ans;
    }

    void changeTree(TreeNode < int > * root) {
    if(root == NULL || (root->left == NULL && root->right == NULL)){
        return;
    }

    int child = 0;

    if(root->left) child += root->left->data;
    if(root->right) child += root->right->data;

    if(child >= root->data) {
        root->data = child;
    }
    else {
        if(root->left) root->left->data = root->data;
        if(root->right) root->right->data = root->data;

    }

    changeTree(root->left);
    changeTree(root->right);

    int total = 0;
    if(root->left) total += root->left->data;
    if(root->right) total += root->right->data;

    root->data = total;

    
}

   vector<int> distanceK(TreeNode<int>* root, TreeNode<int>* target, int k) {
        map<TreeNode<int>* , TreeNode<int>*> parent;
        parent[root] = NULL;
        queue<TreeNode<int>*> q;
        q.push(root);


        while(!q.empty()){
            TreeNode<int>* front = q.front();
            q.pop();
            
            if(front->left) {
                parent[front->left] = front;
                q.push(front->left);
                }

            if(front->right) {
                parent[front->right] = front;
                q.push(front->right);
                }
            }

            q.push(target);
            map<TreeNode<int>* , bool> v;
            v[target] = true;
            int dist = 0;


            while(!q.empty()){
                int size = q.size();
                if(dist == k) break;
                
                while(size--){
                    TreeNode<int>* f = q.front();
                    q.pop();
                    TreeNode<int>* p = parent[f];

                    if(p && !v[p]){
                        q.push(p);
                        v[p] = true;
                    }

                    TreeNode<int>* l = f->left;

                    if(l && !v[l]){
                        q.push(l);
                        v[l] = true;
                    }

                    TreeNode<int>* r = f->right;

                    if(r && !v[r]){
                        q.push(r);
                        v[r] = true;
                    }
                }

                dist++;
            }

            vector<int> ans;

            while(!q.empty()){
                ans.push_back(q.front()->data);
                q.pop();
            } 


            return ans;
        

        }

        int amountOfTime(TreeNode<int>* root, int start) {
        unordered_map<TreeNode<int>* , TreeNode<int>*> parent;
        queue<TreeNode<int>*> q;

        q.push(root);
        parent[root] = NULL;
        TreeNode<int>* startNode = NULL;

        while(!q.empty()){
            TreeNode<int>* node = q.front();
            q.pop();
            if(node->data == start){
                startNode = node;
            }
            

            if(node->left) {
                parent[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                parent[node->right] = node;
                q.push(node->right);
            } 
        } 

        int minutes = -1;

        unordered_map<TreeNode<int>* , bool> v;
        v[startNode] = true;
        q.push(startNode);

        while(!q.empty()){
            int size = q.size();
            minutes += 1;

            while(size--){
                TreeNode<int>* f = q.front();
                q.pop();

                TreeNode<int>* p = parent[f];

                if(p && !v[p]){
                    q.push(p);
                    v[p] = true;
                }

                TreeNode<int>* l = f->left;

                if(l && !v[l]){
                    q.push(l);
                    v[l] = true;
                }

                TreeNode<int>* r = f->right;

                if(r && !v[r]){
                    q.push(r);
                    v[r] = true;
                }
            }
        }


        return minutes;
    }


    TreeNode<int>* solve(
    vector<int>& inorder,
    vector<int>& preorder,
    int s,
    int e,
    int& idx,
    unordered_map<int,int>& mapp
) {
    if (s > e) {
        return NULL;
    }

    int val = preorder[idx++]; 
    TreeNode<int>* root = new TreeNode<int>(val);

    int index = mapp[val];
  

    root->left  = solve(inorder, preorder, s, index - 1, idx ,mapp);
    root->right = solve(inorder, preorder, index + 1, e, idx,mapp);

    return root;
}

TreeNode<int>*buildBinaryTree(vector<int>& inorder, vector<int>& preorder)
{
    unordered_map<int , int> mapp;

    for(int i = 0 ; i < inorder.size() ; i++){
        mapp[inorder[i]] = i;
    }
    int idx = 0;                
    return solve(inorder, preorder, 0, inorder.size() - 1, idx , mapp);
}

TreeNode<int>* solve(
     vector<int>& postOrder,
     vector<int>& inOrder,
     int s, 
     int e,
     int &idx,
     unordered_map<int , int> &mp
){
     if(s > e){
          return NULL;
     }

     int val  = postOrder[idx--];

     int inIndex = mp[val];

     TreeNode<int>* root = new TreeNode<int>(val);

     root->right = solve(postOrder , inOrder , inIndex + 1 , e , idx , mp);

     root->left = solve(postOrder , inOrder , s , inIndex -1 , idx , mp);

     

     return root;
     

}
TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder){
     unordered_map<int , int> mp;

     for(int i = 0 ; i < inOrder.size() ; i++){
          mp[inOrder[i]] = i;
     }
     int idx = postOrder.size() - 1;
     return solve(postOrder , inOrder ,0 , postOrder.size() -1 , idx, mp);
}


    vector<int> inorderTraversalMorris(TreeNode<int>* root) { // space complexity : o(1) no Auxiliary stack space 
        vector<int> inorder;

        TreeNode<int>* cur = root;

        while(cur != NULL){
            if(cur->left == NULL){
                inorder.push_back(cur->data);
                cur = cur->right;
            }else{
                TreeNode<int>* prev = cur->left;
                while(prev->right && prev->right != cur){
                    prev = prev->right;
                }

                if(prev->right == NULL){
                    prev->right = cur;
                    cur = cur->left;
                }else{
                    prev->right = NULL;
                    inorder.push_back(cur->data);
                    cur = cur->right;
                }
            }
        }

        return inorder;
    }

bool searchInBST(TreeNode<int> *root, int x) {
    while(root != NULL && root->data != x){
        root = (root->data > x) ? root->left : root->right ;
    }

    return root;
}

int Floor(TreeNode<int> *root, int input)
{
	int floor = -1;
	while(root != NULL){
		if(root->data == input){
			return input;
		}

		if(root->data > input){
			root = root->left;
		}else{
			floor = root->data;
			root = root->right;
			
		}
	}

	return floor;
}


int findCeil(TreeNode<int> *node, int x){
    int ceil = -1;

    while(node != NULL){
        if(node->data == x){
            return x;
        }

        if(node->data > x){
            ceil = node->data;
            node = node->left;
        }else{
            node = node->right;
        }
    }
    return ceil;
}

