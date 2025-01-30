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
       solve(root,ans,0);
       return ans;
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
void solve(Node* root,vector<int> &ans,int level){
        if(root==NULL){
            return;
        }
        if(level==ans.size()){
            ans.push_back(root->data);
        }
        
          solve(root->right,ans,level+1);
        solve(root->left,ans,level+1);
        
      
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