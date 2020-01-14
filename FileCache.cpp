//
// Created by orit on 14/01/2020.
//

#include "FileCache.h"
template <class Solution>
FileCache<Solution>::FileCache(int capacity) {
    this->className = Solution::class_name;
}

template <class Solution>
// update and write object in cache and file
void FileCache<Solution>::insert(string key, Solution obj) {
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

    string fileName = /*className + "_" +*/ items.front() + ".txt";
    fstream out_file(fileName, std::ios::out | std::ios::binary);
    if (!out_file) {
        throw "failed opening file";
    }
    //out_file.write( (char *) & obj, sizeof(obj));
    out_file.close();

}

template <class Solution>
// get the object if exist in files
Solution FileCache<Solution>::get(string key) {
    if (cache.find(key) == cache.end()) {
        string fileName = /*className + "_" + key +*/ ".txt";
        fstream in_file(fileName, ios::in | ios::binary);
        if(!in_file) {
            throw "an error - not found in cache";
        } else {
            Solution obj;
            in_file.read( (char *) & obj, sizeof(obj));
            in_file.close();
            //return obj;
        }
    }

    //move the object we used now to the front of the list
    items.remove(key);
    items.push_front(key);

    return cache.at(key).first;
}
