#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "maze.h"

using testing::Eq;

TEST(test, a_sizeDisjSets){
    DisjointSets s1(6);
    EXPECT_EQ(6,s1.getNumberOfSets());
    int r1 = s1.find(0);
    int r2 = s1.find(3);
    s1.unionSets(r1,r2);
    EXPECT_EQ(5,s1.getNumberOfSets());
    r1 = s1.find(4);
    r2 = s1.find(5);
    s1.unionSets(r1,r2);
    EXPECT_EQ(4,s1.getNumberOfSets());
    r1 = s1.find(3);
    r2 = s1.find(4);
    s1.unionSets(r1,r2);
    EXPECT_EQ(3,s1.getNumberOfSets());
}


TEST(test, b_initMaze){
    Maze m1(5,5);
    EXPECT_EQ(m1.getSets().getNumberOfSets(),25);
    m1.printMaze();
}

TEST(test, c_buildMaze){
    Maze m1(5,5);
    m1.buildRandomMaze();
    m1.printMaze();
}


