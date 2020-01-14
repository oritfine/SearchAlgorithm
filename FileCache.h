//
// Created by orit on 14/01/2020.
//

#ifndef EX4_FILECACHE_H
#define EX4_FILECACHE_H
#include <string>
#include <vector>
#include <functional>
#include <unordered_map>
#include <list>
#include <iterator>
#include <fstream>
#include "CacheManager.h"

using namespace std;

template <class Solution>

class FileCache: public CacheManager<Solution> {
    unordered_map<string,pair<Solution,list<string>::iterator>> cache;
    list<string> items;
    const unsigned int myCapacity;
public:
    FileCache(int capacity);
    void insert(string key, Solution obj);
    Solution get(string key);
};

#endif //EX4_FILECACHE_H
