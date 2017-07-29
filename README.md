# Caixa_Eletronico
Simulação de um caixa eletrônico que realiza depósitos e saques.

*O Caixa Eletrônico de Bora-Bora*

O dono de um banco em Bora-Bora deseja instalar caixas eletrônicos nas magníficas praias da ilha, permitindo aos seus correntistas sacar e depositar dinheiro durante os momentos de lazer.

O objetivo é construir um programa que mantivesse a contabilidade do caixa e controlasse o número de notas necessárias para efetivar os saques.

Todas as manhãs a central fornece aos caixas notas de 100, 50, 10, 5 e 1 ducas. Todos os saques devem ser processados de maneira a utilizar o menor número possível de notas. Por exemplo, para um saque de 350 ducas o caixa deve entregar, se disponíveis, 3 notas de 100 e uma de 50 (ao invés de outras eventuais possibilidades como 7 notas de 50). Para que o caixa eletrônico processe depósitos é necessário que o usuário especifique a quantidade de notas (de cada tipo) que está sendo fornecida.

Faça um programa em C que simule um dia de funcionamento do caixa:

Lê a quantidade inicial de notas de 100, 50, 10, 5 e 1.
Lê um número inteiro N de operações a serem realizadas. Para cada operação é dado o código da operação: 0 para saque e 1 para depósito. Tratando-se de saque, é fornecido o valor do saque (um número inteiro); para depósitos, é fornecido o número de notas de 100, 50, 10, 5 e 1 que compõem o depósito.
Imprime, a cada operação realizada, o número de notas (para cada tipo) em caixa.
Rejeita os saques para os quais não há dinheiro suficiente em caixa ou não há as notas necessárias. Por exemplo, se o caixa tem apenas uma nota de 100 e o usuário deseja retirar 65 não há como efetivar o saque, embora haja dinheiro suficiente no caixa.
