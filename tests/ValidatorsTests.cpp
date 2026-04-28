#include <gtest/gtest.h>

#include "brdoc/Validators.hpp"

using namespace brdoc::validators;

TEST(Validators, OnlyDigits) {
    EXPECT_EQ(onlyDigits("123.456-78"), "12345678");
    EXPECT_EQ(onlyDigits("abc123"), "123");
    EXPECT_EQ(onlyDigits(""), "");
}

TEST(Validators, CPFValid) {
    EXPECT_TRUE(isValidCPF("52998224725"));
    EXPECT_TRUE(isValidCPF("529.982.247-25"));
}

TEST(Validators, CPFInvalid) {
    EXPECT_FALSE(isValidCPF("11111111111"));
    EXPECT_FALSE(isValidCPF("12345678900"));
    EXPECT_FALSE(isValidCPF("123"));
}

TEST(Validators, CNPJValid) {
    EXPECT_TRUE(isValidCNPJ("04252011000110"));
    EXPECT_TRUE(isValidCNPJ("04.252.011/0001-10"));
}

TEST(Validators, CNPJInvalid) {
    EXPECT_FALSE(isValidCNPJ("00000000000000"));
    EXPECT_FALSE(isValidCNPJ("12345678000100"));
    EXPECT_FALSE(isValidCNPJ("123"));
}
