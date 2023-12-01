#include <gtest/gtest.h>
#include "container.h"


TEST(Container_Test, push_back){
    Container<int, 5> _Container;

    _Container.push_back(1);
    _Container.push_back(2);
    _Container.push_back(3);

    EXPECT_EQ(_Container.data[0], 1);
    EXPECT_EQ(_Container.data[1], 2);
    EXPECT_EQ(_Container.data[2], 3);
}

TEST(Container_Test, size1){
    Container<int, 5> _Container;

    _Container.push_back(1);
    _Container.push_back(2);
    _Container.push_back(3);

    EXPECT_EQ(_Container.size, 3);
}

TEST(Container_Test, size2){
    Container<int, 1> _Container;

    _Container.push_back(1);
    _Container.push_back(2);
    _Container.push_back(3);

    EXPECT_EQ(_Container.size, 3);
}

TEST(Container_Test, capacity1){
    Container<int, 5> _Container;

    _Container.push_back(1);
    _Container.push_back(2);
    _Container.push_back(3);

    EXPECT_EQ(_Container.capacity, 5);
}

TEST(Container_Test, capacity2){
    Container<int, 1> _Container;

    _Container.push_back(1);
    _Container.push_back(2);
    _Container.push_back(3);

    EXPECT_EQ(_Container.capacity, 3);
}

TEST(Container_Test, print){
    Container<int, 5> _Container;
    _Container.push_back(1);
    _Container.push_back(2);
    _Container.push_back(3);

    testing::internal::CaptureStdout();
    _Container.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "1 2 3 \n");

}
