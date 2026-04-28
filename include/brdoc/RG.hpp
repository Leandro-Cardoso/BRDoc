#pragma once

#include <string>

#include "Document.hpp"

namespace brdoc {

class RG : public Document {
public:
    explicit RG(const std::string& value);

    std::string formatted() const override;

    bool operator==(const RG& other) const noexcept;
    bool operator!=(const RG& other) const noexcept;

private:
    static std::string normalize(const std::string& input);
    static bool isValidFormat(const std::string& value);
};

}
