#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    std::cout << "AEDA 2015/2016 - Componente pratica 3" << std::endl;
    return RUN_ALL_TESTS();;
}