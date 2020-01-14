// Created by orit on 27/11/2019.
// 209162650

#ifndef UNTITLED2_EX2_H
#define UNTITLED2_EX2_H
#include <string>
#include <vector>
#include <functional>
#include <unordered_map>
#include <list>
#include <iterator>
#include <fstream>

using namespace std;

template <class P, class S>
class CacheManager {
public:
    virtual void insert(P key, S obj) = 0;
    virtual S get(P key) = 0;

};
#endif //UNTITLED2_EX2_H
