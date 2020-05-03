//
// Created by rarce on 04/28/20.
//

#ifndef BSTN_B92_BSTN_H
#define BSTN_B92_BSTN_H
#include <iostream>
#include <queue>
using namespace std;

class BTNode {
public:
    int key;
    BTNode *left, *right;
    BTNode(int k = 0, BTNode *l = NULL, BTNode *r = NULL) : key(k), left(l), right(r) {}
};

class BSTN {
private:
    BTNode *root;

public:
    BSTN(): root(NULL) {}
    void insert(int k);
    void insertRec(int k);
    void insertRec(int k, BTNode *r);

    void remove(int k);
    void remove(int k, BTNode *r);
    void recDisplay(ostream &out) const;
    void recDisplay(ostream &out, BTNode *cur, int dist) const;

    BTNode *search(int k) const;
    BTNode *searchRec(int k) const;
    BTNode *searchRec(int k, BTNode *r) const;

    string InOrder() const;
    void InOrder(BTNode *n, string &st) const;

    string BFS() const;
};


#endif //BSTN_B92_BSTN_H
