#include <random>
#include <chrono>
#include <cstdlib>
#include <fstream>
#include <string>
#include "DynamicArrSequence.h"
#include "Sorter.h"
#include "test.h"
#include "people.h"
#include <limits>


int main() {

    Sorter<double> DoubleSorter;
    DoubleSorter.init(Sorter<double>::sorts::MergeSort);
    std::cout << " (MergeSort) ";   test_Sort_numbers(DoubleSorter);
    std::cout << " (MergeSort) ";   test_Sort_file_Numbers(DoubleSorter);
    DoubleSorter.init(Sorter<double>::sorts::QuickSort);
    std::cout << " (QuickSort) ";   test_Sort_numbers(DoubleSorter);
    std::cout << " (QuickSort) ";   test_Sort_file_Numbers(DoubleSorter);

    Sorter<people> PeopleSorter;
    PeopleSorter.init(Sorter<people>::sorts::MergeSort);
    std::cout << " (MergeSort) ";   test_Sort_people(PeopleSorter);
    //std::cout << " (MergeSort) ";   test_Sort_file_People(PeopleSorter);
    PeopleSorter.init(Sorter<people>::sorts::QuickSort);\
        std::cout << " (QuickSort) ";   test_Sort_people(PeopleSorter);
    //std::cout << " (QuickSort) ";   test_Sort_file_People(PeopleSorter);



    int choise;
    do
    {
        try {

            std::cout << "\nwrite '0' for stop program:\n";
            std::cout << "3) For filling big data !!!\n";
            std::cout << "\nselect a sort:\n";
            std::cout << "1) QuikSort\n";
            std::cout << "2) MergeSort\n";

            std::cin >> choise;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            switch (choise)
            {
            case 1:
            {
                std::cout << "\nwrite size arr" << std::endl;
                int size, num;
                std::cin >> size;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                Sorter<int> sorter;
                DynamicArrSequence<int> arr(size);
                std::cout << "\nwrite arr: " << std::endl;
                for (int i = 0; i< size ;i++){
                    std::cin >> num;
                    arr.push_back(num);
                }
                sorter.sort(arr);
                std::cout << "\nsorted arr: ";
                for (int i = 0; i < arr.get_colElm(); i++) {
                    std::cout << arr[i] <<" ";
                }
                std::cout << "\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            }
            case 2:
            {

                std::cout << "\nwrite size arr" << std::endl;
                int size, num;
                std::cin >> size;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                Sorter<int> sorter;
                sorter.init(Sorter<int>::sorts::MergeSort);
                std::cout << "\nwrite arr: " << std::endl;
                DynamicArrSequence<int> arr(size);
                for (int i = 0; i < size; i++) {
                    std::cin >> num;
                    arr.push_back(num);
                }
                sorter.sort(arr);
                std::cout << "\nsorted arr: ";
                for (int i = 0; i < arr.get_colElm(); i++) {
                    std::cout << arr[i] << " ";
                }
                std::cout << "\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            }
            case 3:
            {
                DynamicArrSequence<people> arr;
                srand(time(NULL));
                for (int i = 0; i < 5e7; i++) {
                    int age;
                    std::string name;
                    age = rand()%100;
                    for (int q = 0; q < 20; q++) {
                        char c = rand() % 20  + 100;
                        name.push_back(c);
                    }
                    arr.push_back(people(age, name));
                }
                std::ofstream outputFile("inputPeople.txt");
                for (int i = 0; i < arr.get_colElm(); i++) {
                    outputFile << arr[i] << " ";
                }
                outputFile.close();
                break;
            }
            default:
                break;
            }
        }
        catch (std::exception& e) {
            std::cout << "\nthe operation failed, try again" << std::endl;
        }
    } while (choise);
    return 0;
}
