//
// Created by Jacob on 10/19/2022.
//

#ifndef HW5_BINARY_SEARCH_TREE_H
#define HW5_BINARY_SEARCH_TREE_H

#include <ostream>

namespace BST {

    template <class T> class binary_search_tree {
        struct TreeNode{
            T data;
            TreeNode* left;
            TreeNode* right;
        };
    public:
        binary_search_tree();
        ~binary_search_tree();
        void Destroy(TreeNode*& tree);
        int countNodes(TreeNode* tree);
        void makeEmpty();
        bool isEmpty();
        bool isFull();
        int getLength();
        T getItem(T item, bool& found);
        void retrieveItem(TreeNode* tree, T& item, bool& found);
        void putItem(T item);
        void insert(TreeNode* tree, T item);
        void deleteItem(T item);
        void Delete(TreeNode*& tree, T item);
        void deleteNode(TreeNode*& tree);
        void getPredecessor(TreeNode* tree, T &data);
        void print(std::ostream& outStream);
        void printTree(TreeNode* tree, std::ostream& outStream);
    private:
        TreeNode* root;
    };

    template<class T>
    binary_search_tree<T>::binary_search_tree() {
             root = nullptr;
    }

    template<class T>
    binary_search_tree<T>::~binary_search_tree() {
        Destroy(root);
    }

    template<class T>
    void binary_search_tree<T>::Destroy(binary_search_tree::TreeNode *&tree) {
        if (tree != nullptr){
            Destroy(tree->left);
            Destroy(tree->right);
            delete tree;
        }
    }

    template<class T>
    void binary_search_tree<T>::makeEmpty() {

    }
    /**
     *
     * @tparam T ItemType
     * @return Returns true is tree is empty.
     */
    template<class T>
    bool binary_search_tree<T>::isEmpty() {
        return root == nullptr;
    }

    /**
     *
     * @tparam T ItemType
     * @return Returns true if free store has no room for another node
     */
    template<class T>
    bool binary_search_tree<T>::isFull() {
        TreeNode* newNode;
        try {
            newNode = new TreeNode;
            delete newNode;
            return false;
        } catch (std::bad_alloc &e) {
            return true;
        }
    }

    template<class T>
    int binary_search_tree<T>::getLength() {
        return countNodes(root);
    }

    template<class T>
    T binary_search_tree<T>::getItem(T item, bool &found) {
        retrieveItem(root, item, found);
        return item;
    }

    template<class T>
    void binary_search_tree<T>::retrieveItem(binary_search_tree::TreeNode *tree, T &item, bool &found) {
        //Base Case
        if (tree == nullptr){
            found = false;
            //Item in left child
        } else if (item < tree->data){
            retrieveItem(tree->left, item, found);
            //Item in right child
        } else if (item > tree->data){
            retrieveItem(tree->right, item, found);
            //Found item
        } else {
            item = tree->data;
            found = true;
        }
    }

    template<class T>
    void binary_search_tree<T>::putItem(T item) {
        insert(root, item);
    }
    template<class T>
    void binary_search_tree<T>::insert(binary_search_tree::TreeNode *tree, T item) {
        if (tree == nullptr){
            tree = new TreeNode;
            tree->right = nullptr;
            tree->left = nullptr;
            tree->data = item;
        } else if (item < tree->data){
            insert(tree->left, item);
        } else {
            insert(tree->right, item);
        }
    }

    template<class T>
    void binary_search_tree<T>::deleteItem(T item) {
            Delete(root, item);
    }
    template<class T>
    void binary_search_tree<T>::Delete(binary_search_tree::TreeNode *&tree, T item) {
            if (item < tree->data){
                Delete(tree->left, item);
            } else if (item > tree->data){
                Delete(tree->right, item);
            } else {
                deleteNode(tree);
            }
    }

    template<class T>
    void binary_search_tree<T>::deleteNode(binary_search_tree::TreeNode *&tree) {
        T data;
        TreeNode* tempPtr;

        tempPtr = tree;
        if (tree->left == nullptr){
            tree = tree->right;
            delete tempPtr;
        } else if (tree->right == nullptr){
            tree = tree->left;
        } else {
            getPredecessor(tree->left, data);
            tree->data = data;
            Delete(tree->left, data);
        }
    }

    template<class T>
    void binary_search_tree<T>::getPredecessor(binary_search_tree::TreeNode* tree, T& data) {
        while (tree->right != nullptr){
            tree = tree->right;
        }
        data = tree->data;
    }

    template<class T>
    void binary_search_tree<T>::print(std::ostream& outStream) {
        outStream << "---------[Tree]----------" << std::endl;
        printTree(root, outStream);
        outStream << "-------------------------" << std::endl;
    }

    template<class T>
    void binary_search_tree<T>::printTree(binary_search_tree::TreeNode* tree,std::ostream& outStream) {
        if (tree != nullptr){
            printTree(tree->left, outStream);
            outStream << tree->data;
            printTree(tree->right, outStream);
        }
    }

    template<class T>
    int binary_search_tree<T>::countNodes(binary_search_tree::TreeNode *tree) {
        if (tree == nullptr){
            return 0;
        } else {
            return countNodes(tree->left) + countNodes(tree->right) + 1;
        }
    }



} // BST

#endif //HW5_BINARY_SEARCH_TREE_H
