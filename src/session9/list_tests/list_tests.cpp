//
// Created by Marina Ionel on 06/05/2020.
//

#include "gtest/gtest.h"

class TestLinkedList : public ::testing::Test {
protected:
    void SetUp() override {

    }

    void TearDown() override {

    }
};

TEST_F(TestLinkedList, Test1
) {
EXPECT_EQ(1, 1);
EXPECT_TRUE(true);
}

TEST_F(TestLinkedList, Test_hal_create_is_called
) {
production_create();

ASSERT_EQ(1u, hal_create_fake.call_count);
EXPECT_TRUE(10u, hal_create_fake.arg0_val);
}

