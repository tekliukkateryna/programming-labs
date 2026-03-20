#include <vector>
#include "Point.hpp"
using namespace std;

void selection(vector<Point> &arr, int st, int end) {
    for (int i = st; i<end; i++) {
        int min_ind = i;
        for (int j = i; j<=end; j++) {
            if (arr[j]<arr[min_ind]) {
                min_ind = j;
            }
        }
        swap(arr[i], arr[min_ind]);
    }
}

int quick(vector<Point> &arr, int st, int end) {
    int pivot_i = (st + end)/2;
    swap(arr[pivot_i], arr[end]);
    int i = st-1;
    for (int j = st; j<end; j++) {
        if (arr[j]<arr[end]) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    pivot_i=i+1;
    swap(arr[pivot_i], arr[end]);
    return pivot_i;
}

void combined_sort(vector<Point> &arr, int st, int end) {
    if (st >= end) return;
    if (end-st<7) {
        selection(arr, st, end);
    } else {
        int p = quick(arr, st, end);
        combined_sort(arr, st, p-1);
        combined_sort(arr, p+1, end);
    }
}