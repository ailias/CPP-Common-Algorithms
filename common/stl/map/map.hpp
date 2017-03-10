//
// Created by Ailias on 2017/3/8.
//
#include <map>
#include <unordered_map>
#include <vector>

/**
 * get key sets of given map while not change their sequence.
 * the key set is ordered
 * @param origMap
 * @return vector array
 */

template<typename K, typename V>
std::vector<K> getMapKeySet(std::map<K, V> origMap) {
    std::vector<K> resultArr; //the map keys set result
    //need typename keyword because the ite is dependent scope
    using MapIterator = typename std::map<K, V>::iterator;
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
std::vector<V> getMapValueSet(std::map<K, V> origMap) {
    std::vector<V> resultArr; //the map values set result
    //need typename keyword because the ite is dependent scope
    using MapIterator = typename std::map<K, V>::iterator;
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
std::map<V, K> sortMapByValue(std::map<K, V> origMap) {
    std::map<V, K> resultMap;
    using MapIterator = typename std::map<K, V>::iterator;
    for (MapIterator ite = origMap.begin(); ite != origMap.end(); ite++) {
        //for iterator, ite->first = key, ite->second = value.
        resultMap.insert(std::pair<V, K>(ite->second, ite->first));
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
std::vector<K> getUnorderedMapKeySet(std::unordered_map<K, V> origMap) {
    std::vector<K> resultArr; //the map keys set result
    //need typename keyword because the ite is dependent scope
    using MapIterator = typename std::unordered_map<K, V>::iterator;
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
std::vector<V> getUnorderedMapValueSet(std::unordered_map<K, V> origMap) {
    std::vector<V> resultArr; //the map values set result
    //need typename keyword because the ite is dependent scope
    using MapIterator = typename std::unordered_map<K, V>::iterator;
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
std::map<V, K> sortUnorderedMapByValue(std::unordered_map<K, V> origMap) {
    std::map<V, K> resultMap; // sort the <v,k> pair
    using unorderedMapIterator = typename std::unordered_map<K, V>::iterator;
    //sort
    for (unorderedMapIterator ite = origMap.begin(); ite != origMap.end(); ite++) {
        //for iterator, ite->first = key, ite->second = value.
        resultMap.insert(std::pair<V, K>(ite->second, ite->first));
    }
    return resultMap;
};


/**
 * just test all of the map's function
 */
void testMapFunction() {
    std::pair<std::string, double> cpuPair = std::pair<std::string, double>("cpu", 4);
    std::pair<std::string, double> memPair = std::pair<std::string, double>("mem", 16);
    std::pair<std::string, double> diskPair = std::pair<std::string, double>("disk", 128);
    std::pair<std::string, double> nicPair = std::pair<std::string, double>("nic", 10);

    std::map<std::string, double> resourcesMap;
    resourcesMap.insert(cpuPair);
    resourcesMap.insert(memPair);
    resourcesMap.insert(diskPair);
    resourcesMap.insert(nicPair);
    std::cout << "map key set" << std::endl;
    std::vector<std::string> keyRes = getMapKeySet(resourcesMap);
    for (std::string key:keyRes)
        std::cout << key << "\t";
    std::cout << std::endl;
    std::cout << "map value set" << std::endl;
    std::vector<double> valueRes = getMapValueSet(resourcesMap);
    for (double value: valueRes)
        std::cout << value << "\t";
    std::cout << std::endl;
    std::cout << "map sort by value set" << std::endl;
    std::map<double, std::string> valueMap = sortMapByValue(resourcesMap);
    std::map<double, std::string>::iterator ite = valueMap.begin();
    for (; ite != valueMap.end(); ite++) {
        std::cout << ite->first << ":" << ite->second << std::endl;
    }
    std::cout << std::endl;


    std::unordered_map<std::string, double> unresourcesMap;
    unresourcesMap.insert(cpuPair);
    unresourcesMap.insert(memPair);
    unresourcesMap.insert(diskPair);
    unresourcesMap.insert(nicPair);
    std::cout << "unsorted_map key set" << std::endl;
    std::vector<std::string> unKeyRes = getUnorderedMapKeySet(unresourcesMap);
    for (std::string key:unKeyRes)
        std::cout << key << "\t";
    std::cout << std::endl;
    std::cout << "unsorted_map value set" << std::endl;
    std::vector<double> unValueRes = getUnorderedMapValueSet(unresourcesMap);
    for (double value: unValueRes)
        std::cout << value << "\t";
    std::cout << std::endl;
    std::map<double, std::string> unValueMap = sortUnorderedMapByValue(unresourcesMap);
    std::map<double, std::string>::iterator unMapIte = unValueMap.begin();
    std::cout << "unsorted_map sort by value set" << std::endl;
    for (; unMapIte != unValueMap.end(); unMapIte++) {
        std::cout << unMapIte->first << ":" << unMapIte->second << std::endl;
    }
    std::cout << std::endl;
}