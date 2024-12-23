#include <random>
#include <chrono>
#include <cstdlib>
#include <fstream>
#include <string>
#include <limits>
#include <vector>
#include <iostream>
#include "DynamicArrSequence.h"
#include "Sorter.h"
#include "test.h"
#include "people.h"

// Генерация случайного человека с использованием предварительно заданных массивов имен и городов
people generateRandomPerson() {
    static const std::vector<std::string> names = {"Alice", "Bob", "Charlie", "Diana", "Edward"};
    static const std::vector<std::string> cities = {"New York", "Los Angeles", "Chicago", "Houston", "Phoenix"};

    static std::default_random_engine generator;
    std::uniform_int_distribution<int> age_distribution(1, 100);
    std::uniform_real_distribution<float> height_distribution(1.5f, 2.0f); // от 1.5 до 2.0 метров
    std::uniform_real_distribution<float> weight_distribution(50.0f, 100.0f); // от 50.0 до 100.0 кг
    std::uniform_int_distribution<int> name_distribution(0, names.size() - 1);
    std::uniform_int_distribution<int> city_distribution(0, cities.size() - 1);

    return people(
        age_distribution(generator),
        height_distribution(generator),
        weight_distribution(generator),
        names[name_distribution(generator)],
        cities[city_distribution(generator)]
        );
}


void savePeopleToFile(const std::string& filename, const std::vector<people>& people) {
    std::ofstream outputFile(filename);
    for (const auto& person : people) {
        outputFile << person << std::endl;
    }
    outputFile.close();
}


std::vector<people> loadPeopleFromFile(const std::string& filename) {
    std::vector<people> people;
    std::ifstream inputFile(filename);
    int age;
    float height, weight;
    std::string name, city;
    while (inputFile >> age >> height >> weight >> name >> city) {
        people.emplace_back(age, height, weight, name, city);
    }
    inputFile.close();
    return people;
}

int main() {

    Sorter<double> doubleSorter;
    doubleSorter.init(Sorter<double>::Sorts::MergeSort);
    std::cout << " (MergeSort) ";   test_Sort_numbers(doubleSorter);
    std::cout << " (MergeSort) ";   test_Sort_file_Numbers(doubleSorter);

    doubleSorter.init(Sorter<double>::Sorts::QuickSort);
    std::cout << " (QuickSort) ";   test_Sort_numbers(doubleSorter);
    std::cout << " (QuickSort) ";   test_Sort_file_Numbers(doubleSorter);


    Sorter<people> peopleSorter;
    peopleSorter.init(Sorter<people>::Sorts::MergeSort);
    std::cout << " (MergeSort) ";   test_Sort_people(peopleSorter);

    peopleSorter.init(Sorter<people>::Sorts::QuickSort);
    std::cout << " (QuickSort) ";   test_Sort_people(peopleSorter);

    int choice;
    do {
        try {
            std::cout << "\nВведите '0' для выхода:\n";
            std::cout << "3) Для заполнения больших данных !!!\n";
            std::cout << "\nВыберите сортировку:\n";
            std::cout << "1) QuickSort\n";
            std::cout << "2) MergeSort\n";

            std::cin >> choice;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            switch (choice) {
            case 1: {
                std::cout << "\nВведите размер массива: ";
                int size;
                std::cin >> size;
                DynamicArrSequence<int> arr(size);
                std::cout << "\nВведите массив: " << std::endl;

                for (int i = 0; i < size; i++) {
                    int num;
                    std::cin >> num;
                    arr.push_back(num);
                }
                Sorter<int> sorter;
                sorter.init(Sorter<int>::Sorts::QuickSort);
                sorter.sort(arr);
                std::cout << "\nОтсортированный массив: ";
                for (int i = 0; i < arr.get_colElm(); i++) {
                    std::cout << arr[i] << " ";
                }
                std::cout << "\n";
                break;
            }
            case 2: {
                std::cout << "\nВведите размер массива: ";
                int size;
                std::cin >> size;
                DynamicArrSequence<int> arr(size);
                std::cout << "\nВведите массив: " << std::endl;

                for (int i = 0; i < size; i++) {
                    int num;
                    std::cin >> num;
                    arr.push_back(num);
                }
                Sorter<int> sorter;
                sorter.init(Sorter<int>::Sorts::MergeSort);
                sorter.sort(arr);
                std::cout << "\nОтсортированный массив: ";
                for (int i = 0; i < arr.get_colElm(); i++) {
                    std::cout << arr[i] << " ";
                }
                std::cout << "\n";
                break;
            }
            case 3: {
                std::cout << "Начинаю генерировать 50 миллионов записей...\n";
                auto start_time = std::chrono::high_resolution_clock::now(); // Запуск таймера

                std::vector<people> arr;
                for (int i = 0; i < 50000000; i++) { // 50 миллионов
                    arr.push_back(generateRandomPerson());
                }

                savePeopleToFile("inputPeople.txt", arr);

                auto end_time = std::chrono::high_resolution_clock::now(); // Остановка таймера
                std::chrono::duration<double> elapsed = end_time - start_time;

                std::cout << "Данные о людях сохранены в inputPeople.txt\n";
                std::cout << "Время генерации и записи: " << elapsed.count() << " секунд\n";
                break;
            }
            default:
                break;
            }
        } catch (std::exception& e) {
            std::cout << "\nОперация не удалась, попробуйте снова" << std::endl;
        }
    } while (choice != 0);


    auto peopleData = loadPeopleFromFile("inputPeople.txt");
    DynamicArrSequence<people> peopleArr(peopleData.size());
    for (const auto& person : peopleData) {
        peopleArr.push_back(person);
    }

    auto startSortTime = std::chrono::high_resolution_clock::now();
    peopleSorter.sort(peopleArr);
    auto endSortTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> sortElapsed = endSortTime - startSortTime;

    std::cout << "Сортировка завершена. Время сортировки: " << sortElapsed.count() << " секунд\n";

    return 0;
}
