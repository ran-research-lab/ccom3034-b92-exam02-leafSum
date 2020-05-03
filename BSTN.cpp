//
// Created by rarce on 04/28/20.
//

#include "BSTN.h"
#include <iostream>

using namespace std;

// function search:
//    Given k, a key to search, returns a pointer to the first
//    node that contains such key. If not found returns a NULL pointer.

BTNode* BSTN::search(int k) const {
    BTNode* cur = root;
    while (cur) {
        if (k == cur->key)     {return cur;}
            // Found
        else if (k < cur->key) { cur = cur->left; }
        else                   { cur = cur->right; }
    }
    return NULL;
}


// function insert:
//    Given k, a key to insert, inserts into the BST.
//    In this implementation if the key already exists in the tree
//    it will be inserted in the RIGHT subtree of the existing key.

void BSTN::insert(int k) {
    BTNode *cur;
    BTNode *n = new BTNode(k);

    if (!root) {
        // This tree is empty, the new node is the root!
        root = n;
    }
    else {
        // Lets search the tree for a place to insert....
        cur = root;
        while (cur) {
            if (k < cur->key){
                // The value to insert is less than current node
                if (cur->left == NULL) {
                    // If we have reached a node who lacks a left child
                    // then our new node will be the left child
                    cur->left = n;
                    cur = NULL;
                }
                else {
                    // keep looking for a place to insert, on the left subtree
                    cur = cur->left;
                }
            }
            else {
                // The value to insert is greater or equal than current node
                if (cur->right == NULL){
                    // If we have reached a node who lacks a right child
                    // then our new node will be the right child
                    cur->right = n;
                    cur = NULL;
                }
                else {
                    // keep looking for a place to insert, on the right subtree
                    cur = cur->right;
                }
            }
        }
    }
}

// functions recDisplay:
//    Print the tree to the standard output.

void BSTN::recDisplay(ostream &out) const {
    recDisplay(out, root, 0);
}

void BSTN::recDisplay(ostream &out, BTNode *cur, int dist) const{
    if (cur) {
        if (cur->right) recDisplay(out, cur->right, dist + 1);
        for (int i = 0; i < dist; i++) cout << "    ";
        out << cur->key << endl;
        if (cur->left) recDisplay(out, cur->left, dist + 1);
    }
}

// functions remove:
//    Given k, a key to remove, removes the first node that it finds with
//    such key.


void BSTN::remove(int k) {
    remove(k, root);
}

void BSTN::remove(int k, BTNode *r) {
    BTNode *parent = NULL;
    BTNode *cur = r;
    while (cur) { // Search for node
        if (cur->key == k) { // Node found
            if (cur->left == NULL && cur->right == NULL) {        // Remove leaf
                cout << "cur is a leaf: " << cur->key << endl;
                if (!parent) { // Node is root
                    root = NULL;
                }
                else if (parent->left == cur)
                    parent->left = NULL;
                else
                    parent->right = NULL;
                delete cur;
            }
            else if (cur->left && cur->right == NULL) {    // Remove node with only left child
                if (!parent) // Node is root
                    root = cur->left;
                else if (parent->left == cur)
                    parent->left = cur->left;
                else
                    parent->right = cur->left;
                delete cur;
            }
            else if (cur->left == NULL && cur->right) {    // Remove node with only right child
                if (!parent) // Node is root
                    root = cur->right;
                else if (parent->left == cur)
                    parent->left = cur->right;
                else
                    parent->right = cur->right;
                delete cur;
            }
            else {                                  // Remove node with two children
                // Find successor (leftmost child of right subtree)
                BTNode *suc = cur->right;

                while (suc->left )
                    suc = suc->left;
                int successorData = suc->key;
                remove(suc->key, cur);     // Remove successor
                cur->key = successorData;
            }
            return; // Node found and removed
        }
        else if (cur->key < k) { // Search right
            parent = cur;
            cur = cur->right;
        }
        else {                     // Search left
            parent = cur;
            cur = cur->left;
        }
    }
    return; // Node not found
}


// function InOrder:
//    Will return a string containing the sequence of visited keys
//    during an in-order traversal (BFS) of the tree.

string BSTN::InOrder() const {
    string st;
    InOrder(root, st);
    return st;
}
void BSTN::InOrder(BTNode *n, string &st) const {
    if (n) {
        InOrder(n->left, st);
        st = st + to_string(n->key) + " ";
        InOrder(n->right, st);
    }
}

// function BFS:
//    Will return a string containing the sequence of visited keys
//    during a breadth-first traversal of the tree.

string BSTN::BFS() const {
    string st;
    queue<BTNode*> q;

    if(root!=NULL) q.push(root);

    while(!q.empty()) {
        BTNode *f = q.front();
        st.append(to_string(f->key));
        st.append(" ");
        if (f->left  != NULL) q.push(f->left);
        if (f->right != NULL) q.push(f->right);
        q.pop();
    }

    return st;
}


// function searchRec:
//    A recursive version of the search algorithm.

BTNode* BSTN::searchRec(int k) const { return searchRec(k,root); }

BTNode* BSTN::searchRec(int k, BTNode *r) const {
    if (r) {
        if (k == r->key) return r;
        else if (k < r->key)
            return searchRec(k, r->left);
        else
            return searchRec(k, r->right);
    }
    return NULL;
}

// function insertRec:
//    A recursive version of the insert algorithm.

void BSTN::insertRec(int k) {
    if (!root) root = new BTNode(k);
    else insertRec(k, root);
}
void BSTN::insertRec(int k, BTNode *r) {
    if (k < r->key) {
        if (r->left == NULL) r->left = new BTNode(k);
        else insertRec(k, r->left);
    }
    else { // k is greater than r->key
        if (r->right == NULL) r->right = new BTNode(k);
        else insertRec(k, r->right);
    }
}