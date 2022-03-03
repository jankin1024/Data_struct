#ifndef VECTOR_H
#define VECTOR_H
// Vector template
typedef int Rank;  // rank of vector
#define DEFAULT_CAPACITY 4

template <typename T>
class Vector {
   protected:
    Rank _size;
    int _capacity;
    T *_elem;

    void copyfrom(T const *A, Rank lo, Rank hi);  // copy Vector A from lo to hi
    void expand();                                // expand capacity
    void shrink();                                // shrink capacity
    bool bubbleSort(Rank lo, Rank hi);
    Rank max(Rank lo, Rank hi);  // select the max element
    void selectionSort(Rank lo, Rank hi);
    void merge(Rank lo, Rank hi);
    void mergeSort(Rank lo, Rank hi);
    Rank partition(Rank lo, Rank hi);
    void quickSort(Rank lo, Rank hi);
    void heapSort(Rank lo, Rank hi);

   public:
    Vector(int c = DEFAULT_CAPACITY, int s = 0, T v = 0) {
        _elem = new T[_capacity = c];
        for (int _size = 0; _size < s; _elem[_size++] = v)
            ;
    }
    Vector(T const *A, Rank lo, Rank hi) { copyfrom(A, lo, hi); }
    Vector(T const *A, Rank n) { copyfrom(A, 0, n); }
    Vector(Vector<T> const &V, Rank lo, Rank hi) { compyfrom(V._elem, lo, hi); }
    Vector(Vector<T> const &V) { copyfrom(V._elem, 0, V._size); }

    ~Vector() { delete[] _elem; }  // 析构函数

    Rank size() const { return _size; }
    bool empty() const { return !_size; }
    int disorder() const;  // unsorted -1, increase 0, decrease 1
    Rank find(T const &e) const { return find(e, 0, (Rank)_size); }
    // find in a general vector, return the last number
    Rank find(T const &e, Rank lo, Rank hi) const;
    Rank search(T const &e) const {
        // find in a sorted vector
        return (0 > _size) ? -1 : search(e, 0, (Rank)_size);
    }
    Rank search(T const &e, Rank lo, Rank hi) const;

    T &operator[](Rank r) const;  // reload [], visit element by rank
    Vector<T> &operator=(Vector<T> const &);  // reload = to copy vector
    T remove(Rank r);                         // delete rank r element
    int remove(Rank lo, Rank hi);
    Rank insert(Rank r, T const &e);
    Rank insert(T const &e) { return insert(_size, e); }
    void sort(Rank lo, Rank hi);  // sorted vector from lo to hi
    void sort() { sort(0, _size); }
    void unsort(Rank lo, Rank hi);  // unsort the vector
    void unsort() { unsort(0, _size); }
    void dedeuplicate();  // 无序去重
    void uniquify();      // 有序去重

    void traverse(void (*)(T &));
    void traverse1();
    template <typename VST>
    void traverse(VST &);
};

#endif