# EmergenceSim

Simulador de Microcivilizações Emergentes. Este projeto demonstra uma 
simulação simples de surgimento e colapso de civilizações em um mapa 2D.

## Compilação

É necessário um compilador C++17.

```bash
make
./EmergenceSim
```

O programa gera um mapa 20x10 com algumas células contendo símbolos.
Se uma célula com símbolo tiver o clima de esperança, uma nova
civilização aparece. As civilizações envelhecem e colapsam após certo
período.
