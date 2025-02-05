//红黑树demo，不用.h文件
#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int val;
    Node *left, *right, *parent;
    bool color; // 0 for black, 1 for red
    Node(int val) : val(val), left(NULL), right(NULL), parent(NULL), color(1) {} // default color is red
};

class RedBlackTree {
private:
    Node *root;
    void rotateLeft(Node *node);
    void rotateRight(Node *node);
    void fixInsert(Node *node);
    void fixDelete(Node *node);
public:
    Node* getRoot() {
        return root;
    }
    RedBlackTree() : root(NULL) {}
    void insert(int val);
    void remove(int val);
    void inorderTraversal(Node *node);
};

void RedBlackTree::rotateLeft(Node *node) {
    Node *rightChild = node->right;
    node->right = rightChild->left;
    if (rightChild->left != NULL) {
        rightChild->left->parent = node;
    }
    rightChild->parent = node->parent;
    if (node->parent == NULL) {
        root = rightChild;
    } else if (node == node->parent->left) {
        node->parent->left = rightChild;
    }
    else {
        node->parent->right = rightChild;
        rightChild->left = node; // update parent pointer of left child of rightChild to node
        node->parent = rightChild; // update parent pointer of node to rightChild
        rightChild->left->parent = node;
        rightChild->color = node->color;
        node->color = 1;
        node->parent = rightChild;
        rightChild->left->color = 1;
        rightChild->right->color = 0;
    }

}

int main() {
    RedBlackTree tree;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    for (int num : nums) {
        tree.insert(num);
    }
    tree.inorderTraversal(tree.getRoot());
    cout << endl;
    return 0;
}
