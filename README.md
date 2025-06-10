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
Durante vários turnos, se uma célula tiver o clima "Luto" e o símbolo
"Nome Apagado", nasce uma nova civilização. Cada civilização envelhece a
cada turno e colapsa após atingir cinco turnos de idade.
