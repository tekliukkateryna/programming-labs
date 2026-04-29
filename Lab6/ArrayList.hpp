#include <functional>
#include <iostream>
using namespace std;

template <typename T>
class ArrayList {
public:
    T* data = nullptr;
    int capacity = 0;
    int size = 0;

    void resize() {
        capacity = (capacity == 0) ? 10 : capacity * 2;
        T* new_data = new T[capacity];
        for (int i = 0; i<size; i++) {
            new_data[i]=data[i];
        }
        delete [] data;
        data = new_data;
        capacity*=2;
    }

    void create_empty() {
        delete[] data;
        capacity = 10;
        size = 0;
        data = new T[capacity];
    }

    void add (T a) {
        if (size == capacity) {
            resize();
        }

        int i = size;
        int st = 0;
        int end = size - 1;
        while (st<=end) {
            int mid = (st+end)/2;
            if(data[mid]>a) {
                i = mid;
                end = mid-1;
            } else {
                st = mid+1;
            }
        }

        for (int j = size; j>i; j--) {
            data[j]=data[j-1];
        }
        data[i]=a;
        size++;
    }

    void pop (T a) {
        if (size==0) {
            cout<<"Empty"<<endl;
            return;
        }
        int i = find(a);
        if (i==-1) return;
        for (i; i<size-1; i++) {
            data[i]=data[i+1];
        }
        size--;
    }

    int find (T a) {
        int st = 0;
        int end = size-1;
        while (st<=end) {
            int mid = (st+end)/2;
            if (data[mid]==a) {
                return mid;
            }
            if(data[mid]>a) {
                end = mid-1;
            } else {
                st = mid+1;
            }
        }
        cout<<"Not found"<<endl;
        return -1;
    }

    pair<int, int> range (T min, T max) {
        int min_ind = -1;
        int max_ind = -1;
        int st = 0;
        int end = size-1;
        while (st<=end) {
            int mid = (st+end)/2;
            if(data[mid]>=min) {
                min_ind = mid;
                end = mid-1;
            } else {
                st = mid+1;
            }
        }

        if (min_ind==-1 || data[min_ind]>max) return {-1, -1};

        st = min_ind;
        end = size - 1;
        while (st<=end) {
            int mid = (st+end)/2;
            if(data[mid]<=max) {
                max_ind = mid;
                st = mid+1;
            } else {
                end = mid-1;
            }
        }
        return {min_ind, max_ind};
    }

    void print() {
        if (size==0) {
            cout<<"Empty"<<endl;
            return;
        }
        for (int i = 0; i<size; i++) {
            cout<<data[i]<<" ";
        }
        cout<<endl;
    }

    void apply(function<void(T&)> op) {
        if (size==0) {
            cout<<"Empty"<<endl;
            return;
        }
        for (int i = 0; i<size; i++) {
            op(data[i]);
        }
    }
};