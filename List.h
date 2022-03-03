#ifndef LIST_H
#define LIST_H

#include "ListNode.cpp"
#include "ListNode.h"

template <typename T>
class List {
   private:
    int _size;
    ListNodePosi(T) header;
    ListNodePosi(T) tailer;

   protected:
    void init();                           // initial after create
    int clear();                           // clear all nodes
    void copyNodes(ListNodePosi(T), int);  // copy n nodes from p
    void merge(ListNodePosi(T) &, int, List<T> &, ListNodePosi(T),
               int);  // merge two sorted lists
    void mergeSort(ListNodePosi(T) &, int);
    void selectionSort(ListNodePosi(T), int);
    void insertionSort(ListNodePosi(T), int);

   public:
    List() { init(); }
    List(List<T> const &L);
    List(List<T> const &L, Rank r, Rank n);
    List(ListNodePosi(T) p, int n);
    ~List();

    Rank size() const { return _size; }
    bool empty() const { return _size <= 0; }
    T &operator[](int r) const;
    ListNodePosi(T) first() const { return header->succ; }
    ListNodePosi(T) last() const { return tailer->pred; }
    bool valid(ListNodePosi(T) p) {
        return p && (header != p) && (tailer != p);
    }
    int disordered() const;
    ListNodePosi(T) find(T const &e) const { find(e, _size, tailer); }
    ListNodePosi(T)
        find(T const &e, int n,
             ListNodePosi(T) p);  // find e in range n before p from p
    ListNodePosi(T) search(T const &e) const { search(e, _size, tailer); }
    ListNodePosi(T) search(T const &e, int n, ListNodePosi(T) p);
    ListNodePosi(T)
        selextMax(ListNodePosi(T) p, int n);  // select max node from p to p+n
    ListNodePosi(T) selextMax() { return selextMax(header->succ, _size); }

    ListNodePosi(T) insertAsFirst(T const &e);
    ListNodePosi(T) insertAsLast(T const &e);
    ListNodePosi(T) insertBefore(ListNodePosi(T) p, T const &e);
    ListNodePosi(T) insertAfter(ListNodePosi(T) p, T const &e);
    T remove(ListNodePosi(T) p);
    void merge(List<T> &L) {
        merge(first(), _size, L, L.fisrt(), L.size());
    }                                     // merge the whole list L
    void sort(ListNodePosi(T) p, int n);  // sort the part of list
    void sort() { sort(first(), _size); }
    int deduplicate();  // deduplicate a unordered list
    int uniquify();     // uniquify an ordered list
    void reverse();     // reverse the list

    void traverse(void (*)(T &));
    template <typename VST>  // operator
    void traverse(VST &);
};

#endif