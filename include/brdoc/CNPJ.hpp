#pragma once

#include <string>

#include "Document.hpp"

namespace brdoc {

class CNPJ : public Document {
public:
    explicit CNPJ(const std::string& value);

    std::string formatted() const override;

    bool operator==(const CNPJ& other) const noexcept;
    bool operator!=(const CNPJ& other) const noexcept;

private:
    static std::string normalize(const std::string& input);
};

}
