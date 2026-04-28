#include <stdexcept>

#include "brdoc/CPF.hpp"
#include "brdoc/Validators.hpp"

namespace brdoc {

CPF::CPF(const std::string& input)
    : Document(normalize(input))
{}

std::string CPF::normalize(const std::string& input) {
    std::string digits = validators::onlyDigits(input);

    if (!validators::isValidCPF(digits)) {
        throw std::invalid_argument("Invalid CPF");
    }

    return digits;
}

std::string CPF::formatted() const {
    return m_value.substr(0,3) + "." +
           m_value.substr(3,3) + "." +
           m_value.substr(6,3) + "-" +
           m_value.substr(9,2);
}

bool CPF::operator==(const CPF& other) const noexcept {
    return m_value == other.m_value;
}

bool CPF::operator!=(const CPF& other) const noexcept {
    return !(*this == other);
}

}
