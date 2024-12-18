#pragma once
#include <iostream>
#include <fstream>
#include <string>
struct people {
    int age;
    std::string name;
    people() : age(0), name("Oleg") {}
    people(int a) : age(a), name("Oleg") {}
    people(int a, const std::string n) : age(a), name(n){}
    bool operator<( const people& p) const {
        return age < p.age;
    }
    bool operator>(const people& p) {
        return age > p.age;
    }
    friend std::ostream& operator<<(std::ostream& os, const people& p) {
        os << p.age << " " << p.name;
        return os;
    }
};
