#include <chrono>
#include <iostream>
#include <vector>

#include "combined_sort.hpp"
#include "merge_sort.hpp"
#include "quick_sort.hpp"
#include "selection_sort.hpp"
#include "library_sort.hpp"

using namespace std;

void show_array(vector<Point> &arr) {
    for (int i = 0; i<arr.size(); i++) {
        show(arr[i]);
    }
    cout<<endl;
}

void demonstration_mode() {
    cout<<"DEMONSTRATION MODE"<<endl;

    int n;
    cout << "Enter array size: ";
    cin >> n;

    vector<Point> base (n);
    for (int i = 0; i<n; i++) {
        base[i]=random_point();
    }
    cout << "Initial array: "<<endl;
    show_array(base);

    vector<Point> a1 = base;
    cout << "Selection sort: "<<endl;
    selection_sort(a1);
    show_array(a1);

    vector<Point> a2 = base;
    cout << "Merge sort: "<<endl;
    merge_sort(a2);
    show_array(a2);

    vector<Point> a3 = base;
    cout << "Quick sort: "<<endl;
    quick_sort(a3, 0, a3.size() - 1);
    show_array(a3);

    vector<Point> a4 = base;
    cout << "Combined sort: "<<endl;
    combined_sort(a4, 0, a4.size() - 1);
    show_array(a4);

    vector<Point> a5 = base;
    cout << "Library sort: "<<endl;
    library_sort(a5);
    show_array(a5);

    cout<<endl;
}

void benchmark(vector<Point> &arr) {

    auto start = chrono::high_resolution_clock::now();
    selection_sort(arr);
    auto finish = chrono::high_resolution_clock::now();
    double t_selection = chrono::duration<double, std::nano>(finish - start).count();

    start = chrono::high_resolution_clock::now();
    quick_sort(arr, 0, arr.size()-1);
    finish = chrono::high_resolution_clock::now();
    double t_quick = chrono::duration<double, std::nano>(finish - start).count();

    start = chrono::high_resolution_clock::now();
    merge_sort(arr);
    finish = chrono::high_resolution_clock::now();
    double t_merge = chrono::duration<double, std::nano>(finish - start).count();

    start = chrono::high_resolution_clock::now();
    combined_sort(arr, 0, arr.size()-1);
    finish = chrono::high_resolution_clock::now();
    double t_combined = chrono::duration<double, std::nano>(finish - start).count();

    start = chrono::high_resolution_clock::now();
    library_sort(arr);
    finish = chrono::high_resolution_clock::now();
    double t_library = chrono::duration<double, std::nano>(finish - start).count();

    cout<<"selection_sort: "<<t_selection<<endl;
    cout<<"merge_sort    : "<<t_merge<<endl;
    cout<<"quick_sort    : "<<t_quick<<endl;
    cout<<"combined_sort : "<<t_combined<<endl;
    cout<<"library_sort  : "<<t_library<<endl;
}
void benchmark_mode() {
    cout<<"BENCHMARK MODE (ns)"<<endl;

    int n = 20;

    cout<<"Random array"<<endl;
    vector<Point> random_arr (n);
    for (int i = 0; i<n; i++) {
        random_arr[i]=random_point();
    }
    benchmark(random_arr);

    cout<<"Almost sorted array"<<endl;
    vector<Point> almost_sorted_arr = {
        {0, 0, 0},
        {1, 6, 3},
        {2, 7, 5},
        {3, 8, 6},
        {4, 9, 7},
        {5, 11, 8},
        {6, 12, 9},
        {8, 13, 10},
        {7, 14, 11},   //permutation
        {9, 15, 12},
        {10, 16, 13},
        {11, 17, 14},
        {12, 18, 15},
        {14, 19, 16},  //permutation
        {13, 20, 17},
        {15, 21, 18},
        {16, 22, 19},
        {17, 23, 20},
        {19, 24, 21},
        {18, 25, 22}};
    benchmark(almost_sorted_arr);

    cout<<"Almost reverse sorted array"<<endl;
    vector<Point> almost_reverse_arr = {
        {20, 30, 25},
        {19, 29, 24},
        {18, 28, 23},
        {17, 27, 22},
        {16, 26, 21},
        {15, 25, 20},
        {14, 24, 19},
        {13, 23, 18},
        {11, 21, 16},  //permutation
        {12, 22, 17},
        {10, 20, 15},
        {9, 19, 14},
        {8, 18, 13},
        {7, 17, 12},
        {6, 16, 11},
        {5, 15, 10},
        {3, 13, 8},    //permutation
        {4, 14, 9},
        {2, 12, 7},
        {1, 11, 6}
    };
    benchmark(almost_reverse_arr);

    cout<<endl;
}
int main() {

    demonstration_mode();

    benchmark_mode();

}