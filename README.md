# BRDoc

Biblioteca C++ para validação, normalização e formatação de documentos brasileiros.

## ✨ Features

- CPF
  - Validação
  - Normalização
  - Formatação

- CNPJ
  - Validação
  - Normalização
  - Formatação

- RG
  - Validação básica
  - Suporte alfanumérico
  - Normalização
  - Formatação simples

- Testes automatizados com Google Test

## 📁 Estrutura do Projeto

```text
brdoc/
│
├── include/
│   └── brdoc/
│       ├── CPF.hpp
│       ├── CNPJ.hpp
│       ├── RG.hpp
│       ├── Document.hpp
│       └── Validators.hpp
│
├── src/
│   ├── CPF.cpp
│   ├── CNPJ.cpp
│   ├── RG.cpp
│   └── Validators.cpp
│
├── tests/
│   ├── CPFTests.cpp
│   ├── CNPJTests.cpp
│   ├── RGTests.cpp
│   ├── DocumentTests.cpp
│   └── ValidatorsTests.cpp
│
├── examples/
│   ├── cpf_example.cpp
│   ├── cnpj_example.cpp
│   ├── rg_example.cpp
│   ├── document_example.cpp
│   └── validators_example.cpp
│
├── CMakeLists.txt
├── .gitignore
├── README.md
└── LICENSE
```

## ⚙️ Requisitos

- C++ 20+
- CMake 3.20+
- Compiladores compatíveis:
    - GCC
    - Clang
    - MSVC

## 🚀 Build

1. Clone

```bash
git clone https://github.com/Leandro-Cardoso/brdoc/
cd brdoc
```

2. Configuração

```bash
cmake -S . -B build -G "MinGW Makefiles"
```

3. Gerar build

```bash
cmake --build build
```

## ▶️ Executar exemplos

#### Windows

```bash
cd build
.\cpf_example.exe
```

#### Linux

```bash
cd build
./cpf_example
```

## 🧪 Executar testes

```bash
cd build
ctest
```

Ou:

```bash
cd build
.\tests.exe
```

## 📌 Exemplos

#### CPF

```cpp
#include <iostream>
#include <brdoc/CPF.hpp>

int main() {
    brdoc::CPF cpf("529.982.247-25");

    std::cout << cpf.value() << "\n";
    std::cout << cpf.formatted() << "\n";
}
```

#### CNPJ

```cpp
#include <iostream>
#include <brdoc/CNPJ.hpp>

int main() {
    brdoc::CNPJ cnpj("04.252.011/0001-10");

    std::cout << cnpj.value() << "\n";
    std::cout << cnpj.formatted() << "\n";
}
```

#### RG

```cpp
#include <iostream>
#include <brdoc/RG.hpp>

int main() {
    brdoc::RG rg("12.345.678-X");

    std::cout << rg.value() << "\n";
    std::cout << rg.formatted() << "\n";
}
```

## 🧠 Design

A biblioteca utiliza:

- Value Objects
- Imutabilidade
- Normalização de entrada
- Fail-fast validation
- Separação entre domínio e validação

## 📚 Classes

| Classe | Descrição |
|---|---|
| `Document` | Classe base abstrata |
| `CPF` | Documento CPF |
| `CNPJ` | Documento CNPJ |
| `RG` | Documento RG |
| `Validators` | Funções auxiliares |

## 🔒 Validação

#### CPF

- Remove máscara
- Verifica tamanho
- Rejeita sequências repetidas
- Calcula dígitos verificadores

#### CNPJ

- Remove máscara
- Verifica tamanho
- Rejeita sequências repetidas
- Calcula dígitos verificadores

#### RG

Validação básica:

- caracteres válidos
- tamanho válido
- suporte alfanumérico

## 🧪 Testes

O projeto utiliza Google Test.

Cobertura atual:

- Validators
- Document
- CPF
- CNPJ
- RG

## 📄 Licença

[MIT License](https://github.com/Leandro-Cardoso/BRDoc/blob/main/LICENSE)
