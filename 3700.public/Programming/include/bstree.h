//
// Created by bob on 11/15/19.
//

#pragma once

#include <cstdint>
#include "iostream"

template <typename TreeType>
struct TreeNode {
    TreeType
        datum;
    int32_t
        count,
        height;
    TreeNode<TreeType>
        *left,*right;
};

template <class TreeType>
class SortedLinearList {
public:
    SortedLinearList() { root = nullptr; }
    ~SortedLinearList() { prvClear(root); }

    void clear() { prvClear(root); root = nullptr; }
    bool isEmpty() { return root == nullptr; }
    int32_t size();
    int32_t height();

    int32_t search(TreeType);
    TreeType &operator[](int32_t);
    void traverse(void (*fp)(TreeType &)) { prvTraverse(root,fp); }
    void insert(TreeType);
    void remove(TreeType);
private:
    void prvClear(TreeNode<TreeType> *);
    void prvTraverse(TreeNode<TreeType> *,void (*)(TreeType &));
    TreeNode<TreeType> *prvInsert(TreeNode<TreeType> *,TreeNode<TreeType> *);
    TreeNode<TreeType> *prvRemove(TreeNode<TreeType> *,const TreeType &);
    void prvAdjust(TreeNode<TreeType> *);

    TreeNode<TreeType>
        *root,
        *ntbd;
};

#include "bstree-implementation.h"
