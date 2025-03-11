#include "reserve.h"

reservation::reservation(int t) {
  time = t;
  left = nullptr;
  right = nullptr;
}

BST::BST() { root = nullptr; }

BST::~BST() { clearTree(root); }

void BST::clearTree(reservation *node) {
  if (node == nullptr) // not root . . . node?
    return;

  clearTree(node->left);
  clearTree(node->right);
  delete node;
}

bool BST::reserve(int time) {
  if (checkConflict(root, time)) {
    return false;
  }

  insert(root, time);
  return true;
}

bool BST::checkConflict(reservation *node, int time) {
  if (node == nullptr) {
    return false;
  }
  int absTime = abs(node->time - time);
  if (3 >= absTime) {
    return true;
  }

  if (time < node->time) {
    return checkConflict(node->left, time);
  } else {
    return checkConflict(node->right, time);
  }
}

// update subtree size (make sure to avoid inserting duplicates)
void BST::insert(reservation *&node, int time) {
  int rightsub = 0;
  int leftsub = 0;

  if (node == nullptr) {
    node = new reservation(time);
    node->subtreeSize = 1;
    return;
  }

  // recursive calls
  if (node->time > time) {
    insert(node->left, time);
  }
  if (node->time < time) {
    insert(node->right, time);
  }

  // update subtres by adding the subtree sizes of the left and right sizes
  if (node->left != nullptr) {
    leftsub = node->left->subtreeSize;
  }
  if (node->right != nullptr) {
    rightsub = node->right->subtreeSize;
  }
  node->subtreeSize = leftsub + rightsub;
}

int BST::countPlanes(reservation *node, int t) {
  if (node == nullptr) {
    return 0;
  }

  if (node->time <= t) {
    int leftsize = 0;
    if (node->left != nullptr) {
      leftsize = node->left->subtreeSize;
    }
    return leftsize + 1 + countPlanes(node->right, t);
  }
  return countPlanes(node->left, t);
}

void BST::inorder(reservation *root) {
  if (root == nullptr)
    return;

  inorder(root->left);
  cout << root->time << " ";
  inorder(root->right);
}
