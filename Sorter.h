#pragma once
#include <iostream>
#include <functional>
#include <memory>
#include "Isorters.h"
#include "quick_sort.h"
#include "merge_sort.h"

template <typename T>
class Sorter {
    std::unique_ptr<Isorted<T>> sorter;
    std::function<bool(const T&, const T&)> comparator;

    static bool sravn(const T& a, const T& b) {
        return a < b;
    }
public:
    Sorter() : sorter(nullptr), comparator(sravn) {}

    enum class Sorts { MergeSort, QuickSort };

    void init(Sorts sort, std::function<bool(const T&, const T&)> F = nullptr) {
        comparator = F ? F : sravn;
        switch (sort) {
        case Sorts::MergeSort:
            sorter = std::make_unique<MergeSort<T>>();
            break;
        case Sorts::QuickSort:
            sorter = std::make_unique<QuickSort<T>>();
            break;
        }
    }

    void sort(DynamicArrSequence<T>& arr) {
        if (!sorter)
            init(Sorts::QuickSort);
        sorter->Sort(arr, comparator);
    }
};
