#ifndef LINKED_BINARY_TREE_H
#define LINKED_BINARY_TREE_H
#include "BTNode.h"
#include <iostream>
#include "String.h"
#include<fstream>
#include "Stack.h"
#include "Queue.h"
using namespace std;
enum SpecializationFormat{LEVEL_ORDER,FULLY_PARENTHESIS,COMMA_PARENTHESIS };
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
   /* int heightRightSubtree()
    {
        return height(root->right);
    }*/
    /*String fullyParenthesized(BTNode<T>* p)
    {
        if (!p)
            return String();

        String t = String(p->info);

        if (p->left)
        {
            t = t + String("(") + fullyParenthesized(p->left) + String(")");
        }
        else
        {

            t = t + String("()");
        }

        if (p->right)
        {
            t = t + String("(") + fullyParenthesized(p->right) + String(")");
        }
        else
        {
            t = t + String("()");
        }

        return t;
    }
    String serializeLevel(BTNode<T>* p)
    {
        if (!p)
            return String("#");

        String str(" ");
        Queue<BTNode<T>*> q;
        q.enQueue(p);

        while (!q.isEmpty())
        {
            BTNode<T>* curr = q.deQueue();

            if (curr == nullptr)
            {
                str = str + String("#,");
                continue;
            }

            str = str + String(curr->info);

            if (curr->left)
            {
                q.enQueue(curr->left);
            }
            else
            {
                q.enQueue(nullptr);
            }
            if (curr->right)
            {
                q.enQueue(curr->right);
            }
            else
            {
                q.enQueue(nullptr);
            }

        }

        return str;
    }
    String serializeComma(BTNode<T>* p)
    {
        String str(" ");
        if (!p)
            return String();

        str += String(p->info);

        if (p->left || p->right)
        {
            str += String("(");
            if (p->left)
            {
                serializeComma(p->left);
            }
            else
            {
                str += String(" ");
            }
            str += String(",");
            if (p->right)
            {
                serializeComma(p->right);
            }
            else
            {
                str += String(" ");
            }
            str += String(")");
        }
        return str;
    }*/
    int cNodes(BTNode<T>* p)
    {
       
        if (!p) return 0;
        
        return 1+ cNodes(p->left)+ cNodes(p->right);
    }
    int minV(BTNode<T>* p)
    {
        if (!p) return -1;

        int minVal = p->info;
        
        if (p->left)
        {
            int leftMin = minV(p->left);
            if (leftMin != -1 && leftMin < minVal)
            {
                minVal = leftMin;
            }
        }
        if (p->right)
        {
            int rightMin = minV(p->right);
            if (rightMin != -1 && rightMin < minVal)
            {
                minVal = rightMin;
            }
        }
        return minVal;
    }
    int cLeaf(BTNode<T>* p)
    {
        if (!p) return 0;

        if (!p->left && !p->right)
        {
            return 1;
        }

        return cLeaf(p->left) + cLeaf(p->right);
    }
    void nonRecVLR(BTNode<T>* p)
    {
        if (!p) return;
       
        Stack<BTNode<T>*> s;
        s.push(p);
        while (!s.isEmpty())
        {
            BTNode<T>* curr = s.pop();
            cout << curr->info<< " ";

            if (curr->right)
            {
                s.push(curr->right);
            }
            if (curr->left)
            {
                s.push(curr->left);
            }
           
        }
    }
   

           

    void nonRecLRV(BTNode<T>* root)
    {
        if (!root) return;

        Stack<BTNode<T>*> s1, s2;
        s1.push(root);

        while (!s1.isEmpty())
        {
            BTNode<T>* curr = s1.pop();
            s2.push(curr);

            if (curr->left) s1.push(curr->left);
            if (curr->right) s1.push(curr->right);
        }

        // Now pop from s2 to get post-order
        while (!s2.isEmpty())
        {
            cout << s2.pop()->info << " ";
        }
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

   /* String serializeFullyParenthesis()
    {
        String s = fullyParenthesized(root);
        return s;
    }
    String serializeLevelOrder()
    {
        String s = serializeLevel(root);
        return s;
    }
    String serializeCommaParenthesis()
    {
       String str=  serializeComma(root);
       return str;
    }*/
   /* void deserializeLevelOrder(String str)
    {
        if (str.isEmpty()) return;

        Queue<BTNode<T>*> q;
        int i = 0;
        int len = str.getSize();

        root = new BNode<T>(str[i]);
        q.enQueue(root);
        i++;
        
        while (!q.isEmpty()&& i< len)
        {
            BNode<T>* p = q.deQueue();
           
            if (i< len && str[i] != '#')
            {
                p->left = new BNode<T>(str[i]);
                q.enQueue(p->left);
            }
            else
            {
                p->left = nullptr;
            }
            i++;
            if (i< len && str[i] != '#')
            {
                p->right = new BNode<T>(str[i]);
                q.enQueue(p->right);
            }
            else
            {
                p->right = nullptr;
            }
            i++;
        }
    }*/
    int countNodes()
    {
        return cNodes(root);
    }
    int minVal()
    {
        
        return minV(root);

    }
    int countLeafNodes()
    {
        return cLeaf(root);
    }
  
    void saveTree(String filename, SpecializationFormat format)
    {
        ofstream ofs("dsa.txt");
        if (!ofs.is_open())
        {
            cout << "File not opened";
            return;
        }
        ofs << format << " "<< filename;
       
        ofs.close();
    }
    void loadTree(String filename)
    {
        ifstream ifs("dsa.txt");
        if (!ifs.is_open())
        {
            cout << "file not opened for reading mode";
            return;
        }
       
        ifs.clear();
        ifs.seekg(0);

        String  format;
        ifs >> format;

        filename = " ";
        char ch;
        while (ifs.get(ch))
        {
            filename += ch;
        }
        ifs.close();
    }
    void nonRecPreOrder()
    {
        nonRecVLR(root);
    }
    void nonRecPostOrder()
    {
        nonRecLRV(root);
    }
    int findBalanceFactor(T val)
    {
        BTNode<T> * p = search(root, val);
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
    void nonRecLVR(BTNode<T>* root)
    {
        Stack<BTNode<T>*> s;
        BTNode<T>* curr = root;

        while (curr || !s.isEmpty())
        {
            while (curr)
            {
                s.push(curr);
                curr = curr->left;
            }

            curr = s.pop();
            cout << curr->info << " ";

            curr = curr->right;
        }
    }
    bool isComplete(BTNode<T>* root)
    {
        if (!root) return true;

        Queue<BTNode<T>*> q;
        q.enqueue(root);

        bool nullFound = false;

        while (!q.isEmpty())
        {
            BTNode<T>* curr = q.dequeue();

            if (curr == NULL)
            {
                nullFound = true;
            }
            else
            {
                if (nullFound)
                    return false;

                q.enqueue(curr->left);
                q.enqueue(curr->right);
            }
        }
        return true;
    }
    bool isFullBT(BTNode<int>* root) {
        if (!root) return true;                 // Empty tree
        if (!root->left && !root->right) return true;  // Leaf node

        if (root->left && root->right) {        // 2 children
            return isFullBT(root->left) && isFullBT(root->right);
        }

        return false;  // 1 child only
    }


};

#endif