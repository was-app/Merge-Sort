#!/bin/bash
set -e  # para parar o script se algum comando falhar

# --- Build do projeto ---
echo "Compilando o projeto..."
make

# --- Rodar o executável ---
echo "Rodando o executável..."
./sort

# --- Criar e ativar um ambiente virtual Python ---
echo "Configurando ambiente Python..."
python3 -m venv data_analysis/venv
source data_analysis/venv/bin/activate

# --- Atualizar pip ---
pip install --upgrade pip --break-system-packages

# --- Instalar dependências ---
if [ -f data_analysis/requirements.txt ]; then
    pip install -r data_analysis/requirements.txt --break-system-packages
else
    echo "requirements.txt não encontrado, pulando instalação de pacotes."
fi

# --- Rodar o script de gráficos ---
if [ -f data_analysis/graficos.py ]; then
    echo "Gerando gráficos..."
    python3 data_analysis/graficos.py
else
    echo "graficos.py não encontrado, pulando etapa de gráficos."
fi

# --- Desativar o venv ---
deactivate

