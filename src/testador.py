import os
import re
import subprocess

# 1. Configuração dos caminhos e executável
instances_dir = "/home/2025.1.08.014/TP2-AEDs_III-Pareamento_DNA/instances/"
output_csv = "/home/2025.1.08.014/TP2-AEDs_III-Pareamento_DNA/doc/results.csv"

# Assumindo que o executável 'dna' está na mesma pasta onde este script será rodado
executable = "./dna" 

# Função auxiliar para extrair o número do nome do arquivo para ordenação correta
def extract_number(filename):
    match = re.search(r'dna_(\d+)\.txt', filename)
    return int(match.group(1)) if match else 0

def main():
    # Garante que a pasta de destino (doc) exista
    os.makedirs(os.path.dirname(output_csv), exist_ok=True)

    # Lista e ordena os arquivos (ex: dna_5.txt, dna_10.txt, dna_25.txt...)
    arquivos = [f for f in os.listdir(instances_dir) if f.startswith("dna_") and f.endswith(".txt")]
    arquivos.sort(key=extract_number)

    # Abre o arquivo CSV para escrita
    with open(output_csv, "w", encoding="utf-8") as f_out:
        # Escreve o cabeçalho (corrigi o erro de digitação 'Reusltado' para você)
        f_out.write("Entrada;Resultado Prog. Dinâmica;Tempo Prog. Dinâmica;Resultado Prog. Guloso;Tempo Prog. Guloso;\n")

        print("Iniciando bateria de testes...\n")

        # Percorre todos os arquivos da pasta
        for arquivo in arquivos:
            filepath = os.path.join(instances_dir, arquivo)
            tamanho = extract_number(arquivo)
            
            print(f"Rodando teste para {arquivo}...")

            # Executa o programa C e captura a saída do terminal
            process = subprocess.run([executable, filepath], capture_output=True, text=True)
            saida = process.stdout

            # Expressões regulares para buscar os padrões de texto do seu programa
            regex_dp = r"Programação Dinâmica:\s*Resultado:\s*(-?\d+)\s*Tempo:\s*([0-9.]+)"
            regex_guloso = r"Guloso:\s*Resultado:\s*(-?\d+)\s*Tempo:\s*([0-9.]+)"

            match_dp = re.search(regex_dp, saida)
            match_guloso = re.search(regex_guloso, saida)

            if match_dp and match_guloso:
                # Extrai os grupos capturados pela regex
                res_dp = match_dp.group(1)
                tempo_dp = match_dp.group(2)
                res_guloso = match_guloso.group(1)
                tempo_guloso = match_guloso.group(2)

                # Dica de ouro: Substituir o ponto por vírgula no tempo.
                # Se você for abrir esse CSV no Excel em português, ele só entende casas decimais com vírgula.
                tempo_dp = tempo_dp.replace('.', ',')
                tempo_guloso = tempo_guloso.replace('.', ',')

                # Escreve a linha formatada no CSV
                linha_csv = f"{tamanho};{res_dp};{tempo_dp};{res_guloso};{tempo_guloso};\n"
                f_out.write(linha_csv)
            else:
                print(f"[ERRO] A saída do arquivo {arquivo} não estava no formato esperado.")
                print(f"Saída recebida:\n{saida}\n")

    print(f"\nConcluído! Todos os testes foram salvos em:\n{output_csv}")

if __name__ == "__main__":
    main()