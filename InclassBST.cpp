#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
  if (root != NULL) {
    traverseInOrder(root->left);
    cout << root->key << " ";
    traverseInOrder(root->right);
  }
}

// Insert a node
struct node *insertNode(struct node *root, int key) {
  if (root == NULL) {
    struct node *newNode = new node;
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
  }

  if (key < root->key)
    root->left = insertNode(root->left, key);
  else if (key > root->key)
    root->right = insertNode(root->right, key);

  return root;
}

// Find the minimum key node in a subtree
struct node *minKeyNode(struct node *node) {
  struct node *current = node;

  while (current && current->left != NULL)
    current = current->left;

  return current;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
  if (root == NULL) return root;

  if (key < root->key)
    root->left = deleteNode(root->left, key);
  else if (key > root->key)
    root->right = deleteNode(root->right, key);

  else {
    // node with only one child or no child
    if (root->left == NULL) {
      struct node *temp = root->right;
      delete root;
      return temp;
    }
    else if (root->right == NULL) {
      struct node *temp = root->left;
      delete root;
      return temp;
    }

    // node with two children: get the inorder successor (smallest
    // in the right subtree)
    struct node *temp = minKeyNode(root->right);

    // copy the inorder successor's content to this node
    root->key = temp->key;

    // delete the inorder successor
    root->right = deleteNode(root->right, temp->key);
  }
  return root;
}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }

  traverseInOrder(root);
}
