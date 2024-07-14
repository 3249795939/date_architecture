#include "QuickUnion.h"
#include <iostream>

QuickUnionSet* createQuickUnionSet(unsigned int size)
{
    QuickUnionSet* set = new QuickUnionSet;
    set->val = new int[size];
    set->parentID = new int[size];
    set->size = new unsigned int[size];
    set->n = size;

    return set;
}

void initQuickUnionSet(QuickUnionSet* set, const int* val, unsigned int n)
{
    for (int i = 0; i < n; i++) {
        set->val[i] = val[i];
        set->parentID[i] = i;
    }

    return;
}

void releaseQuickUnionSet(QuickUnionSet* set)
{
    delete[] set->parentID;
    set->parentID = nullptr;
    delete[] set->val;
    set->val = nullptr;
    delete[] set->size;
    set->size = nullptr;

    return;
}

static int getAncestID(QuickUnionSet* set, int a) {
    if (a != set->parentID[a]) {
        set->parentID[a] = getAncestID(set, set->parentID[a]);
    }
    return set->parentID[a];    //Â·¾¶Ñ¹Ëõ
}

bool isSameSet(QuickUnionSet* set, int a, int b)
{
    if (a >= set->n || b >= set->n) {
        return false;
    }
    int tempa = getAncestID(set, a), tempb = getAncestID(set, b);
    return tempa == tempb;
}

void unionQuickUnionSet(QuickUnionSet* set, int a, int b)
{
    int tempa = getAncestID(set, a), tempb = getAncestID(set, b);
    if (tempa == tempb) {
        return;
    } else {
        if (set->size[tempa] > set->size[tempb]) {
            set->parentID[tempb] = tempa;
            set->size[tempa] += set->size[tempb];
        }
        else {
            set->parentID[tempa] = tempb;
            set->size[tempb] += set->size[tempa];
        }
    }

    return;
}