#include <bits/stdc++.h>
using namespace std;

//-------------------------- Strategy Interface --------------------------
class SortingStrategy {
public:
    virtual void sort(vector<int>& A) const = 0;
    virtual ~SortingStrategy() = default;
};
//-------------------------- Bubble Sort --------------------------
class BubbleSortStrategy : public SortingStrategy {
public:
    void sort(vector<int>& A) const override {
        int n = A.size();
        for (int i = 0; i < n - 1; ++i) {
            bool swapped = false;
            for (int j = 0; j < n - i - 1; ++j) {
                if (A[j] > A[j + 1]) {
                    swap(A[j], A[j + 1]);
                    swapped = true;
                }
            }
            if (!swapped) break;
        }
    }
};
//-------------------------- Insertion Sort --------------------------
class InsertionSortStrategy : public SortingStrategy {
public:
    void sort(vector<int>& A) const override {
        int n = A.size();
        for (int j = 1; j < n; ++j) {
            int key = A[j];
            int i = j - 1;
            while (i >= 0 && A[i] > key) {
                A[i + 1] = A[i];
                i = i - 1;
            }
            A[i + 1] = key;
        }
    }
};
//-------------------------- Selection Sort --------------------------
class SelectionSortStrategy : public SortingStrategy {
public:
    void sort(vector<int>& A) const override {
        int n = A.size();
        for (int i = 0; i < n - 1; ++i) {
            int min_idx = i;
            for (int j = i + 1; j < n; ++j) {
                if (A[j] < A[min_idx]) {
                    min_idx = j;
                }
            }
            if (min_idx != i) {
                swap(A[i], A[min_idx]);
            }
        }
    }
};
//-------------------------- Merge Sort --------------------------
class MergeSortStrategy : public SortingStrategy {
    void merge(vector<int>& A, int l, int mid, int r) const {
        int n1 = mid - l + 1;
        int n2 = r - mid;

        vector<int> L(n1 + 1);
        vector<int> R(n2 + 1);

        for (int i = 0; i < n1; ++i)
            L[i] = A[l + i];
        for (int j = 0; j < n2; ++j)
            R[j] = A[mid + 1 + j];

        L[n1] = INT_MAX;  // Sentinel
        R[n2] = INT_MAX;

        int i = 0, j = 0;
        for (int k = l; k <= r; ++k) {
            if (L[i] <= R[j]) {
                A[k] = L[i];
                ++i;
            } else {
                A[k] = R[j];
                ++j;
            }
        }
    }

    void merge_sort(vector<int>& A, int l, int r) const {
        if (l < r) {
            int mid = (l + r) / 2;
            merge_sort(A, l, mid);
            merge_sort(A, mid + 1, r);
            merge(A, l, mid, r);
        }
    }

public:
    void sort(vector<int>& A) const override {
        merge_sort(A, 0, A.size() - 1);
    }
};

//-------------------------- Quick Sort --------------------------
class QuickSortStrategy : public SortingStrategy {
    int partition(vector<int>& A, int l, int r) const {
        int x = A[r];
        int i = l - 1;
        for (int j = l; j < r; ++j) {
            if (A[j] <= x) {
                ++i;
                swap(A[i], A[j]);
            }
        }
        swap(A[i + 1], A[r]);
        return i + 1;
    }
    void quick_sort(vector<int>& A, int l, int r) const {
        if (l < r) {
            int mid = partition(A, l, r);
            quick_sort(A, l, mid - 1);
            quick_sort(A, mid + 1, r);
        }
    }

public:
    void sort(vector<int>& A) const override {
        quick_sort(A, 0, A.size() - 1);
    }
};

//-------------------------- Context Class --------------------------
class Sorter {
private:
    const SortingStrategy* strategy;
public:
    void setStrategy(const SortingStrategy* s) {
        strategy = s;
    }
    void sort(vector<int>& A) const {
        if (strategy) {
            strategy->sort(A);
        }
    }
};

//-------------------------- Helper Function --------------------------
void printArray(const vector<int>& A) {
    for (int x : A)
        cout << x << " ";
    cout << "\n";
}

//-------------------------- Main --------------------------
int main() {
    vector<int> A = {31, 41, 59, 26, 41, 58};

    BubbleSortStrategy bubble;
    InsertionSortStrategy insertion;
    SelectionSortStrategy selection;
    MergeSortStrategy merge;
    QuickSortStrategy quick;

    Sorter sorter;

    vector<int> B;

    cout << "Original: ";
    printArray(A);

    B = A;
    sorter.setStrategy(&bubble);
    sorter.sort(B);
    cout << "Bubble Sort: ";
    printArray(B);

    B = A;
    sorter.setStrategy(&insertion);
    sorter.sort(B);
    cout << "Insertion Sort: ";
    printArray(B);

    B = A;
    sorter.setStrategy(&selection);
    sorter.sort(B);
    cout << "Selection Sort: ";
    printArray(B);

    B = A;
    sorter.setStrategy(&merge);
    sorter.sort(B);
    cout << "Merge Sort: ";
    printArray(B);

    B = A;
    sorter.setStrategy(&quick);
    sorter.sort(B);
    cout << "Quick Sort: ";
    printArray(B);

    return 0;
}
