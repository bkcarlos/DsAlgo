#include "Array_cpp.h"

int main(int argc, char** argv) {
    Array<int> array(5);
    array.insert(0, 3);
    array.insert(0, 4);
    array.insert(1, 5);
    array.insert(3, 9);
    array.insert(3, 10);

    std::cout << array.find(4) << std::endl;
    array.remove(0);

    std::cout << array << std::endl;

    return 1;
}