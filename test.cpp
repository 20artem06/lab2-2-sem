#include <iostream>
#include <fstream>
#include <random>
#include "DynamicArrSequence.h"
#include "Sorter.h"
#include "test.h"
#include "people.h"
#include <string>
using namespace std;
void test_Sort_numbers(Sorter<double>& sorter) {
    try {
        srand(time(NULL));
        int size = 1e4;
        int diaposon = 200;
        DynamicArrSequence<double> arr(size);
        for (int i = 0; i < size; ++i) {
            arr.push_back(rand() % diaposon);
        }
        sorter.sort(arr);
        for (int i = 1; i < size; ++i) {
            if (arr[i - 1] > arr[i]) {
                cout << "test_Sort_numbers - error sort";
                break;
            }
        }
    }
    catch (std::exception& e) {
        cout << "test_Sort_numbers - error "<< endl;
        cout << e.what() << endl;
        return;
    }
    cout << "test_Sort_numbers - complete" << endl;
}


void test_Sort_people(Sorter<people>& sorter) {
    try {
        srand(time(NULL));
        int size = 1e4;
        int diaposon = 200;
        DynamicArrSequence<people> arr(size);
        for (int i = 0; i < size; ++i) {
            arr.push_back(rand() % diaposon);
        }
        sorter.sort(arr);
        for (int i = 1; i < size; ++i) {
            if (arr[i - 1] > arr[i]) {
                cout << "test_Merge_sort_people - error sort";
                break;
            }
        }
    }
    catch (std::exception& e) {
        cout << "test_Sort_people - error " << endl;
        cout << e.what() << endl;
        return;
    }
    cout << "test_Sort_people - complete" << endl;
}


void test_Sort_file_Numbers(Sorter<double>& sorter) {
    try {

        std::ifstream inputFile("input.txt");
        DynamicArrSequence<double> arr;
        double number;
        while (inputFile >> number) {
            arr.push_back(number);
        }
        inputFile.close();

        sorter.sort(arr);

        std::ofstream outputFile("output.txt");
        for (int i = 0; i < arr.get_colElm(); i++) {
            outputFile << arr[i] << " ";
        }
        outputFile.close();


        std::ifstream inputFile2("output.txt");
        DynamicArrSequence<double> arr2;
        double number2;
        while (inputFile2 >> number2) {
            arr2.push_back(number2);
        }

        for (int i = 1; i < arr2.get_colElm(); ++i) {
            if (arr2[i - 1] > arr2[i]) {
                cout << "\nerror sort";
                break;
            }
        }
        inputFile2.close();
    }
    catch (std::exception& e) {
        cout << "test_Sort_file_Numbers - error " << endl;
        cout << e.what() << endl;
        return;
    }
    cout << "test_Sort_file_Numbers - complete" << endl;
}



void test_Sort_file_People(Sorter<people>& sorter) {
    try {

        std::ifstream inputFile("inputPeople.txt");
        DynamicArrSequence<people> arr;
        int age;
        std::string name;
        while (inputFile >> age >> name) {
            arr.push_back(people(age, name));
        }
        inputFile.close();

        sorter.sort(arr);

        std::ofstream outputFile("outputPeople.txt");
        for (int i = 0; i < arr.get_colElm(); i++) {
            outputFile << arr[i] << " ";
        }
        outputFile.close();


        std::ifstream inputFile2("outputPeople.txt");
        DynamicArrSequence<people> arr2;
        int age2;
        std::string name2;
        while (inputFile >> age2 >> name2) {
            arr2.push_back(people(age2, name2));
        }
        for (int i = 1; i < arr2.get_colElm(); ++i) {
            if (arr2[i - 1] > arr2[i]) {
                cout << "\nerror sort";
                break;
            }
        }
        inputFile2.close();
    }
    catch (std::exception& e) {
        cout << "test_Sort_file_People - error " << endl;
        cout << e.what() << endl;
        return;
    }
    cout << "test_Sort_file_People - complete" << endl;
}
