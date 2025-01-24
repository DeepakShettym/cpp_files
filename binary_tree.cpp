//binary tree and its representaions
#include <iostream>
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