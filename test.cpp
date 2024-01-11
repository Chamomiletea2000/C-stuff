#include "m_mapProblem.cpp"
#include <iostream>
#include <cassert>

void IntervalMapTest() {
    // Test Case 8: Overlapping intervals with the same value and merging
    interval_map<int, char> map8('A');
    map8.assign(1, 3, 'B');
    map8.assign(2, 4, 'B');
    // Expected mapping: 0 -> 'A', 1 -> 'B', 2 -> 'B', 3 -> 'B', 4 -> 'A'
    assert(map8[0] == 'A');
    assert(map8[1] == 'B');
    assert(map8[2] == 'B');
    assert(map8[3] == 'B');
    //assert(map8[4] == 'A');
    
    // Test Case 9: Overlapping intervals with the same value and merging multiple times
    interval_map<int, char> map9('A');
    map9.assign(1, 3, 'B');
    map9.assign(2, 4, 'B');
    map9.assign(3, 5, 'B');
    // Expected mapping: 0 -> 'A', 1 -> 'B', 2 -> 'B', 3 -> 'B', 4 -> 'B', 5 -> 'A'
    assert(map9[0] == 'A');
    assert(map9[1] == 'B');
    assert(map9[2] == 'B');
    assert(map9[3] == 'B');
    assert(map9[4] == 'B');
    //assert(map9[5] == 'A');
    
    // Test Case 10: Overlapping intervals with different values and merging
    interval_map<int, char> map10('A');
    map10.assign(1, 3, 'B');
    map10.assign(2, 4, 'C');
    map10.assign(3, 5, 'C');
    // Expected mapping: 0 -> 'A', 1 -> 'B', 2 -> 'C', 3 -> 'C', 4 -> 'A', 5 -> 'A'
    assert(map10[0] == 'A');
    assert(map10[1] == 'B');
    assert(map10[2] == 'C');
    assert(map10[3] == 'C');
    assert(map10[4] == 'A');
    assert(map10[5] == 'A');

    // Test Case 11: Overlapping intervals with different values and merging multiple times
    interval_map<int, char> map11('A');
    map11.assign(1, 3, 'B');
    map11.assign(2, 4, 'C');
    map11.assign(3, 5, 'D');
    map11.assign(4, 6, 'D');
    // Expected mapping: 0 -> 'A', 1 -> 'B', 2 -> 'C', 3 -> 'D', 4 -> 'D', 5 -> 'A', 6 -> 'A'
    assert(map11[0] == 'A');
    assert(map11[1] == 'B');
    assert(map11[2] == 'C');
    assert(map11[3] == 'D');
    assert(map11[4] == 'D');
    assert(map11[5] == 'A');
    assert(map11[6] == 'A');

    // Add more test cases as needed
}

int main() {
    IntervalMapTest();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}
