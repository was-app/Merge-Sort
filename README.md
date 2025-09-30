# Merge-Sort

Este projeto implementa e compara diferentes algoritmos de ordenação (Bubble Sort, Selection Sort, Insertion Sort e Merge Sort) em termos de tempo de execução e consumo de memória. Também gera gráficos de comparação a partir dos resultados coletados.

---

## Requisitos

- **Compilador C** (gcc ou similar)  
- **Python 3**  
- **Virtualenv**

Dependências Python (para gerar gráficos):

```text
pandas
matplotlib
```
Essas dependências estão listadas no arquivo requirements.txt.

## Configurações de Parâmetros

O tamanho das entradas, tipo de ordenação (aleatória, crescente ou decrescente) e o número de repetições podem ser configurados diretamente no arquivo main.c.

### Principais Parâmetros
- tamanhos[ ] -> define os tamanhos das listas a serem testadas
- NUM_REP -> define quantas vezes cada teste será repetido para a média
- SIZE_LIMIT -> define um limite para o tamanho de entradas para os algoritmos quadráticos

## Execução
Ambos os métodos devem ser executados a partir da pasta CODIGO

### Método 1: Usando run.sh (Recomendado)
Este script automatiza todo o pipeline:
- Compila o código C (make)
- Roda o executável e gera os resultados em CSV na pasta DADOS
- Cria um ambiente virtual Python (venv) e instala as dependências
- Gera gráficos a partir dos arquivos CSV
- Desativa o venv ao final

Para executar:
```bash
chmod +x run.sh
./run.sh
```

Após a execução você terá:
- Arquivos csv com os resultados em DADOS/
- Gráficos comparativos em DADOS/tempo_comparação.png e DADOS/memoria_comparação.png

### Método 2: Executando manualmente
Compilar o código C
```bash
make
```
Executar
```bash
./sort
```

Criar um ambiente virtual Python e instalar dependencias
```bash
python3 -m venv venv
source venv/bin/activate
pip install --upgrade pip
pip install -r requirements.txt
```

Gerar Gráficos
```bash
python3 data_analysis/graficos.py
```