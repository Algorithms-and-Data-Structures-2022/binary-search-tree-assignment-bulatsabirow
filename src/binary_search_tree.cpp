#include "assignment/binary_search_tree.hpp"

namespace assignment {

  BinarySearchTree::~BinarySearchTree() {
    BinarySearchTree::Clear();
  }

  void BinarySearchTree::Insert(int key, int value) {
    insert(key, value, root_);
  }

  bool BinarySearchTree::Remove(int key) {
    /*
   if (remove(key, root_) == false) {
     return false;
   }
   remove(key, root_);
   return true;
     */
  }

  void BinarySearchTree::Clear() {
   clear(root_);
   root_ = nullptr;
  }

  std::optional<int> BinarySearchTree::Find(int key) const {
    Node *found_node = find(key, root_);
    if (found_node == nullptr) {
      return std::nullopt;
    }
    return found_node->value;
  }

  bool BinarySearchTree::Contains(int key) const {
    return Find(key) == std::nullopt ? false : true;
  }

  bool BinarySearchTree::IsEmpty() const {
    return root_ == nullptr;
  }

  std::optional<int> BinarySearchTree::FindMin() const {
    if (root_ == nullptr) {
      return std::nullopt;
    }
    return find_min(root_)->value;
  }

  std::optional<int> BinarySearchTree::FindMax() const {
    if (root_ == nullptr) {
      return std::nullopt;
    }
    return find_max(root_)->value;
  }

  Node* BinarySearchTree::root() const {
    return root_;
  }

  // вспомогательные методы

  void BinarySearchTree::insert(int key, int value, Node*& node) {
   if (node == nullptr){
    Node *inserted_node = new Node(key, value);
    node = inserted_node;
   }
  else {
     if (key > node->key) {
       insert(key, value, node->right);
     } else if (key < node->key) {
       insert(key, value, node->left);
     } else {
       node->value = value;
     }
   }
  }

  bool BinarySearchTree::remove(int key, Node*& node) {
  if (node == nullptr){
    return false;
  }
  if (key == node->key){
    if (node->left != nullptr && node->right != nullptr){
      Node *min_node = find_min(node->right);
      node->key = min_node->key;
      node->value = min_node->value;
      return remove(min_node->key, node->right);
    }
    if (node->right == nullptr && node->left != nullptr){
      Node *left_child = node->left;
      delete node;
      node = left_child;
      return true;
    }

    Node *right_node = node->right;
    delete node;
    node = right_node;
    return true;
  }
  if (key < node->key){
    return remove(key, node->left);
  }
  return remove(key, node->right);
  }

  void BinarySearchTree::clear(Node* node) {
    if (node != nullptr){
      clear(node->left);
      clear(node->right);
    }
    delete node;
  }

  Node* BinarySearchTree::find(int key, Node* node) const {
    if (node == nullptr) {
      return nullptr;
    }
    if (key > node->key){
      find(key, node->right);
    }
    else if (key < node->key){
      find(key, node->left);
    }
    else {
      return node;
    }
  }

  Node* BinarySearchTree::find_min(Node* node) const {
    if (root_ == nullptr){
      return nullptr;
    }
    if (node->left != nullptr){
      return find_min(node->left);
    }
    return node;
  }

  Node* BinarySearchTree::find_max(Node* node) const {
    if (root_ == nullptr) {
      return nullptr;
    }
    if (node->right != nullptr){
      return find_max(node->right);
    }
    return node;
  }

}  // namespace assignment