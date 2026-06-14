#ifndef BST_H
#define BST_H
#include "BTNode.h"
#include<iostream>
using namespace std;
template<typename T>
class BST
{
    BTNode<T>* root;

    void doubleTre(BTNode<T> * p)
    {
        if (!p) return;

        BTNode<T>* r = p;
        BTNode<T>* q = new BTNode<T>(r->info);
       
        if (r->left)
        {
            BTNode<T>* d = r->left;
            doubleTre(d);
            q->left = r->left;
            r->left = q;
        }
        else if (!r->left)
        {
            r->left = q;
        }

        if (r->right)
        {
            doubleTre(r->right);
        }
    }
    int height(BTNode<T>* p)
    {
        if (!p)
            return 0;
        int l = height(p->left);
        int r = height(p->right);
        return 1 + ((l > r) ? l : r);
    }
  /*  BTNode<T>* searchNode(BTNode<T>* p, T key)
    {
        if (!p)
            return nullptr;
        if (p->info == key)
            return p;
        BTNode<T>* l = search(p->left, key);
        if (l)
            return l;
        return search(p->right, key);
    }*/
    BTNode<T>* searchNode(T key)
    {
        if (!root) return nullptr ;

        BTNode<T>* p = root;
        while (p)
        {
            if (p->info == key)
            {
                return p;
            }
            else if (p->info > key)
            {
                p = p->left;
            }
            else
            {
                p = p->right;
            }
        }
        return nullptr;
    }

public:
   
    BST() :root(nullptr)
    { }

    bool search(T key)
    {
        if (!root) return false;

        BTNode<T>* p = root;
        while (p)
        {
            if (p->info == key)
            {
                return true;
            }
            else if (p->info > key)
            {
                p = p->left;
            }
            else
            {
                p = p->right;
            }
        }
        return false;
    }
    void insert(T val)
    {
        if (!root)
        {
            root = new BTNode<T>(val);
            return;
        }
        BTNode<T>* p = root;
        while (p)
        {
            if (p->info > val)
            {
                if (p->left == nullptr)
                {
                    p->left = new BTNode<T>(val);
                    return;
                }
                else
                {
                    p = p->left;
                }
            }
            else
            {
                if (p->right == nullptr)
                {
                    p->right = new BTNode<T>(val);
                    return;
                }
                else
                {
                    p = p->right;
                }
            }
        }
    }
    void remove(T key)
    {
        if (!root) return;

        BTNode<T>* par = nullptr;
        BTNode<T>* p = root;
        while (p)
        {
            if (p->info == key)
            {
                if (p->left == nullptr && p->right == nullptr)
                {
                    if (p == root)
                    {
                        delete root;
                        root = nullptr;
                    }
                    else if (par->left == p)
                    {
                        par->left = nullptr;
                        delete p;
                    }
                    else
                    {
                        par->right = nullptr;
                        delete p;
                    }
                    return;
                }
                else if ((p->left != nullptr && p->right == nullptr) || (p->right != nullptr && p->left == nullptr))
                {
                    if (p == root)
                    {
                        if (p->right)
                        {
                            root = p->right;
                        }
                        else
                        {
                            root = p->left;
                        }
                        delete p;
                    }
                    else  if (par->left == p)
                    {
                        if (p->right)
                        {
                            par->left = p->right;
                        }
                        else
                        {
                            par->left = p->left;
                        }
                        delete p;
                    }
                    else
                    {
                        if (p->right)
                        {
                            par->right = p->right;
                        }
                        else
                        {
                            par->right = p->left;
                        }
                        delete p;
                    }
                    return;
                }
                else
                {
                    BTNode<T>* succPar = p;
                    BTNode<T>* succ= p->right;
                    while (succ->left != nullptr)
                    {
                        succPar = succ;
                        succ = succ->left;
                    }

                    p->info = succ->info;

                    if (succPar->left == succ)
                    {
                        succPar->left = succ->right;
                    }
                    else
                    {
                        succPar->right = succ->right;
                    }
                    delete succ;
                    return;
                }
            }
            else if (p->info > key)
            {
                par = p;
                p = p->left;
            }
            else
            { 
                par = p;
                p = p->right;
            }
        }

    }
    void doubleTree()
    {
        doubleTre(root);
    }
    void preOrderPrint() {
        preOrder(root);
        cout << endl;
    }
    void preOrder(BTNode<T>* p) {
        if (!p) return;

        cout << p->info << " ";
        preOrder(p->left);
        preOrder(p->right);
    }
    int findBalanceFactor(T val)
    {
        BTNode<T>* p = searchNode( val);
        if (p)
        {
            if (!p->left && !p->right)
            {
                return 0;
            }
            else if (p->left && !p->right)
            {
                return height(p->left) - 0;
            }
            else if (p->right && !p->left)
            {
                return 0 - height(p->right);
            }
            else
            {
                return height(p->left) - height(p->right);
            }
        }
        else
        {
            cout << "Node not found\n";
            exit(0);
        }
    }

};
#endif