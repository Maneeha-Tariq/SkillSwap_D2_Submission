#ifndef LINKED_BINARY_TREE_H
#define LINKED_BINARY_TREE_H
#include "BTNode.h"
#include <iostream>
#include "Queue.h"
using namespace std;
template<typename T>
class BinaryTree {
private:
    BTNode<T>* root;

    void VLR(BTNode<T>* p)
    {
        if (!p)
            return;
        cout << p->info << ",";
        VLR(p->left);
        VLR(p->right);
    }

    void LVR(BTNode<T>* p)
    {
        if (!p)
            return;
        LVR(p->left);
        cout << p->info << ",";
        LVR(p->right);
    }

    void LRV(BTNode<T>* p)
    {
        if (!p)
            return;
        LRV(p->left);
        LRV(p->right);
        cout << p->info << ",";
    }


    int height(BTNode<T>* p)
    {
        if (!p)
            return 0;
        int l = height(p->left);
        int r = height(p->right);
        return 1 + ((l > r) ? l : r);
    }


    void parenthesizedView(BTNode<T>* p)
    {
        if (!p)
            return;
        cout << p->info;
        if (p->left || p->right)
        {
            cout << "(";
            if (p->left)
            {
                parenthesizedView(p->left);
            }
            else
            {
                cout << " ";
            }
            cout << ",";
            if (p->right)
            {
                parenthesizedView(p->right);
            }
            else
            {
                cout << " ";
            }
            cout << ")";
        }
    }


    void explorerView(BTNode<T>* p, int depth)
    {
        if (!p)
            return;
        for (int i = 0; i < depth; i++)
        {
            cout << "\t";
        }
        cout << p->info << endl;
        explorerView(p->left, depth + 1);
        explorerView(p->right, depth + 1);
    }

    BTNode<T>* search(BTNode<T>* p, T key)
    {
        if (!p)
            return nullptr;
        if (p->info == key)
            return p;
        BTNode<T>* l = search(p->left, key);
        if (l)
            return l;
        return search(p->right, key);
    }

    BTNode<T>* getParentNode(BTNode<T>* p, T key)
    {
        if (!p)
            return nullptr;
        if ((p->left && p->left->info == key) || (p->right && p->right->info == key))
            return p;
        BTNode<T>* l = getParentNode(p->left, key);
        if (l)
            return l;
        return getParentNode(p->right, key);
    }

    void removeNode(BTNode<T>*& p)
    {
        if (!p)
            return;
        removeNode(p->left);
        removeNode(p->right);
        delete p;
        p = nullptr;
    }

    void displayDescendents(BTNode<T>* p)
    {
        if (!p)
            return;
        if (p->left)
        {
            cout << p->left->info << ",";
            displayDescendents(p->left);
        }
        if (p->right)
        {
            cout << p->right->info << ",";
            displayDescendents(p->right);
        }
    }

    void displayAncestors(BTNode<T>* p, T key)
    {
        BTNode<T>* parent = getParentNode(p, key);
        if (!parent)
            return;
        cout << parent->info << ",";
        displayAncestors(p, parent->info);
    }


    void displayLevel(BTNode<T>* p, int level)
    {
        if (!p)
            return;
        if (level == 0)
        {
            cout << p->info << ",";
            return;
        }
        displayLevel(p->left, level - 1);
        displayLevel(p->right, level - 1);
    }

    int findLevel(BTNode<T>* p, T key, int level)
    {
        if (!p)
            return -1;
        if (p->info == key)
            return level;
        int left = findLevel(p->left, key, level + 1);
        if (left != -1)
            return left;
        return findLevel(p->right, key, level + 1);
    }

public:

    BinaryTree() : root(nullptr)
    {
    }

    void setRoot(T val)
    {
        if (!root)
            root = new BTNode<T>(val);
    }

    void setLeftChild(T parent, T child)
    {
        BTNode<T>* p = search(root, parent);
        if (p && !p->left)
            p->left = new BTNode<T>(child);
    }

    void setRightChild(T parent, T child)
    {
        BTNode<T>* p = search(root, parent);
        if (p && !p->right)
            p->right = new BTNode<T>(child);
    }

    T getParent(T node)
    {
        BTNode<T>* p = getParentNode(root, node);
        if (!p)
        {
            exit(0);
        }
        return p->info;
    }

    void remove(T node)
    {
        if (!root) return;
        if (root->info == node)
        {
            removeNode(root);
            root = nullptr;
            return;
        }
        BTNode<T>* parent = getParentNode(root, node);
        if (!parent)
        {
            return;
        }
        if (parent->left && parent->left->info == node)
        {
            removeNode(parent->left);
        }
        if (parent->right && parent->right->info == node)
        {
            removeNode(parent->right);
        }
    }

    void preOrder()
    {
        VLR(root);
        cout << endl;
    }
    void inOrder()
    {
        LVR(root);
        cout << endl;
    }
    void postOrder()
    {
        LRV(root);
        cout << endl;
    }


    int heightOfTree()
    {
        return height(root);
    }


    void levelOrder()
    {
        if (!root)
            return;

        Queue<BTNode<T>*> q;
        q.enQueue(root);

        bool first = true;

        while (!q.isEmpty())
        {
            BTNode<T>* curr = q.deQueue();

            if (!first)
                cout << ",";
            cout << curr->info;
            first = false;

            if (curr->left)
                q.enQueue(curr->left);

            if (curr->right)
                q.enQueue(curr->right);
        }

        cout << endl;
    }


    void displayLevel(int level)
    {
        displayLevel(root, level);
        cout << "\n";
    }


    int findLevelOfNode(T node)
    {
        return findLevel(root, node, 0);
    }

    void displayParenthesizedView()
    {
        parenthesizedView(root);
        cout << "\n";
    }
    void displayExplorerView()
    {
        explorerView(root, 0);
    }


    void displayDescendents(T node)
    {
        BTNode<T>* p = search(root, node);
        if (!p)
            return;
        displayDescendents(p);
        cout << "\n";
    }

    void displayAncestors(T node)
    {
        displayAncestors(root, node);
        cout << "\n";
    }

    ~BinaryTree()
    {
        removeNode(root);
    }
};

#endif