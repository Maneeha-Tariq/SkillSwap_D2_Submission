
#ifndef HUFFMAN_H
#define HUFFMAN_H
#include <iostream>
#include "MaxHeap.h"
#include "MinHeap.h"
#include "String.h"
#include "Node.h"
using namespace std;

class Huffman
{
private:
    String message;
    Node* root;
   
    MinHeap<MaxHeap<Node*>*>* heap;

    void print(Node* node, String code)
    {
        if (!node) return;
        if (!node->left && !node->right)
            cout << node->sym->ch << " : " << code << endl;

       
        print(node->left, code + "0");
        print(node->right, code + "1");
    }

    
    void destroyTree(Node* node) {
        if (!node) return;
        destroyTree(node->left);
        destroyTree(node->right);
        delete node->sym;
        delete node;
    }

public:
    Huffman(String msg) : message(msg), root(nullptr), heap(nullptr) {}

    void build()
    {
        if (message.getLength() == 0) return;

       
        int n = message.getLength();
        int* freq = new int[n];
        String uniqueChars;
        for (int i = 0; i < n; i++) freq[i] = 0;

        for (int i = 0; i < n; i++)
        {
            char c = message[i];
            int index = -1;
            for (int j = 0; j < uniqueChars.getLength(); j++)
            {
                if (uniqueChars[j] == c)
                {
                    index = j;
                    break;
                }
            }
            if (index != -1)
            {
                freq[index]++;
            }
            else
            {
                uniqueChars += c;
                freq[uniqueChars.getLength() - 1] = 1;
            }
        }

        int uniqueCount = uniqueChars.getLength();
        if (uniqueCount == 0) { delete[] freq; return; }

        heap = new MinHeap<MaxHeap<Node*>*>(uniqueCount);

        
        for (int i = 0; i < uniqueCount; i++)
        {
           
            MaxHeap<Node*>* mh = new MaxHeap<Node*>(1);
            Node* n = new Node(new Symbol(uniqueChars[i], freq[i]));
            mh->insert(n);
            heap->insert(mh);
        }

        
        while (heap->getNoOfElements() > 1)
        {
            
            MaxHeap<Node*>* h1 = heap->remove();
            MaxHeap<Node*>* h2 = heap->remove();

           
            Node* node1 = h1->remove();
            Node* node2 = h2->remove();

           
            delete h1;
            delete h2;

           
            int combinedFreq = node1->sym->freq + node2->sym->freq;
            Symbol* s = new Symbol('\0', combinedFreq); 
            Node* parent = new Node(s, node1, node2);

            
            MaxHeap<Node*>* newHeap = new MaxHeap<Node*>(1);
            newHeap->insert(parent);

            heap->insert(newHeap);
            root = parent; 
        }

      
        if (root == nullptr && uniqueCount == 1) {
            root = heap->remove()->remove(); 
        }
        delete[] freq;
    }

    void showCodes()
    {
        if (root) {
            cout << "--- Huffman Codes ---\n";
            print(root, "");
            cout << "---------------------\n";
        }
        else {
            cout << "No message or tree to display.\n";
        }
    }

    ~Huffman()
    {
        destroyTree(root); 
        delete heap;
    }
};
#endif
