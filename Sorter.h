#pragma once
#include <iostream>
#include <functional>
#include "Isorters.h"
#include "quick_sort.h"
#include "merge_sort.h"



template <typename T>
class Sorter {
    std::unique_ptr<Isorted<T>> sorter;
    std::function<bool(const T&, const T&)> comporator;
    static bool sravn(const T& a, const T& b) {
        return a < b;
    };
public:
    Sorter() : sorter(nullptr), comporator() {}
    enum class sorts { MergeSort, QuickSort };
    void init(sorts sort, std::function<bool(const T&, const T&)> F) {
        comporator = F;
        if (sort == sorts::MergeSort) {
            sorter = std::unique_ptr<Isorted<T>>(new MergeSort<T>);
        }
        if (sort == sorts::QuickSort) {
            sorter = std::unique_ptr<Isorted<T>>(new QuickSort<T>);
        }
    }
    void init(sorts sort) {
        if (sort == sorts::MergeSort) {
            sorter = std::unique_ptr<Isorted<T>>(new MergeSort<T>);
        }
        if (sort == sorts::QuickSort) {
            sorter = std::unique_ptr<Isorted<T>>(new QuickSort<T>);
        }
    }

    void sort(DynamicArrSequence<T>& arr) {
        if (!sorter)  sorter = std::unique_ptr<Isorted<T>>(new QuickSort<T>);
        if (!comporator) comporator = &sravn;
        sorter->Sort(arr, comporator);
    }
};
