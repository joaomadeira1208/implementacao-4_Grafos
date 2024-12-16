# implementacao-4_Grafos
# Compilar e rodar a implementação
Compile todos arquivos .cpp previamente e rode o arquivo Main.cpp.

## Exemplo de compilação e execução:
### MacOS
g++-14 -std=c++17 *.cpp -o Main && ./Main

### Windows
g++ -o programa *.cpp -std=c++17
./Main

# Formato das Imagens
A imagem deve estar no formato .ppm (P3 - Formato legível)

# Comando Python

Nosso código utiliza um script python. 

- Certifique de possuir o pip instalado para as bibliotecas corretas serem instaladas.
- Caso você utilize o comando `python3 arquivo.py` para executar um programa python, você deve alterar a linha 16 do arquivo `Main.cpp`:
    ```cpp
    "string command = "python script.py \"" + inputFile + ".ppm\" \"" + outputFile + ".ppm\" " + to_string(sigma);"
    ```
    Altere para:
    ```cpp
    "string command = "python3 script.py \"" + inputFile + ".ppm\" \"" + outputFile + ".ppm\" " + to_string(sigma);"
    ```