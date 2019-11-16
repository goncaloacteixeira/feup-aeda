#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    std::cout << "AEDA 2018/2019 - Componente pratica 2" << std::endl;
    return RUN_ALL_TESTS();;
}