#pragma once
#include <random>
using namespace std;
struct Point {
    double x, y, z;

    bool operator<(const Point& other) const {
        if (x != other.x) return x < other.x;
        if (y != other.y) return y < other.y;
        return z < other.z;
    }
    bool operator>(const Point& other) const {
        return other < *this;
    }
    bool operator<=(const Point& other) const {
        return !(*this > other);
    }
    bool operator>=(const Point& other) const {
        return !(*this < other);
    }
};

void show(Point p) {
    cout<<"("<<p.x<<", "<<p.y<<", "<<p.z<<")"<<" ";
}

void swap(Point &a, Point &b) {
    int temp = a.x;
    a.x=b.x;
    b.x = temp;

    temp = a.y;
    a.y = b.y;
    b.y = temp;

    temp = a.z;
    a.z = b.z;
    b.z = temp;
}

Point random_point() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static uniform_real_distribution<double> dist(-1000.0, 1000.0);

    Point p;
    p.x = dist(gen);
    p.y = dist(gen);
    p.z = dist(gen);

    return p;
}