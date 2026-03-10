#include <vector>
#include "Point.hpp"

void merge(vector<Point> &arr, int st, int mid, int end) {
    int left_num = mid-st+1;
    vector<Point> left (left_num);
    int right_num = end-mid;
    vector<Point> right (right_num);

    for (int i = 0; i<left_num; i++) {
        left[i]=arr[st+i];
    }
    for (int i = 0; i<right_num; i++) {
        right[i]=arr[mid+1+i];
    }

    int i=0, j=0, k=st;
    while (i<left_num && j<right_num) {
        if (left[i]<=right[j]) {
            arr[k++]=left[i++];
        } else {
            arr[k++]=right[j++];
        }
    }
    while (i<left_num) {
        arr[k++]=left[i++];
    }
    while (j<right_num) {
        arr[k++]=right[j++];
    }
}

//Classic way
/*void merge_sort(vector<Point> &arr, int st, int end) {
    if (st>=end) return;
    int mid = (st+end)/2;
    merge_sort(arr, st, mid);
    merge_sort(arr, mid+1, end);
    merge(arr, st, mid, end);
}*/

//First try of bottom-up, but it looks scary
/*void merge_sort(vector<Point> &arr) {
    int len = arr.size();
    int i = 0;
    int rem_i = len-1;
    for (int step = 2; step<len; step*=2) {
        for (i = 0; i<len-step/2; i=i+step) {
            merge(arr, i, i+step/2-1, i+step-1);
        }

        if (i<len-1 && rem_i<len) {
            merge(arr, i, rem_i, len-1);
        }
        rem_i = i;
    }
    if (i<len) {
        merge(arr, 0, rem_i-1, len-1);
    }
}*/

//Final
void merge_sort(vector<Point> &arr) {
    int len = arr.size();
    for (int step = 1; step<len; step*=2 ){
        for (int i = 0; i<len-step; i=i+2*step) {
            merge(arr, i, min(i+step-1, len-1), min(i+2*step-1,len-1));
        }
    }
}