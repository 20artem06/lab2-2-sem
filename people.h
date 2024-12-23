#pragma once
#include <iostream>
#include <string>

struct people {
    int age;
    float height;
    float weight;
    std::string name;
    std::string city;

    people() : age(0), height(0.0f), weight(0.0f), name("Oleg"), city("Unknown") {}
    people(int a, float h, float w, const std::string& n, const std::string& c)
        : age(a), height(h), weight(w), name(n), city(c) {}

    // Перегрузка операторов для сравнения
    bool isOlderThan(const people& p) const {
        return age > p.age;
    }

    bool isYoungerThan(const people& p) const {
        return age < p.age;
    }

    bool isHeavierThan(const people& p) const {
        return weight > p.weight;
    }

    bool isLighterThan(const people& p) const {
        return weight < p.weight;
    }

    bool isTallerThan(const people& p) const {
        return height > p.height;
    }

    bool isShorterThan(const people& p) const {
        return height < p.height;
    }

    friend std::ostream& operator<<(std::ostream& os, const people& p) {
        os << p.age << " " << p.height << " " << p.weight << " " << p.name << " " << p.city;
        return os;
    }
};
