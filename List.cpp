#include "List.h"
#include <stdio.h>
#include "ListNode.h"

template <typename T>
ListNodePosi(T) ListNode<T>::insertAsPred(T const &e) {
    ListNodePosi(T) node = new ListNode<T>(e);
    node->succ = pred->succ;
    node->pred = pred;
    pred->succ = node;
    pred = node;
}

template <typename T>
ListNodePosi(T) ListNode<T>::insertAsSuss(T const &e) {
    ListNodePosi(T) node = new ListNode<T>(e);
    node->pred = succ->pred;
    node->succ = succ;
    succ->pred = node;
    succ = node;
}

template <typename T>
void List<T>::init() {
    _size = 0;
    header = new ListNode<T>;
    tailer = new ListNode<T>;
    header->pred = nullptr;
    header->succ = tailer;
    tailer->pred = header;
    tailer->succ = nullptr;
}

template <typename T>
int List<T>::clear() {
    ListNodePosi(T) p = header->succ;
    int cnt = 0;
    while (p != tailer) {
        p = p->succ;
        remove(p->pred);
        ++cnt;
        --_size;
    }
    return cnt;
}

template <typename T>
void List<T>::copyNodes(ListNodePosi(T) p, int n) {
    printf("-----copyNode-----\n");
    while (n--) {
        ListNodePosi(T) q = header->succ;
        q->insertAsPred(p->data);
        p = p->succ;
        _size++;
    }
}

template <typename T>
void List<T>::merge(ListNodePosi(T) & L1, int n1, List<T> &L,
                    ListNodePosi(T) L2, int n2) {}

template <typename T>
void List<T>::selectionSort(ListNodePosi(T) p, int n) {
    printf("-----selectionSort-----\n");
    ListNodePosi(T) last = p;
    for (int i = 0; i < n; i++) last = last->succ;
    // range of [p , last)
    // int unsortedLen = _size;
    while (n > 1) {
        ListNodePosi(T) maxNode = selextMax(p, --n);
        last->insertAsPred(maxNode->data);
        last = last->pred;
        remove(maxNode);
    }
}

// 下面这个写错了，这个是起泡排序
template <typename T>
void List<T>::insertionSort(ListNodePosi(T) p, int n) {
    ListNodePosi(T) header = p->pred;
    ListNodePosi(T) fir = header->succ;
    int unsortHeader = 0;
    while (n-- > 1) {
        unsortHeader = 0;
        fir = header->succ;
        while (unsortHeader++ <= n) {
            if (fir->data > (fir->succ)->data) {
                fir->insertAsPred(fir->succ);
                remove(fir->succ);
            }
            fir = fir->succ;
        }
    }
}