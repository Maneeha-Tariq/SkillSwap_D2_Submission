//BSEF24M046
#ifndef AVL_H
#define AVL_H
#include "AVLNode.h"
#include "Stack.h"
#include <iostream>
#include <initializer_list>
#include<fstream>
using namespace std;
template <typename T>
class Array
{
    T* data;
    int size;
    bool isValidIndex(int index) const
    {
        return (index >= 0 && index < size);

    }
public:
    Array()
    {
        data = nullptr;
        size = 0;
    }
    Array(int s) :Array()
    {
        if (s > 0)
        {
            data = new T[s];
            size = s;
        }
    }
    Array(const Array& r) :Array()
    {
        if (r.size <= 0)
            return;
        size = r.size;
        data = new T[size];
        for (int i = 0; i < size; i++)
        {
            data[i] = r.data[i];
        }
    }
    Array<T>& operator=(const Array<T>& r)
    {
        if (r.size == 0)
        {
            this->~Array();
            return *this;
        }
        if (this == &r)
            return *this;
        this->~Array();
        size = r.size;
        data = new T[size];
        int i;
        for (i = 0; i < size; i++)
        {
            data[i] = r.data[i];
        }
        return *this;
    }
    Array(Array<T>&& other) :Array()
    {
        data = other.data;
        size = other.size;
        other.data = nullptr;
        other.size = 0;
    }
    Array<T>& operator=(Array<T>&& other)
    {
        if (this == &other)
        {
            return *this;
        }
        delete[] data;

        data = other.data;
        size = other.size;

        other.data = nullptr;
        other.size = 0;

        return *this;
    }
    const T& operator [](int index) const
    {
        if (isValidIndex(index))
        {
            return data[index];
        }
        else
        {
            cout << "Index out of bound";
            exit(0);
        }
    }
    T& operator [](int index)
    {
        if (isValidIndex(index))
        {
            return data[index];
        }
        else
        {
            cout << "Index out of bound";
            exit(0);
        }
    }
    int getSize() const
    {
        return size;
    }
    void reSize(int s)
    {
        if (s <= 0)
        {
            this->~Array();
            return;
        }
        T* temp = new T[s];
        int i = 0;
        while (i < size && i < s)
        {
            temp[i] = data[i];
            i++;
        }
        this->~Array();
        data = temp;
        size = s;
    }
    ~Array()
    {
        if (data)
        {
            delete[]data;
            data = nullptr;
        }
        size = 0;
    }
    Array(initializer_list<T> val) :Array()
    {
        size = val.size();
        if (size == 0)
            return;
        data = new T[size];
        int i = 0;
        for (auto x : val)
        {
            data[i] = x;
            i++;
        }
    }
    const T* begin()
    {
        return &data[0];
    }
    const T* end()
    {
        return &data[size];
    }
};
template <typename T>
ostream& operator <<(ostream& out, const Array<T>& r)
{
    out << "{";
    for (int i = 0; i < r.getSize(); i++)
    {
        out << r[i];
        if (i < r.getSize() - 1)
        {
            out << " , ";
        }
    }
    out << "}";
    return out;
}
template <typename T>
istream& operator >>(istream& out, Array<T>& r)
{
    for (int i = 0; i < r.getSize(); i++)
    {
        out >> r[i];
    }
    return out;
}



enum Order { ASC, DESC };
template<typename T>
class AVL
{
    AVLNode<T>* root;

   
    int heightN(AVLNode<T>* p)
    {
        if (!p)
            return 0;
        int l = heightN(p->left);
        int r = heightN(p->right);
        return 1 + ((l > r) ? l : r);
    }

    AVLNode<T>* searchNode(T key)
    {
        if (!root) return nullptr;

        AVLNode<T>* p = root;
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

    void updateHeight(AVLNode<T>* node)
    {
        if (!node) return;
        int leftH = (node->left) ? node->left->height : 0;
        int rightH = (node->right) ? node->right->height : 0;
        node->height = 1 + max(leftH, rightH);
    }

    void rotateLL(AVLNode<T>* curr, Stack<AVLNode<T>*>& path)
    {
        AVLNode<T>* pivot = curr;
        AVLNode<T>* LP = pivot->left;
        AVLNode<T>* RLP = LP->right;

        LP->right = pivot;
        pivot->left = RLP;
        if (pivot == root)
        {
            root = LP;
        }
        else
        {
            AVLNode<T>* par = path.stackTop();
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
    void rotateLR(BTNode<T>* curr, AVLNode<T>* par)
    {
        AVLNode<T>* p = curr;
        AVLNode<T>* LP = p->left;
        AVLNode<T>* RLP = LP->right;
        AVLNode<T>* LRLP = RLP->left;
        AVLNode<T>* RRLP = RLP->right;


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
    void rotateRR(AVLNode<T>* curr, AVLNode<T>* par)
    {
        AVLNode<T>* p = curr;
        AVLNode<T>* RP = p->right;
        AVLNode<T>* LRP = RP->left;


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
    void rotateRL(AVLNode<T>* curr, AVLNode<T>* par)
    {
        AVLNode<T>* p = curr;
        AVLNode<T>* RP = p->right;
        AVLNode<T>* LRP = RP->left;
        AVLNode<T>* LLRP = LRP->left;
        AVLNode<T>* RLRP = LRP->right;

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
    void LVROrder(AVLNode<T>* p) {
        if (!p) return;

        LVROrder(p->left);
        cout << p->info << " ";
        cout << p->height << " ";
        LVROrder(p->right);
    }
    int findBalanceFactor(AVLNode<T>* p)
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

public:

    AVL() :root(nullptr)
    {
    }

    bool search(T key)
    {
        if (!root) return false;

        AVLNode<T>* p = root;
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
    bool insert(T val)
    {
        Stack<AVLNode <T>*> s;
        if (!root)
        {
            root = new AVLNode<T>(val);
            s.push(root);

            return true;
        }
        AVLNode<T>* p = root;
        while (p)
        {
            s.push(p);
            if (p->info > val)
            {

                if (p->left == nullptr)
                {
                    p->left = new AVLNode<T>(val);
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
                    p->right = new AVLNode<T>(val);
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
            AVLNode<T>* curr = s.pop();
            AVLNode<T>* par = s.isEmpty() ? nullptr : s.stackTop();
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
        return true;

    }
    bool remove(T key)
    {
        if (!root) return true;

        Stack<AVLNode<T>*> s;
        AVLNode<T>* par = nullptr;
        AVLNode<T>* p = root;
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
                    AVLNode<T>* succPar = p;
                    AVLNode<T>* succ = p->right;
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
            AVLNode<T>* curr = s.pop();
            AVLNode<T>* par = s.isEmpty() ? nullptr : s.stackTop();
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
        return true;
    }
    int getElementsCountInRange(int a, int b, Order ord = ASC)
    {
        AVLNode<T>* p = root;
        AVLNode<T> * aIndx = p.searchNode(a);
      
        int count = 0;
        while (!aIndx)
        {
            if (aIndx->info >= a && aIndx->left->info<= b)
            {
                count++;
                if (aIndx->left)
                {
                    aIndx = aIndx->left;
                }
                else
                {
                    aIndx = aIndx->right;
                }
            }
        }
        return count;
    }
    void printInRange(int a, int b)
    {
        AVLNode<T>* p = root;
        AVLNode<T>* aIndx = p.searchNode(a);
        AVLNode<T>* bIndx = p.searchNode(b);
        while (!aIndx)
        {
            if (aIndx->info >= a && aIndx->info <= b)
            {
                cout << aIndx->info << " ";
                if (aIndx->left)
                {
                    aIndx = aIndx->left;
                }
                else
                {
                    aIndx = aIndx->right;
                }
            }
            else
            {
                return;
            }
          
        }
        /* cout << aIndx->info<< " ";
           if (aIndx->left->info != b)
           {
               aIndx = aIndx->left;
           }
           else
           {
               return;
           }

           if (aIndx->right->info != b)
           {
               aIndx = aIndx->right;
           }
           else
           {
               return;
           }*/
        

    }
    Array<T> getElementsInRange(int a, int b, Order ord = ASC)
    {
        int count = getElementsCountInRange(a, b);
        Array<T> arr(count);
        AVLNode<T>* p = root;
        AVLNode<T>* aIndx = p.searchNode(a);
        int i = 0;
        while (!aIndx)
        {
            if (aIndx->info >= a && aIndx->info <= b)
            {
                arr[i++] = aIndx->info;
                if (aIndx->left)
                {
                    aIndx = aIndx->left;
                }
                else
                {
                    aIndx = aIndx->right;
                }
            }
            else
            {
                return;
            }
           
           
        }
        return arr;
        /* if (aIndx->left->info != b)
            {
                aIndx = aIndx->left;
            }
            else
            {
                return;
            }

            if (aIndx->right->info != b)
            {
                aIndx = aIndx->right;
            }
            else
            {
                return;
            }*/
       /* arr[i] = bIndx->info;*/

    }
    void print()
    {
        LVROrder(root);
        cout << endl;
    }
   AVL(const AVL<T>& other): AVL()
   {
       AVLNode<T>* p = root;
       AVLNode<T>* r = other.root;

       if (!r)
       {
           remove(root);
           return;
       }
      
       if (r && !root)
       {
           root = new AVLNode<T>;
           root->info = r->info;
       }
       else if (r && root)
       {
           p->info = r->info;
       }
      
       while (!p && !r)
       {
           if (p->left && r->left)
           {
               p->left->info = r->left->info;
               p = p->left;
               r = r->left;
           }
           else if (p->right && r->right)
           {
               p->right->info = r->right->info;
               p = p->right;
               r = r->right;
           }
           else if ((!p->left && r->left) || (!r->left && p->left))
           {
               if (!r->left && p->left)
               {
                   remove(p->left->info);
                   r = r->right;
                   p = p->right;
               }
               else
               {
                   p->left = new AVLNode<T>;
                   p->left = r->left->info;
                   r = r->left;

               }
           }
           else if ((!r->right && p->right) || (!p->right && r->right))
           {
               if (!r->right && p->right)
               {
                   remove(p->right->info);
                   r = r->left;
                   p = p->left;
               }
               else
               {
                   p->right = new AVLNode<T>;
                   p->right = r->right->info;
                   r = r->right;

               }
           }
       }
   }
   AVL<T>& operator = (const AVL<T>& r)
   {
       AVLNode<T>* other = r.root;
       AVLNode<T>* p = root;
       if (!other)
       {
           delete[] root;
           root = nullptr;
       }
       if (p == other)
           return root;

       p(other);
       return p;
   }
   bool& operator == (const AVL<T>& r)
   {
       AVL<T>* other = r.root;
       AVLNode<T>* p = root;
       if (!p && ! other)
       {
           return 0;
       }
       else if (!p && other)
       {
           return -1;
       }
       else if (p && !other)
       {
           return 1;
       }

      
       while (!p && !other)
       {

           if (p->info < other->info)
           {
               return -1;
           }
           else if (p->info > other->info)
           {
               return 1;
           }

           if (p->left && other->left)
           {
               p = p->left;
               other = other->left;
           }
           else if (p->left && !other->left)
           {
               return 1;
           }
           else if (!p->left && other->left)
           {
               return -1;
           }

           if (p->right && other->right)
           {
               p = p->right;
               other = other->right;
           }
           else if (p->right && !other->right)
           {
               return 1;
           }
           else if (!p->right && other->right)
           {
               return -1;
           }

       }
       if (p->info == other->info)
       {
           return 0;
       }
       else if (p->info < other->info)
       {
           return -1;
       }
       else
       {
           return 1;
       }
   }
   AVL(AVL<T>&& other)
   {
       AVLNode<T>* r = other.root;
       AVLNode<T>* p = root;

       p = r;

       delete[] r;
       r = nullptr;
   }
   AVL<T>& operator = (AVL<T>&& other)
   {
       AVLNode<T>* r = other.root;
       AVLNode<T>* p = root;

       if (p == r)
       {
           return root;
       }
       
       p = r;
       delete[] r;
       r = nullptr;

       return p;
   }
   ~AVL()
   {
       if (root)
       {
           delete[] root;
           root = nullptr;
       }
   }
  

};
#endif












