#include <stdexcept>
#include <cctype>

#include "brdoc/RG.hpp"
#include "brdoc/Validators.hpp"

namespace brdoc {

RG::RG(const std::string& input)
    : Document(normalize(input))
{}

std::string RG::normalize(const std::string& input) {
    std::string result;
    result.reserve(input.size());

    for (char c : input) {
        unsigned char uc = static_cast<unsigned char>(c);

        if (std::isalnum(uc)) {
            result.push_back(
                static_cast<char>(std::toupper(uc))
            );
        }
        else if (c == '.' || c == '-' || c == ' ') {
            continue;
        }
        else {
            throw std::invalid_argument("Invalid RG character");
        }
    }

    if (!isValidFormat(result)) {
        throw std::invalid_argument("Invalid RG");
    }

    return result;
}

bool RG::isValidFormat(const std::string& value) {
    // Tamanho:
    if (value.size() < 5 || value.size() > 14)
        return false;

    // Alfanumérico:
    for (char c : value) {
        if (!std::isalnum(static_cast<unsigned char>(c)))
            return false;
    }

    return true;
}

std::string RG::formatted() const {
    if (m_value.size() == 9) {
        return m_value.substr(0,2) + "." +
               m_value.substr(2,3) + "." +
               m_value.substr(5,3) + "-" +
               m_value.substr(8,1);
    }

    return m_value;
}

bool RG::operator==(const RG& other) const noexcept {
    return m_value == other.m_value;
}

bool RG::operator!=(const RG& other) const noexcept {
    return !(*this == other);
}

}
