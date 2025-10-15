import pandas as pd
import matplotlib.pyplot as plt
import os

DATA_DIR = "../DADOS"
ALGORITHMS = ["bubble", "selection", "insertion", "merge"]
INPUT_TYPES = ["Aleatorio", "Crescente", "Decrescente"]

COLORS = {"bubble": "r", "selection": "g", "insertion": "b", "merge": "m"}

data = {}
for algo in ALGORITHMS:
    filepath = os.path.join(DATA_DIR, f"{algo}_resultados.csv")
    if not os.path.exists(filepath):
        print(f"{filepath} não encontrado, ignorando...")
        continue
    data[algo] = pd.read_csv(filepath)

# Intervalo desejado de tamanhos
min_n, max_n = 1000, 300000

# Configurações de escala
SCALES = {
    "loglog": ("log", "log"),
    "linear": ("linear", "linear"),
    "logx": ("log", "linear"),
}

for tipo in INPUT_TYPES:
    for scale_name, (xscale, yscale) in SCALES.items():
        plt.figure(figsize=(10,6))
        for algo, df in data.items():
            subset = df[(df["tipo"] == tipo) & (df["n"] >= min_n) & (df["n"] <= max_n)]
            if subset.empty:
                continue
            plt.plot(subset["n"], subset["tempo"], 
                     color=COLORS[algo], linestyle='-', 
                     label=algo.capitalize())
        
        plt.xscale(xscale)
        plt.yscale(yscale)
        plt.xlabel("Tamanho da entrada", fontsize=22)
        plt.ylabel("Tempo médio (s)", fontsize=22)
        plt.xticks(fontsize=20)
        plt.yticks(fontsize=20)
        plt.grid(True, which="major", ls="--")
        plt.legend(fontsize=20)
        plt.tight_layout()
        plt.savefig(os.path.join(DATA_DIR, f"tempo_{tipo.lower()}_{scale_name}.png"))
        plt.close()

print("Gráficos gerados em", DATA_DIR)