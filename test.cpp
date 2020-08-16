#include <gtest/gtest.h>

int sum(int first, int second) {
    return first + second;
}

TEST(example, sum) {
    EXPECT_EQ(4, sum(2,2));
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
