//
// Created by orit on 14/01/2020.
//

#ifndef EX4_FILECACHEMANAGER_H
#define EX4_FILECACHEMANAGER_H
#include <string>
#include <vector>
#include <functional>
#include <unordered_map>
#include <list>
#include <iterator>
#include <fstream>
#include "CacheManager.h"
#define CAPACITY_SIZE 5
using namespace std;

template <class P, class S>

class FileCacheManager: public CacheManager<P,S> {
private:
    unordered_map<P,pair<S,list<string>::iterator>> cache;
    list<string> items;
    unsigned int myCapacity = CAPACITY_SIZE;
public:
    void insert(P key, S obj) {
        if (items.size() == myCapacity) {
            string eraseKey = items.back();
            items.remove(items.back());
            cache.erase(eraseKey);
        }

        if (cache.find(key) != cache.end()) {
            items.remove(key);
            cache.erase(key);
        }
        items.push_front(key);
        list<string>::iterator it = items.begin();
        cache[key] = {obj, it};

        string fileName = items.front() + ".txt";
        fstream out_file(fileName, std::ios::out | std::ios::binary);
        if (!out_file) {
            throw "failed opening file";
        }
        out_file.write( (char *) & obj, sizeof(obj));
        out_file.close();

    }
    S get(P key) {
        if (cache.find(key) == cache.end()) {
            string fileName = key + ".txt";
            fstream in_file(fileName, ios::in | ios::binary);
            if(!in_file) {
                return "";
            } else {
                S obj;
                in_file.read( (char *) & obj, sizeof(obj));
                in_file.close();
            }
        }

        //move the object we used now to the front of the list
        items.remove(key);
        items.push_front(key);

        return cache.at(key).first;
    }
};

#endif //EX4_FILECACHEMANAGER_H
