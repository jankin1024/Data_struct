// #include "ListNode.h"

// template <typename T>
// ListNodePosi(T) ListNode<T>::insertAsPred(T const &e)
// {
//     ListNodePosi(T) node = new ListNode<T>(e);
//     node->succ = pred->succ;
//     node->pred = pred;
//     pred->succ = node;
//     pred = node;
// }

// template <typename T>
// ListNodePosi(T) ListNode<T>::insertAsSuss(T const &e)
// {
//     ListNodePosi(T) node = new ListNode<T>(e);
//     node->pred = succ->pred;
//     node->succ = succ;
//     succ->pred = node;
//     succ = node;
// }