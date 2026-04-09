<div style="font-family: 'Courier New', Courier, monospace;">
  <h1 align="center">TP2 AED's III - Pareamento de sequência de DNA</h1>

  <section align="center">
    <h2>👥 Autores:</h2>
    <ul type="none">
      <li>Joaquim Pedro do Nascimento Moreira de Jesus</li>
      <li>Victoria Almeida Tambasco</li>
      <li>Murilo Antonio da Silva</li>
      <li>Luiz Gabriel da Silva Cabrera</li>
      <li>Luiz Fernando Ferreira Cabral</li>
    </ul>
    <p><i>Trabalho desenvolvido em grupo conforme as diretrizes da disciplina.</i></p>
  </section>

  <hr>

  <section>
    <p>
      Este repositório contém o desenvolvimento do segundo trabalho prático da disciplina <b>AEDS 3 (DCE797)</b> do curso de Bacharelado em Ciência da Computação da Universidade Federal de Alfenas (UNIFAL).
    </p>
    <h2>🧬 Sobre o Projeto</h2>
    <p>
      O objetivo deste projeto é implementar e avaliar algoritmos para realizar o alinhamento (pareamento) de sequências de DNA. O problema consiste em encontrar a melhor forma de sobrepor duas sequências de nucleotídeos (A, T, C, G) para maximizar a pontuação de pareamento, respeitando as regras biológicas de formação da dupla hélice.
    </p>
    <h2>Regras de Pontuação</h2>
    <p>O alinhamento é pontuado da seguinte forma:</p>
    <ol>
      <li>
        <b>Base Pareada (Correta)</b>: +2 pontos (A com T, C com G).
      </li>
      <li>
        <b>Base Não Pareada</b>: -1 ponto.
      </li>
      <li>
        <b>Lacuna (Gap)</b>: -2 pontos (quando uma base é pareada com um espaço vazio "-").
      </li>
    </ol>
    <h2>🛠️ Algoritmos Implementados</h2>
    <p>O trabalho exige a resolução do problema utilizando dois paradigmas diferentes para análise de <i>trade-offs</i> entre eficiência e otimalidade:</p>
    <ul>
      <li><b>Programação Dinâmica</b>: Algoritmo que busca a solução ótima global do alinhamento.</li>
      <li><b>Algoritmo Guloso</b>: Implementação com foco em velocidade de execução, cuja otimalidade é testada em comparação à Programação Dinâmica.</li>
    </ul>
    <h2>📊 Relatório e Análise</h2>
    <p>Além do código, o projeto inclui uma análise experimental detalhada cobrindo:</p>
    <ul>
      <li><b>Metodologia</b>: Descrição da lógica de implementação de cada paradigma.</li>
      <li><b>Gráficos de Desempenho</b>: Relação entre o tamanho da entrada vs. Tempo de Execução e Consumo de Memória.</li>
      <li><b>Tabela de Resultados</b>: Comparação das pontuações obtidas por ambos os algoritmos em diversas instâncias de teste.</li>
    </ul>
    <h2>📁 Estrutura do Repositório</h2>
    <ul>
      <li><b>/src</b>: Código-fonte em C (arquivos <code>algoritmos.c</code> e <code>algoritmos.h</code>).</li>
      <li><b>/doc</b>: Relatório técnico em PDF e slides da apresentação.</li>
      <li><b>/instances</b>: Conjunto de instâncias de DNA utilizadas nos testes.</li>
    </ul>
    <p>
      <b>Professor:</b> Iago Augusto de Carvalho.<br>
      <b>Data de Entrega:</b> 12/04/2026 às 23h59.
    </p>
  </section>
</div>
