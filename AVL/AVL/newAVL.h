#ifndef NEWAVL_H
#define NEWAVL_H
#include "BTNode.h"
#include "Stack.h"
#include<iostream>
using namespace std;
template<typename T>
class newAVL
{
    BTNode<T>* root;

    void doubleTre(BTNode<T>* p)
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
    int heightN(BTNode<T>* p)
    {
        if (!p)
            return 0;
        int l = heightN(p->left);
        int r = heightN(p->right);
        return 1 + ((l > r) ? l : r);
    }

    BTNode<T>* searchNode(T key)
    {
        if (!root) return nullptr;

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
  
void updateHeight(BTNode<T>* node)
{
    if (!node) return;
    int leftH = (node->left) ? node->left->height : 0;
    int rightH = (node->right) ? node->right->height : 0;
    node->height = 1 + max(leftH, rightH);
}

    void rotateLL(BTNode<T>* curr, Stack<BTNode<T>*>& path)
    {
        BTNode<T>* pivot = curr;
        BTNode<T>* LP= pivot->left;
        BTNode<T>* RLP= LP->right;

        LP->right = pivot;
        pivot->left = RLP;
        if (pivot == root)
        {
            root = LP;
        }
        else
        {
           BTNode<T>* par = path.stackTop();
            if (par->left == pivot)
            {
                par->left = LP;
            }
            else
            {
                par->right = LP;
            }
        }
        updateHeight(pivot);
        updateHeight(LP);
    }
    void rotateLR(BTNode<T>* curr, BTNode<T> * par)
    {
        BTNode<T>* p = curr;
        BTNode<T>* LP = p->left;
        BTNode<T>* RLP = LP->right;
        BTNode<T>* LRLP = RLP->left;
        BTNode<T>* RRLP = RLP->right;
      

        RLP->left = LP;
        RLP->right = p;
        LP->right = LRLP;
        p->left = RRLP;

        if (p == root)
        {
            root = RLP;
        }
        else
        {
            if (par->left == p)
            {
                par->left = RLP;
            }
            else
            {
                par->right = RLP;
            }
        }
        updateHeight(LP);
        updateHeight(p);
        updateHeight(RLP);

    }
    void rotateRR(BTNode<T>* curr, BTNode<T>* par)
    {
        BTNode<T>* p = curr;
        BTNode<T>* RP = p->right;
        BTNode<T>* LRP = RP->left;
       

        RP->left = p;
        p->right = LRP;
        if (p == root)
        {
            root = RP;
        }
        else
        {
            if (par->left == p)
            {
                par->left = RP;
            }
            else
            {
                par->right = RP;
            }
        }
        updateHeight(p);
        updateHeight(RP);
    }
    void rotateRL(BTNode<T>* curr, BTNode<T> * par)
    {
        BTNode<T>* p = curr;
        BTNode<T>* RP = p->right;
        BTNode<T>* LRP = RP->left;
        BTNode<T>* LLRP = LRP->left;
        BTNode<T>* RLRP = LRP->right;

        LRP->left = p;
        LRP->right = RP;
        p->right = LLRP;
        RP->left = RLRP;


        if (p == root)
        {
            root = LRP;
        }
        else
        {
            if (par->left == p)
            {
                par->left = LRP;
            }
            else
            {
                par->right = LRP;
            }
        }
        
        updateHeight(p);
        updateHeight(RP);
        updateHeight(LRP);

    }

public:

    newAVL() :root(nullptr)
    {
    }

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
        Stack<BTNode <T>*> s;
        if (!root)
        {
            root = new BTNode<T>(val);
            s.push(root);

            return;
        }
        BTNode<T>* p = root;
        while (p)
        {
            s.push(p);
            if (p->info > val)
            {

                if (p->left == nullptr)
                {
                    p->left = new BTNode<T>(val);
                    break;
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
                    break;
                }
                else
                {
                    p = p->right;
                }
            }
        }
        while (!s.isEmpty())
        {
            BTNode<T>* curr = s.pop();
            BTNode<T>* par = s.isEmpty() ? nullptr : s.stackTop();
            updateHeight(curr);

            int bf = findBalanceFactor(curr);
            if (bf == 2)
            {
                if (findBalanceFactor(curr->left) > 0)
                {
                    rotateLL(curr, s);
                }
               else 
               {
                    rotateLR(curr,par);
               }
            }
            else if (bf == -2)
            {
                if (findBalanceFactor(curr->right) <= 0)
                {
                    rotateRR(curr, par);
                }
                else
                {
                    rotateRL(curr, par);
                }
            }
        }


    }
    void remove(T key)
    {
        if (!root) return;

        Stack<BTNode<T>*> s;
        BTNode<T>* par = nullptr;
        BTNode<T>* p = root;
        while (p)
        {
            
            s.push(p);
            
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
                    break;
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
                    break;
                }
                else
                {
                    BTNode<T>* succPar = p;
                    BTNode<T>* succ = p->right;
                    while (succ->left != nullptr)
                    {
                        succPar = succ;
                        succ = succ->left;
                        s.push(succPar);
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
                    break;
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
        while (!s.isEmpty())
        {
            BTNode<T>* curr = s.pop();
            BTNode<T>* par = s.isEmpty() ? nullptr : s.stackTop();
            updateHeight(curr);

            int bf = findBalanceFactor(curr);
            if (bf == 2)
            {
                if (findBalanceFactor(curr->left) > 0)
                {
                    rotateLL(curr, s);
                }
                else
                {
                    rotateLR(curr, par);
                }
            }
            else if (bf == -2)
            {
                if (findBalanceFactor(curr->right) <= 0)
                {
                    rotateRR(curr, par);
                }
                else
                {
                    rotateRL(curr, par);
                }
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
    int findBalanceFactor(BTNode<T>* p)
    {
        if (!p)
        {
            return 0;
        }
        int l = (p->left) ? p->left->height : 0;
        int r = (p->right) ? p->right->height : 0;
        int b = l - r;
        return b;
       
    }

};
#endif












