#pragma once

#include <string>

#include "Document.hpp"

namespace brdoc {

class CPF : public Document {
public:
    explicit CPF(const std::string& value);

    std::string formatted() const override;

    bool operator==(const CPF& other) const noexcept;
    bool operator!=(const CPF& other) const noexcept;

private:
    static std::string normalize(const std::string& input);
};

}
