// https://www.geeksforgeeks.org/map-vs-unordered_map-c/
// https://stackoverflow.com/questions/40320455/comparing-unordered-map-vs-unordered-set/40320514

void test_unordered_map() {
    unordered_map<int,int> map;
    map[3] =0; // map[key] = value
    map[4] = 2;
    map[1] = 5;
    if (map.count(3)) {
        printf("map exist 3\n");
        map.erase(3);
    }

    if (map.count(3)) 
        printf("map exist 3\n");
    else printf("map doesn't exist 3\n");
}

void test_unordered_set() {
    unordered_set<int> set;
    set.insert(3); //only store key
    set.insert(4);
    set.insert(1);
    if (set.count(3)) {
        printf("set exist 3\n");
        set.erase(3);
    }

    if (set.count(3)) 
        printf("set exist 3\n");
    else printf("set doesn't exist 3\n");
    
}

int main() {
    test_unordered_map();
    test_unordered_set();
    
    return 0;
}