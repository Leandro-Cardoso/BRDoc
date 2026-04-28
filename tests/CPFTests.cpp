#include <gtest/gtest.h>

#include "brdoc/CPF.hpp"

using namespace brdoc;

TEST(CPF, ValidCPF) {
    CPF cpf("529.982.247-25");

    EXPECT_EQ(cpf.value(), "52998224725");
    EXPECT_EQ(cpf.formatted(), "529.982.247-25");
}

TEST(CPF, ValidWithoutMask) {
    CPF cpf("52998224725");

    EXPECT_EQ(cpf.formatted(), "529.982.247-25");
}

TEST(CPF, InvalidCPFThrows) {
    EXPECT_THROW(CPF("111.111.111-11"), std::invalid_argument);
    EXPECT_THROW(CPF("12345678900"), std::invalid_argument);
    EXPECT_THROW(CPF("123"), std::invalid_argument);
}

TEST(CPF, Equality) {
    CPF a("52998224725");
    CPF b("529.982.247-25");

    EXPECT_TRUE(a == b);
}

TEST(CPF, Inequality) {
    CPF a("52998224725");
    CPF b("12345678909");

    EXPECT_TRUE(a != b);
}
