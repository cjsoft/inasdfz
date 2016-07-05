#include "oath.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MXM 300007

using namespace std;
struct node {
    node *fa;
    Data d;
} buf[MXM], *cur, *root;
int idcur;
node *locator[MXM];
node *newnode(Data d, node *parent) {
    if (parent == root) {
        cur->d = d;
        cur->fa = parent;
        return cur++;
    } else {
        cur->d = F(d, parent->d);
        cur->fa = parent;
        return cur++;
    }
}
void Init() {
    cur = buf + 1;
    root = buf;
    idcur = 1;
    locator[0] = root;
}
void Add_element(int id, Data x) {
    locator[idcur++] = newnode(x, locator[id]);
}
void Del_element(int id) {
    locator[idcur++] = locator[id]->fa;
}
Data Query_range(int id, int l, int r) {
    return locator[id]->d;
}