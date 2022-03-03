#ifndef LISTNODE_H
#define LISTNODE_H

typedef int Rank;
#define ListNodePosi(T) ListNode<T> *

template <typename T>
struct ListNode
{
    // member variable
    T data;
    ListNodePosi(T) pred;
    ListNodePosi(T) succ;
    // member function
    ListNode() {}
    ListNode(T e, ListNodePosi(T) p = NULL, ListNodePosi(T) s = NULL)
        : data(e), pred(p), succ(s) {}

    ListNodePosi(T) insertAsPred(T const &e);
    ListNodePosi(T) insertAsSuss(T const &e);
};

#endif