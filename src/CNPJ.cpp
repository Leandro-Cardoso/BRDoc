#include <stdexcept>

#include "brdoc/CNPJ.hpp"
#include "brdoc/Validators.hpp"

namespace brdoc {

CNPJ::CNPJ(const std::string& input)
    : Document(normalize(input))
{}

std::string CNPJ::normalize(const std::string& input) {
    std::string digits = validators::onlyDigits(input);

    if (!validators::isValidCNPJ(digits)) {
        throw std::invalid_argument("Invalid CNPJ");
    }

    return digits;
}

std::string CNPJ::formatted() const {
    return m_value.substr(0,2) + "." +
           m_value.substr(2,3) + "." +
           m_value.substr(5,3) + "/" +
           m_value.substr(8,4) + "-" +
           m_value.substr(12,2);
}

bool CNPJ::operator==(const CNPJ& other) const noexcept {
    return m_value == other.m_value;
}

bool CNPJ::operator!=(const CNPJ& other) const noexcept {
    return !(*this == other);
}

}
