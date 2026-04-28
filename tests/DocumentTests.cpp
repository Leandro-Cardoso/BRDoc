#include <gtest/gtest.h>

#include "brdoc/Document.hpp"

using namespace brdoc;

class TestDocument : public Document {
public:
    explicit TestDocument(const std::string& value)
        : Document(value) {}

    std::string formatted() const override {
        return m_value;
    }
};

TEST(Document, ValueAccess) {
    TestDocument doc("123");
    EXPECT_EQ(doc.value(), "123");
}

TEST(Document, ComparisonSameType) {
    TestDocument a("123");
    TestDocument b("123");
    TestDocument c("456");

    EXPECT_TRUE(a.value() == b.value());
    EXPECT_FALSE(a.value() == c.value());
}

TEST(Document, Formatted) {
    TestDocument doc("abc");
    EXPECT_EQ(doc.formatted(), "abc");
}
