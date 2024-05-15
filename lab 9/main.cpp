#include <iostream>
#include <cstring>

template<typename K, typename V>

class Map {
private:
    struct MapItem {
        int index;
        K key;
        V value;
    };

    MapItem items[50];
    int count = 0;

public:
    int Count() { return count; };
    void Set(const K key, V value) {
        for (int i = 0; i < count; i++) {
            if (items[i].key == key) {
                items[i].value = value;
                return;
            }
        }

        items[count] = { count, key, value };
        ++count;
    }
    bool Get(const K& key, V& value) {

        for (int i = 0; i < count; i++) {
            if (items[i].key == key) {
                value = items[i].value;
                return true;
            }
        }

        return false;
    }
    void Clear() { count = 0; }
    bool Delete(const K& key) {

        for (int i = 0; i < count; i++) {
            if (items[i].key == key) {

                for (int j = i + 1; j < count; j++)
                    items[j - 1] = items[j];
                return true;
            }
        }

        return false;
    }
    bool Includes(const Map<K, V>& map) {
        if (map.count > count)
            return 0;

        for (int i = 0; i < map.count; i++) {
            bool ok = 0;
            for (int j = 0; j < count; j++) {
                if (map.items[i].key == items[j].key) {
                    ok = 1;
                    break;
                }
            }
            if (!ok)
                return false;
        }
        return true;
    }
    const char*& operator[] (int key) {
        for (int i = 0; i < count; i++) {
            if (items[i].key == key) {
                return items[i].value;
            }
        }
        items[count] = { count, key, "" };
        ++count;
        return items[count - 1].value;
    }
    bool operator!= (Map<K, V> map) {
        if (count != map.count)
            return 0;
        for (int i = 0; i < count; i++) {
            if (items[i].key != map.items[i].key)
                return 0;
            if (items[i].value != map.items[i].value)
                return 0;
        }
        return 1;
    }
    const MapItem* begin() const {
        return &items[0];
    }
    const MapItem* end() const {
        return &items[count];
    }
};



int main()
{
    Map<int, const char*> m;
    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";

    for (auto [index, key, value] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    m[20] = "result";
    for (auto [index, key, value] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }

    return 0;

}