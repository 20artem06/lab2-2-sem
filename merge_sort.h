#pragma once
#include <iostream>
#include "DynamicArrSequence.h"
#include <functional>
#include "Isorters.h"


template <typename T>
class MergeSort :public Isorted<T> {
    void merge(MutableSequence<T>& arr, int start, int finish, std::function<bool(const T&,const T&)> F) {
        if (finish - start < 1) {
            return;
        }
        int mid = start + (finish - start) / 2;

        merge(arr, start, mid, F);
        merge(arr, mid + 1, finish, F);

        int first = start;
        int second = mid + 1;
        DynamicArrSequence<T> arr2(finish - start + 1);

        while (first <= mid and second <= finish) {

            if ( F( arr[second],arr[first] ) ) {
                arr2.push_back(arr[second]);
                second++;
            }
            else {
                arr2.push_back(arr[first]);
                first++;
            }
        }
        while (first <= mid) {
            arr2.push_back(arr[first]);
            first++;
        }
        while (second <= finish) {
            arr2.push_back(arr[second]);
            second++;
        }

        for (int i = 0; i < finish - start + 1; i++) {
            arr[start + i] = arr2[i];
        }
    }
public:
    void Sort(MutableSequence<T>& arr, std::function<bool(const T&, const T&)> F) override
    {
        merge(arr, 0, arr.get_colElm() - 1, F);
    }
};
