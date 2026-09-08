import geometry.rectangle;

#include <gtest/gtest.h>

TEST(Rectangle, Area)
{
    Rectangle r(10.0, 5.0);

    EXPECT_DOUBLE_EQ(r.area(), 50.0);
}

TEST(Rectangle, ZeroWidth)
{
    Rectangle r(0.0, 5.0);

    EXPECT_DOUBLE_EQ(r.area(), 0.0);
}

TEST(Rectangle, ZeroHeight)
{
    Rectangle r(10.0, 0.0);

    EXPECT_DOUBLE_EQ(r.area(), 0.0);
}

TEST(Rectangle, OneByOne)
{
    Rectangle r(1.0, 1.0);

    EXPECT_DOUBLE_EQ(r.area(), 1.0);
}
