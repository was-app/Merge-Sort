import pandas as pd
import matplotlib.pyplot as plt
import os

DATA_DIR = "../DADOS"
ALGORITHMS = ["bubble", "selection", "insertion", "merge"]
INPUT_TYPES = ["Aleatorio", "Crescente", "Decrescente"]

COLORS = {"bubble": "r", "selection": "g", "insertion": "b", "merge": "m"}
MARKERS = {"Aleatorio": "o", "Crescente": "s", "Decrescente": "^"}

data = {}
for algo in ALGORITHMS:
    filepath = os.path.join(DATA_DIR, f"{algo}_resultados.csv")
    if not os.path.exists(filepath):
        print(f"{filepath} não encontrado, ignorando...")
        continue
    data[algo] = pd.read_csv(filepath)

plt.figure(figsize=(10,6))
for algo, df in data.items():
    for tipo in INPUT_TYPES:
        subset = df[df["tipo"] == tipo]
        plt.plot(subset["n"], subset["tempo"], 
                 marker=MARKERS[tipo], color=COLORS[algo], linestyle='-', 
                 label=f"{algo.capitalize()} - {tipo}")
plt.xscale("log")
plt.yscale("log")
plt.xlabel("Tamanho da entrada")
plt.ylabel("Tempo médio (s)")
plt.title("Comparação de tempo de execução")
plt.legend()
plt.grid(True, which="both", ls="--")
plt.tight_layout()
plt.savefig(os.path.join(DATA_DIR, "tempo_comparacao.png"))
plt.close()

plt.figure(figsize=(10,6))
for algo, df in data.items():
    for tipo in INPUT_TYPES:
        subset = df[df["tipo"] == tipo]
        plt.plot(subset["n"], subset["memoria"], 
                 marker=MARKERS[tipo], color=COLORS[algo], linestyle='-', 
                 label=f"{algo.capitalize()} - {tipo}")
plt.xscale("log")
plt.yscale("log")
plt.xlabel("Tamanho da entrada")
plt.ylabel("Memória máxima (KB)")
plt.title("Comparação de consumo de memória")
plt.legend()
plt.grid(True, which="both", ls="--")
plt.tight_layout()
plt.savefig(os.path.join(DATA_DIR, "memoria_comparacao.png"))
plt.close()

print("Gráficos gerados em", DATA_DIR)