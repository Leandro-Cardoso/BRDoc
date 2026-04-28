#pragma once

#include <string>

namespace brdoc {

class Document {
public:
    virtual ~Document() = default;

    const std::string& value() const noexcept {
        return m_value;
    }

    virtual std::string formatted() const = 0;

    bool operator==(const Document& other) const noexcept {
        return m_value == other.m_value;
    }

    bool operator!=(const Document& other) const noexcept {
        return !(*this == other);
    }

    bool operator<(const Document& other) const noexcept {
        return m_value < other.m_value;
    }

protected:
    explicit Document(std::string value)
        : m_value(std::move(value)) {}

    std::string m_value;
};

}
