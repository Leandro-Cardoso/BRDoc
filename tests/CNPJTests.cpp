#include <gtest/gtest.h>

#include "brdoc/CNPJ.hpp"

using namespace brdoc;

TEST(CNPJ, ValidCNPJ) {
    CNPJ cnpj("04.252.011/0001-10");

    EXPECT_EQ(cnpj.value(), "04252011000110");
    EXPECT_EQ(cnpj.formatted(), "04.252.011/0001-10");
}

TEST(CNPJ, ValidWithoutMask) {
    CNPJ cnpj("04252011000110");

    EXPECT_EQ(cnpj.formatted(), "04.252.011/0001-10");
}

TEST(CNPJ, InvalidCNPJThrows) {
    EXPECT_THROW(CNPJ("00.000.000/0000-00"), std::invalid_argument);
    EXPECT_THROW(CNPJ("12345678000100"), std::invalid_argument);
    EXPECT_THROW(CNPJ("123"), std::invalid_argument);
}

TEST(CNPJ, Equality) {
    CNPJ a("04252011000110");
    CNPJ b("04.252.011/0001-10");

    EXPECT_TRUE(a == b);
}

TEST(CNPJ, Inequality) {
    CNPJ a("04252011000110");
    CNPJ b("11222333000181");

    EXPECT_TRUE(a != b);
}
