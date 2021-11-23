//
// Created by Marina Ionel on 06/05/2020.
//

#include "gtest/gtest.h"

extern "C" {
#include "../../session6/1/list.h"
}

class TestLinkedList : public testing::Test {
protected:
    list_t list;

    void SetUp() override {
        list = list_create();
    }

    void TearDown() override {
        list_destroy(list);
    }
};

TEST_F(TestLinkedList, Test_list_is_created
) {
    EXPECT_TRUE(list != nullptr);
}

TEST_F(TestLinkedList, Test_list_add_item
) {
    int value = 10;
    list_addItem(list, &value);
    EXPECT_EQ(list_noOfItems(list), 1);
}

TEST_F(TestLinkedList, Test_list_get_item) {
    int value = 10;
    list_addItem(list, &value);
    void *out = NULL;
    list_getItem(list, &out, 0);
    int *res = (int *) out;
    EXPECT_EQ(value, *res);
}

TEST_F(TestLinkedList, Test_remove_item) {
    int value = 10;
    list_addItem(list, &value);
    EXPECT_EQ(1, list_noOfItems(list));
    EXPECT_EQ(LIST_OK, list_removeItem(list, &value));
    EXPECT_EQ(0, list_noOfItems(list));
}
