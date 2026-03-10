#include <vector>
#include "Point.hpp"
using namespace std;

void selection_sort(vector<Point> &arr) {
    int n = arr.size();

    for (int i = 0; i<n; i++) {
        int min_ind = i;
        for (int j = i; j<n; j++) {
            if (arr[j]<arr[min_ind]) {
                min_ind = j;
            }
        }
        swap(arr[i], arr[min_ind]);
    }

}