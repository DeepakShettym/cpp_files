//binary tree and its representaions
#include <iostream>
#include <bits/stdc++.h>
#include <queue>
using namespace std;

struct Node {
  int data;
  Node *left;
  Node *right;

  Node(int data) {
    this->data = data;
    this->left = NULL;
    this->right = NULL;
  }
};

Node *buildTree(Node *root) {
  cout << "Enter data to the node : " << endl;
  int data;
  cin >> data;

  if (data == -1) {
    return NULL;
  }

  root = new Node(data);

  cout << "Enter data for left of " << data << endl;
  root->left = buildTree(root->left);

  cout << "Enter data for right of " << data << endl;
  root->right = buildTree(root->right);

  return root;
}

void levelOrderTreversal(Node *root) {
  queue<Node *> queue;
  queue.push(root);
  queue.push(NULL);

  while (!queue.empty()) {
    Node *temp = queue.front();
    queue.pop();

    if (temp == NULL) {
      cout << endl;

      if (!queue.empty()) {
        queue.push(NULL);
      }

    } else {
      cout << temp->data << " ";

      if (temp->left) {
        queue.push(temp->left);
      }

      if (temp->right) {
        queue.push(temp->right);
      }
    }
  }
}



void inOrder(Node *root) {
  if (root == NULL) {
    return;
  }

  inOrder(root->left);
  cout << root->data << " ";
  inOrder(root->right);
}

void preOrder(Node *root) {
  if (root == NULL) {
    return;
  }
  cout << root->data << " ";
  preOrder(root->left);
  preOrder(root->right);
}

void postOrder(Node *root) {
  if (root == NULL) {
    return;
  }
  postOrder(root->left);
  postOrder(root->right);
  cout << root->data << " ";
}

void display(Node *root) {
  if (root == NULL) {
    return;
  }

  cout << "Node Data: " << root->data << ", ";

  if (root->left != NULL) {
    cout << "Left Child: " << root->left->data << ", ";
  } else {
    cout << "Left Child: NULL, ";
  }

  if (root->right != NULL) {
    cout << "Right Child: " << root->right->data;
  } else {
    cout << "Right Child: NULL";
  }

  cout << endl;

  display(root->left);
  display(root->right);
}

int height(Node *root) {
  if (root == NULL) {
    return 0;
  }

  int left = height(root->left);
  int right = height(root->right);

  return max(left, right) + 1;
}

bool leftToRight = true;
void ZigZagTreversal(Node *root) {
  queue<Node *> queue;
  queue.push(root);
  queue.push(NULL);

  while (!queue.empty()) {
   
    Node *temp = queue.front();
    queue.pop();

    if (temp == NULL) {
      cout << endl;

      if (!queue.empty()) {
        queue.push(NULL);
      }

    } else {
      cout << temp->data << " ";

      if (temp->left) {
        queue.push(temp->left);
      }

      if (temp->right) {
        queue.push(temp->right);
      }
    }
  }
}

 



vector<int> verticalOrderTraversal(Node *root)
{
    map<int, map<int, vector<int>>> node;
    queue<pair<Node*, pair<int, int>>> q;  
    vector<int> ans;

    if (root == NULL) {
        return ans;  
    }

    q.push(make_pair(root, make_pair(0, 0)));

    while (!q.empty()) {
        pair<Node*, pair<int, int>> frontNode = q.front();
        q.pop();

        int hd = frontNode.second.first;  
        int lvl = frontNode.second.second;  

        node[hd][lvl].push_back(frontNode.first->data);  

        if (frontNode.first->left) {
           
            q.push(make_pair(frontNode.first->left, make_pair(hd - 1, lvl + 1)));
        }

        if (frontNode.first->right) {
         
            q.push(make_pair(frontNode.first->right, make_pair(hd + 1, lvl + 1)));
        }
    }

   
    for (auto i : node) {
        for (auto j : i.second) {
            for (auto k : j.second) {
                ans.push_back(k);  
            }
        }
    }

    return ans;
}

 vector<int> topView(Node *root) {
       vector<int> ans;
       
       if(root==NULL){
           return ans;
       }
       
        map<int,int> map;
       queue< pair<Node*,int> > q;
       q.push(make_pair(root, 0));
       
      
       
       while(!q.empty()){
           pair<Node* , int> temp = q.front();
           q.pop();
           Node* frontNode = temp.first;
           int hd = temp.second;
           
           if(map.find(hd) == map.end()){
               map[hd] = frontNode->data;
           }
           
           if(frontNode->left){
               q.push(make_pair(frontNode->left,hd-1));
           }
           
           if(frontNode->right){
               q.push(make_pair(frontNode->right,hd+1));
           }
       }
       
       for(auto i:map){
           ans.push_back(i.second);
       }
       
       return ans;
    }

     vector <int> bottomView(Node *root) {
      vector<int> ans;
       
       if(root==NULL){
           return ans;
       }
       
        map<int,int> map;
       queue< pair<Node*,int> > q;
       q.push(make_pair(root, 0));
       
      
       
       while(!q.empty()){
           pair<Node* , int> temp = q.front();
           q.pop();
           Node* frontNode = temp.first;
           int hd = temp.second;
           
               map[hd] = frontNode->data;
          
           
           if(frontNode->left){
               q.push(make_pair(frontNode->left,hd-1));
           }
           
           if(frontNode->right){
               q.push(make_pair(frontNode->right,hd+1));
           }
       }
       
       for(auto i:map){
           ans.push_back(i.second);
       }
       
       return ans;
    }

  vector<int> leftView(Node *root) {
       vector<int> ans;
       leftView_solve(root,ans,0);
       return ans;
    }  

    void leftView_solve(Node* root,vector<int> &ans,int level){
      if(root==NULL){
          return;
      }
      if(level==ans.size()){
          ans.push_back(root->data);
      }
      
      leftView_solve(root->right,ans,level+1);
      leftView_solve(root->left,ans,level+1);
      
    
  }
void rightView_solve(Node* root,vector<int> &ans,int level){
        if(root==NULL){
            return;
        }
        if(level==ans.size()){
            ans.push_back(root->data);
        }
        rightView_solve(root->left,ans,level+1);
        
        rightView_solve(root->right,ans,level+1);
    }


 vector<int> rightView(Node *root)
    {
        vector<int> ans;
       rightView_solve(root,ans,0);
       return ans;
    }


        void sumOfLongRootToLeafPath_solve(Node* root,int len,int &maxLen,int sum,int &maxSum){
        if(root==NULL){
            if(len > maxLen){
                maxLen = len;
                maxSum = sum;
            }else if(len == maxLen){
                maxSum = max(sum,maxSum);
            }
            
            return;
            
        }
            
            sum = sum + root->data;
            
            sumOfLongRootToLeafPath_solve(root->left,len+1,maxLen,sum,maxSum);
            sumOfLongRootToLeafPath_solve(root->right,len+1,maxLen,sum,maxSum);
        
    }
    int sumOfLongRootToLeafPath(Node *root) {
        int len = 0;
        int maxLen = 0;
        int sum = 0;
        int maxSum = INT_MIN;

    sumOfLongRootToLeafPath_solve(root, len, maxLen, sum, maxSum);

    return maxSum;
    }
      Node* lca(Node* root, int n1, int n2) {
       if(root==NULL){
           return NULL;
       }
       
       if(root->data == n1 || root->data == n2){
           return root;
       }
       
       Node* left = lca(root->left,n1,n2);
       Node* right = lca(root->right,n1,n2);
        if(left!=NULL && right!=NULL){
           return root;
       }else if(left!=NULL && right == NULL){
           return left;
       }else if(left==NULL && right != NULL){
           return right;
       }else{
           return NULL;
       }
    }

    int findBottomLeftDataue(Node* root) {
        if(root->left==NULL && root->right==NULL){
            return root->data;
        }

        int dataue = 0;
         queue<Node *> queue;
            queue.push(root);
            queue.push(NULL);

  while (!queue.empty()) {
    Node *temp = queue.front();
    queue.pop();

    if (temp == NULL) {
        if(!queue.empty()){
                  Node* ans = queue.front();
                   dataue = ans->data;
        }

      if (!queue.empty()) {
        queue.push(NULL);
      }

    } else {
      if (temp->left) {
        queue.push(temp->left);
      }

      if (temp->right) {
        queue.push(temp->right);
      }
    }
  }

  return dataue;
    }


    void pathSum_solve(Node* root, int targetSum,int &count,vector<int> path){
        if(root==NULL){
            return;
        }

        path.push_back(root->data);

        pathSum_solve(root->left,targetSum,count,path);
        pathSum_solve(root->right,targetSum,count,path);

        int size = path.size();
        long sum =0;

        for(int i = size-1;i>=0;i--){
            sum += path[i];

            if(sum==targetSum){
                count++;
            }
        }

        path.pop_back();
    }
    int pathSum(Node* root, int targetSum) {
        vector<int> path;
        int count = 0;
        pathSum_solve(root,targetSum,count,path);
        return count;
    }

    int isSumProperty(Node *root) {
    
    if (root == NULL || (root->left == NULL && root->right == NULL)) {
        return 1;
    }

    int sum = 0;


    if (root->left) {
        sum += root->left->data;
    }


    if (root->right) {
        sum += root->right->data;
    }

  
    if (sum != root->data) {
        return 0;
    }

   
    return isSumProperty(root->left) && isSumProperty(root->right);
}
int toSumTree_solve(Node *node){
          if(node==NULL){
              return 0;
          }
          
        
          
          
         int left = toSumTree_solve(node->left);
          int right = toSumTree_solve(node->right);
          
          int value = left + right + node->data;
          
            if(node->left==NULL && node->right == NULL){
                
              node->data = 0;
              
          }else{
               node->data = left + right;
          }
          
         
          
          
          return value;
       }
 
    void toSumTree(Node *node)
    {
         int sum = toSumTree_solve(node);
         
    }

      void mirror(Node* node) {
       if(node==NULL){
           return;
       }
       
       
            Node* temp = node->left;
            node->left = node->right;
            node->right = temp;
      
           mirror(node->left);

           mirror(node->right);
       
       
       
    }

      int getLevelDiff(Node *root)
    {
       queue<Node *> queue;
          queue.push(root);
          queue.push(NULL);
          
          int sumEven = 0;
          int sumOdd  = 0;
          
         bool isodd = true;

  while (!queue.empty()) {
    Node *temp = queue.front();
    queue.pop();

    if (temp == NULL) {
      isodd = !isodd;

      if (!queue.empty()) {
        queue.push(NULL);
      }

    } else {
      
      if(isodd){
          sumOdd += temp->data;
      }else{
          sumEven += temp->data;
      }

      if (temp->left) {
        queue.push(temp->left);
      }

      if (temp->right) {
        queue.push(temp->right);
      }
    }
  }
  
  
  return sumOdd - sumEven;
    }


 bool isSymmetric( Node* root)
    {
        if(root==NULL || (root->left ==NULL && root->right == NULL)){
            return true;
        }
	       return solve_isSymmetric(root->left,root->right);
    }
    
    bool solve_isSymmetric( Node* leftNode, Node* rightNode){
        
        if(left==NULL && right == NULL){
            return true;
        }
        
         if (leftNode == NULL || rightNode == NULL) {
        return false; 
    }
        
        bool leftans = solve_isSymmetric(leftNode->left,rightNode->right);
        bool rightans =  solve_isSymmetric(leftNode->right,rightNode->left);
        
        
        
    
        return leftans && rightans && (leftNode->data == rightNode->data);
        
        
        
    }


    //inorder preorder

    Node* solve_buildTree(vector<int> &inorder, vector<int> &preorder, int &index, int start, int end, int n) {
    if (index >= n || start > end) {
        return NULL;
    }
    
    int elem = preorder[index];
    int pos = -1;
    
   
    for (int i = start; i <= end; i++) {
        if (inorder[i] == elem) {
            pos = i;
            break;  
        }
    }
    
    // Create root node
    Node* root = new Node(elem);
    index++;  

    
    root->left = solve_buildTree(inorder, preorder, index, start, pos - 1, n);
    root->right = solve_buildTree(inorder, preorder, index, pos + 1, end, n);

    return root;
}
        
        
        
    
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        int preorderIndex = 0;
        int n = inorder.size();
        Node* ans = solve_buildTree(inorder,preorder,preorderIndex,0,n-1,n);
        return ans;
    }



// inorder postorder 
class Solution {
public:
    Node* solve_buildTree2(vector<int> &inorder, vector<int> &postorder, int &index, int start, int end, int n) {
    if (index < 0 || start > end) {
        return NULL;
    }
    
    int elem = postorder[index];
    int pos = -1;
    
   
    for (int i = start; i <= end; i++) {
        if (inorder[i] == elem) {
            pos = i;
            break;  
        }
    }
    
    // Create root node
    Node* root = new Node(elem);
    index--;  

    root->right = solve_buildTree2(inorder, postorder, index, pos + 1, end, n);
    root->left = solve_buildTree2(inorder, postorder, index, start, pos - 1, n);


    return root;
}
    

    Node* buildTree2(vector<int>& inorder, vector<int>& postorder) {
        
        int n = postorder.size();
        int postorderIndex = n-1;
        Node* ans = solve_buildTree(inorder,postorder,postorderIndex,0,n-1,n);
        return ans;
    }


    Node* createParentMapping(Node* root,int target,map<Node* , Node*> &nodeToParent){
      Node* res = NULL;
      
      queue<Node*> q;
      
      q.push(root);
      nodeToParent[root] = NULL;
      
      while(!q.empty()){
          Node* front = q.front();
          q.pop();
          
          if(front->data==target){
              res = front;
          }
          
          if(front->left){
              nodeToParent[front->left] = front;
              q.push(front->left);
          }
          
           if(front->right){
               nodeToParent[front->right] = front;
              q.push(front->right);
          }
      }
      
      return res;
  }
  
  
  int burnTree(Node* root,map<Node* , Node*> nodeToParent){
      map<Node*,bool> visited;
      
      queue<Node*> q;
      q.push(root);
      
      visited[root] = true;
      
      int ans = 0;
      
      
      
      while(!q.empty()){
          bool flag = 0;
          int size = q.size();
          
          for(int i=0; i<size;i++){
              Node* front = q.front();
              q.pop();
              
              
              if(front->left && !visited[front->left]){
                  flag = 1;
                  q.push(front->left);
                  visited[front->left] = true;
              }
              
                if(front->right && !visited[front->right]){
                  flag = 1;
                  q.push(front->right);
                  visited[front->right] = true;
              }
              
              if(nodeToParent[front] && !visited[nodeToParent[front]]){
                  flag = 1;
                  q.push(nodeToParent[front]);
                  visited[nodeToParent[front]] = true;
              }
          }
          
          if(flag == 1){
              ans++;
          }
      }
      
      return ans;
      
      
  }
  
  int minTime(Node* root, int target) {
     map<Node* , Node*> nodeToParent;
     Node* targetNode =  createParentMapping(root,target,nodeToParent);
     int ans = burnTree(targetNode,nodeToParent);
     return ans;
  }


  Node* createParentMapping(Node* root,int target,map<Node* , Node*> &nodeToParent){
    Node* res = NULL;
    
    queue<Node*> q;
    
    q.push(root);
    nodeToParent[root] = NULL;
    
    while(!q.empty()){
        Node* front = q.front();
        q.pop();
        
        if(front->data==target){
            res = front;
        }
        
        if(front->left){
            nodeToParent[front->left] = front;
            q.push(front->left);
        }
        
         if(front->right){
             nodeToParent[front->right] = front;
            q.push(front->right);
        }
    }
    
    return res;
}

 vector<int> findDistance(Node* root,map<Node* , Node*> nodeToParent,int k){
    map<Node*,bool> visited;
    vector<int> ans;
    
    queue<pair<Node*,int>> q;
    q.push(make_pair(root,0));
    
    visited[root] = true;
    
    while(!q.empty()){
        bool flag = 0;
        int size = q.size();
        
        for(int i=0; i<size;i++){
            pair<Node*,int> p =  q.front();
            Node* front = p.first;
            int distance = p.second;
            q.pop();
            
            if(distance == k){
                ans.push_back(front->data);
            }
            
            if(front->left && !visited[front->left]){
                q.push(make_pair(front->left,distance+1));
                visited[front->left] = true;
            }
            
              if(front->right && !visited[front->right]){
                q.push(make_pair(front->right,distance+1));
                visited[front->right] = true;
            }
            
            if(nodeToParent[front] && !visited[nodeToParent[front]]){
                q.push(make_pair(nodeToParent[front],distance+1));
                visited[nodeToParent[front]] = true;
            }
        }
        
         
    }
    
    sort(ans.begin(), ans.end());
    
    return ans; 
    
    
}


vector<int> KDistanceNodes(Node* root, int target, int k) {
     map<Node* , Node*> nodeToParent;
   Node* targetNode =  createParentMapping(root,target,nodeToParent);
   vector<int> ans = findDistance(targetNode,nodeToParent,k);
   
   return ans;
}
};

 

int main() {
  Node *root = NULL;
  root = buildTree(root);
  cout << "\nDisplaying Tree:" << endl;
  display(root);
  cout << "\nDisplaying Tree as level order:" << endl;
  levelOrderTreversal(root);
  cout << "\nDisplaying Tree as in order:" << endl;
  inOrder(root);
  cout << "\nDisplaying Tree as pre order:" << endl;
  preOrder(root);
  cout << "\nDisplaying Tree as post order:" << endl;
  postOrder(root);

  int hightOfTree = height(root);

  cout << endl << "height = " << hightOfTree << endl;

  return 0;
}
// 1,2,4,-1,-1,5,-1,-1,3,-1,-1