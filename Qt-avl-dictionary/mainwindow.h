#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <algorithm>
using namespace std;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};
template <typename T>
class Node {
public:
    T value;
    Node<T>* left;
    Node<T>* right;
    int height;
    Node(const T& value) : value(value), left(nullptr), right(nullptr), height(1) {}
};

template <typename T>
class AVL {

public:
    //konstruktor domyślny
    AVL() : treeroot(nullptr) {};

    void insert(const T& elem) {
        treeroot = insertNode(treeroot, elem);
    }

    void remove(const T& elem) {
        treeroot = deleteNode(treeroot, elem);
    }


    void print() {
        printTree(treeroot);
    }


    bool exists(const T& value) {
        Node<T>* n = treeroot;
        while (n != nullptr) {
            if (n->value == value) {
                return true;
            }
            else if (value < n->value) {
                n = n->left;
            }
            else {
                n = n->right;
            }
        }
        return false;
    }

private:

    Node<T>* treeroot;

    int height(Node<T>* node) {
        if (node == nullptr)
            return 0;
        return node->height;
    }

    Node<T>* rotateRight(Node<T>* y) {
        Node<T>* x = y->left;
        Node<T>* z = x->right;
        x->right = y;
        y->left = z;
        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;
        return x;
    }

    Node<T>* rotateLeft(Node<T>* x) {
        Node<T>* y = x->right;
        Node<T>* z = y->left;
        y->left = x;
        x->right = z;
        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;
        return y;
    }

    int getBalanceFactor(Node<T>* N) {
        if (N == nullptr)
            return 0;
        return height(N->left) - height(N->right);
    }

    Node<T>* insertNode(Node<T>* node, const T& value) {
        if (node == nullptr)
            return (new Node<T>(value));
        if (value < node->value)
            node->left = insertNode(node->left, value);
        else if (value > node->value)
            node->right = insertNode(node->right, value);
        else
            return node;
        node->height = 1 + max(height(node->left), height(node->right));
        int balanceFactor = getBalanceFactor(node);
        if (balanceFactor > 1) {
            if (value < node->left->value) {
                return rotateRight(node);
            }
            else if (value > node->left->value) {
                if (node->left)
                    node->left = rotateLeft(node->left);
                return rotateRight(node);
            }
        }
        if (balanceFactor < -1) {
            if (value > node->right->value) {
                return rotateLeft(node);
            }
            else if (value < node->right->value) {
                if (node->left)
                    node->left = rotateRight(node->left);
                return rotateLeft(node);
            }
        }
        return node;
    }

    Node<T>* next(Node<T>* node) {
        Node<T>* current = node->right;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    Node<T>* deleteNode(Node<T>* root, const T& value) {
        if (root == nullptr)
            return root;
        if (value < root->value) {
            root->left = deleteNode(root->left, value);
        }
        else if (value > root->value) {
            root->right = deleteNode(root->right, value);
        }
        else {
            if ((root->left == nullptr) || (root->right == nullptr)) {
                Node<T>* temp = root->left ? root->left : root->right;
                if (temp == nullptr) {
                    temp = root;
                    root = nullptr;
                }
                else {
                    *root = *temp;
                }
                delete temp;

            }
            else {
                Node<T>* temp = next(root);
                root->value = temp->value;
                root->right = deleteNode(root->right, temp->value);
            }
        }
        if (root == nullptr) {
            return root;
        }
        root->height = 1 + max(height(root->left), height(root->right));
        int balanceFactor = getBalanceFactor(root);
        if (balanceFactor > 1) {
            if (getBalanceFactor(root->left) >= 0) {
                return rotateRight(root);
            }
            else {
                root->left = rotateLeft(root->left);
                return rotateRight(root);
            }
        }
        if (balanceFactor < -1) {
            if (getBalanceFactor(root->right) <= 0) {
                return rotateLeft(root);
            }
            else {
                root->right = rotateRight(root->right);
                return rotateLeft(root);
            }
        }
        return root;
    }

    void printTree(Node<T>* root) {
        if (root != nullptr) {
            printTree(root->left);
            cout << "[" << root->value << "] \n";
            printTree(root->right);
        }
    }
};



#endif // MAINWINDOW_H
