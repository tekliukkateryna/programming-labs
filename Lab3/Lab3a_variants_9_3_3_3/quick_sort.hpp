#include <vector>
#include "Point.hpp"
using namespace std;

void quick_sort(vector<Point> &arr, int st, int end) {
    if (st>=end) return;
    int pivot_i = st + rand() % (end-st+1);
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
    quick_sort(arr, st, pivot_i-1);
    quick_sort(arr, pivot_i+1, end);
}