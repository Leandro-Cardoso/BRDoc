#include <algorithm>
#include <cctype>
#include <vector>

#include "brdoc/Validators.hpp"

namespace brdoc::validators {

std::string onlyDigits(const std::string& input) {
    std::string result;
    std::copy_if(input.begin(), input.end(), std::back_inserter(result),
        [](unsigned char c) { return std::isdigit(c); });
    return result;
}

static bool allDigitsEqual(const std::string& s) {
    return std::all_of(s.begin(), s.end(),
        [&](char c) { return c == s[0]; });
}

// CPF:

static int calculateCPFDigit(const std::string& cpf, int weightStart) {
    int sum = 0;
    for (size_t i = 0; i < cpf.size(); ++i) {
        sum += (cpf[i] - '0') * (weightStart - i);
    }

    int remainder = (sum * 10) % 11;
    return (remainder == 10) ? 0 : remainder;
}

bool isValidCPF(const std::string& input) {
    std::string cpf = onlyDigits(input);

    if (cpf.size() != 11 || allDigitsEqual(cpf))
        return false;

    int digit1 = calculateCPFDigit(cpf.substr(0, 9), 10);
    int digit2 = calculateCPFDigit(cpf.substr(0, 10), 11);

    return digit1 == (cpf[9] - '0') &&
           digit2 == (cpf[10] - '0');
}

// CNPJ:

static int calculateCNPJDigit(const std::string& cnpj, const std::vector<int>& weights) {
    int sum = 0;
    for (size_t i = 0; i < weights.size(); ++i) {
        sum += (cnpj[i] - '0') * weights[i];
    }

    int remainder = sum % 11;
    return (remainder < 2) ? 0 : 11 - remainder;
}

bool isValidCNPJ(const std::string& input) {
    std::string cnpj = onlyDigits(input);

    if (cnpj.size() != 14 || allDigitsEqual(cnpj))
        return false;

    std::vector<int> weights1 = {5,4,3,2,9,8,7,6,5,4,3,2};
    std::vector<int> weights2 = {6,5,4,3,2,9,8,7,6,5,4,3,2};

    int digit1 = calculateCNPJDigit(cnpj.substr(0, 12), weights1);
    int digit2 = calculateCNPJDigit(cnpj.substr(0, 13), weights2);

    return digit1 == (cnpj[12] - '0') &&
           digit2 == (cnpj[13] - '0');
}

}
