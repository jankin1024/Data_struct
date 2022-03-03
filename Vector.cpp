#include "Vector.h"

template <typename T>
void Vector<T>::copyfrom(T const* A, Rank lo, Rank hi) {
    _size = 0;
    _elem = new T[_capacity = 2 * (hi - lo)];
    for (int i = lo; i < hi; ++i) {
        _elem[i] = A[i];
        _size++;
    }
}

template <typename T>
void Vector<T>::expand() {
    if (_capacity < _size * 2) _capacity *= 2;
}

template <typename T>
void Vector<T>::shrink() {
    if (_capacity > _size * 2) _capacity /= 2;
}

template <typename T>
bool Vector<T>::bubbleSort(Rank lo, Rank hi) {
    if (lo < 0 && hi > _capacity) return -1;
    for (int i = hi - 1; i > lo; i--) {
        for (int j = lo; j < i; j++) {
            if (_elem[j] > _elem[j + 1]) {
                _elem[j] ^= _elem[j + 1];
                _elem[j + 1] ^= _elem[j];
                _elem[j] ^= _elem[j + 1];
            }
        }
    }
    return 1;
}

template <typename T>
Rank Vector<T>::max(Rank lo, Rank hi) {
    int maxRank = lo;
    T maxv = _elem[lo];
    for (int i = lo; i < hi; i++) {
        if (_elem[i] > maxv) {
            maxv = _elem[i];
            maxRank = i;
        }
    }
    return maxRank;
}

template <typename T>
void Vector<T>::merge(Rank lo, Rank hi) {}

template <typename T>
void Vector<T>::mergeSort(Rank lo, Rank hi) {}

template <typename T>
Rank Vector<T>::partition(Rank lo, Rank hi) {}

template <typename T>
void Vector<T>::quickSort(Rank lo, Rank hi) {}

template <typename T>
void Vector<T>::heapSort(Rank lo, Rank hi) {}

template <typename T>
void Vector<T>::traverse1() {}

template <typename T>
int Vector<T>::disorder() const {
    // int disordered = 0;
    int in = 0;
    int de = 1;
    for (int i = 0; i < _size; i++) {
        if (_elem[i] > _elem[i + 1]) {
            // disordered = 1;
            in = -1;
        } else if (_elem[i] < _elem[i + 1]) {
            de = -1;
        }
    }
    if (in == -1 && de == -1) return -1;
    if (in == 0) return 0;
    return 1;
}

template <typename T>
Rank Vector<T>::find(T const& e, Rank lo, Rank hi) const {
    while (lo < hi-- && _elem[hi] != e)
        ;  // find the last element
    // int pos;
    // for (pos = lo; pos < hi; pos++) {
    //     if (_elem[pos] == e) break;
    // }
    // return pos;
    return hi;
}

template <typename T>
Rank Vector<T>::search(T const& e, Rank lo, Rank hi) const {
    int mid;
    while (lo < hi - 1) {
        mid = (lo + hi) >> 1;
        if (_elem[mid] <= e)
            hi = mid;
        else
            lo = mid;
    }
    return _elem[lo] == e ? lo : -1;
}

template <typename T>
T& Vector<T>::operator[](Rank r) const {
    return _elem[r];
}

template <typename T>
Vector<T>& Vector<T>::operator=(Vector<T> const& vec) {
    delete[] _elem;
    copyfrom(vec._elem, 0, vec.size());
    return *this;
}

template <typename T>
T Vector<T>::remove(Rank r) {
    int temp = _elem[r];
    if (r >= 0 && r < _size) {
        _size--;
        while (r < _size) {
            _elem[r] = _elem[r + 1];
        }
    }
    return temp;
}

template <typename T>
int Vector<T>::remove(Rank lo, Rank hi) {
    int t = hi - lo;
    while (hi < _size) {
        _elem[lo++] = _elem[hi++];
    }
    _size -= t;
    return t;
}

template <typename T>
Rank Vector<T>::insert(Rank r, T const& e) {
    expand();
    int pos = _size;
    while (pos > r) {
        _elem[pos] = _elem[pos - 1];
    }
    _size++;
    _elem[r] = e;
    return r;
}
