#include <gtest/gtest.h>

#include "brdoc/RG.hpp"

using namespace brdoc;

TEST(RG, ValidNumericRG) {
    RG rg("12.345.678-9");

    EXPECT_EQ(rg.value(), "123456789");
}

TEST(RG, ValidAlphanumericRG) {
    RG rg("12.345.678-X");

    EXPECT_EQ(rg.value(), "12345678X");
}

TEST(RG, NoFormattingFallback) {
    RG rg("ABC12345");

    EXPECT_EQ(rg.formatted(), "ABC12345");
}

TEST(RG, InvalidTooShort) {
    EXPECT_THROW(RG("123"), std::invalid_argument);
}

TEST(RG, InvalidCharacters) {
    EXPECT_THROW(RG("12.345.678@"), std::invalid_argument);
}
