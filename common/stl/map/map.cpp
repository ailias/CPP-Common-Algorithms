//
// Created by Ailias on 2017/3/8.
//
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * get key sets of given map while not change their sequence.
 * the key set is ordered
 * @param origMap
 * @return vector array
 */

template<typename K, typename V>
vector<K> getMapKeySet(map<K, V> origMap) {
    vector<K> resultArr; //the map keys set result
    //need typename keyword because the ite is dependent scope
    using MapIterator = typename map<K, V>::iterator;
    for (MapIterator ite = origMap.begin(); ite != origMap.end(); ite++) {
        //for iterator, ite->first = key, ite->second = value.
        resultArr.push_back(ite->first);
    }
    return resultArr;
}

/**
 * get value sets of given map while not change their sequence.
 * @param origMap
 * @return vector array
 */
template<typename K, typename V>
vector<V> getMapValueSet(map<K, V> origMap) {
    vector<V> resultArr; //the map values set result
    //need typename keyword because the ite is dependent scope
    using MapIterator = typename map<K, V>::iterator;
    for (MapIterator ite = origMap.begin(); ite != origMap.end(); ite++) {
        //for iterator, ite->first = key, ite->second = value.
        resultArr.push_back(ite->second);
    }
    return resultArr;
}


/**
 * sort the map by value and return a new <V, K> map object
 * @param origMap
 * @return map:
 */
template<typename K, typename V>
map<V, K> sortMapByValue(map<K, V> origMap) {
    map<V, K> resultMap;
    using MapIterator = typename map<K, V>::iterator;
    for (MapIterator ite = origMap.begin(); ite != origMap.end(); ite++) {
        //for iterator, ite->first = key, ite->second = value.
        resultMap.insert(pair<V, K>(ite->second, ite->first));
    }
    return resultMap;
};


/**
 * get key sets of given unordered_map while not change their sequence.
 * the key set is not ordered. their sequence is FILO, first in, last out.
 * which is similar to stack.
 * @param origMap
 * @return vector array
 */
template<typename K, typename V>
vector<K> getUnorderedMapKeySet(unordered_map<K, V> origMap) {
    vector<K> resultArr; //the map keys set result
    //need typename keyword because the ite is dependent scope
    using MapIterator = typename unordered_map<K, V>::iterator;
    for (MapIterator ite = origMap.begin(); ite != origMap.end(); ite++) {
        //for iterator, ite->first = key, ite->second = value.
        resultArr.push_back(ite->first);
    }
    return resultArr;
}

/**
 * get value sets of given unordered_map while not change their sequence.
 * @param origMap
 * @return vector array
 */
template<typename K, typename V>
vector<V> getUnorderedMapValueSet(unordered_map<K, V> origMap) {
    vector<V> resultArr; //the map values set result
    //need typename keyword because the ite is dependent scope
    using MapIterator = typename unordered_map<K, V>::iterator;
    for (MapIterator ite = origMap.begin(); ite != origMap.end(); ite++) {
        //for iterator, ite->first = key, ite->second = value.
        resultArr.push_back(ite->second);
    }
    return resultArr;
}

/**
 * sort the unordered_map by value and return a new <V, K> map object
 * @param origMap
 * @return map:
 */
template<typename K, typename V>
map<V, K> sortUnorderedMapByValue(unordered_map<K, V> origMap) {
    map<V, K> resultMap; // sort the <v,k> pair
    using unorderedMapIterator = typename unordered_map<K, V>::iterator;
    //sort
    for (unorderedMapIterator ite = origMap.begin(); ite != origMap.end(); ite++) {
        //for iterator, ite->first = key, ite->second = value.
        resultMap.insert(pair<V, K>(ite->second, ite->first));
    }
    return resultMap;
};