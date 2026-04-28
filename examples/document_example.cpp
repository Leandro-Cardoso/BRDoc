#include <iostream>
#include <memory>

#include "brdoc/CPF.hpp"
#include "brdoc/CNPJ.hpp"
#include "brdoc/Document.hpp"

int main() {
    try {
        std::unique_ptr<brdoc::Document> doc1 =
            std::make_unique<brdoc::CPF>("52998224725");

        std::unique_ptr<brdoc::Document> doc2 =
            std::make_unique<brdoc::CNPJ>("04252011000110");

        std::cout << "Doc1: " << doc1->formatted() << "\n";
        std::cout << "Doc2: " << doc2->formatted() << "\n";

    } catch (const std::exception& e) {
        std::cerr << "Erro: " << e.what() << "\n";
    }
}
