#!/bin/python3

import os

#
# Complete the 'queensAttack' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER n (tamanho do tabuleiro)
#  2. INTEGER k (numero de obstaculos)
#  3. INTEGER r_q (linha da rainha)
#  4. INTEGER c_q (coluna da rainha)
#  5. 2D_INTEGER_ARRAY obstacles (lista de obstaculos)
#

def queensAttack(n, k, r_q, c_q, obstacles):
    # Inicializar os limites das direcoes
    left = c_q - 1  # Limite esquerdo
    right = n - c_q  # Limite direito
    up = n - r_q  # Limite superior
    down = r_q - 1  # Limite inferior
    up_left = min(n - r_q, c_q - 1)  # Diagonal superior esquerda
    up_right = min(n - r_q, n - c_q)  # Diagonal superior direita
    down_left = min(r_q - 1, c_q - 1)  # Diagonal inferior esquerda
    down_right = min(r_q - 1, n - c_q)  # Diagonal inferior direita

    # Converter lista de obstaculo para um conjunto para busca rapida
    obstacle_set = {(r, c) for r, c in obstacles}

    # Ajustar os limites com base nos obstaculo
    for r_obs, c_obs in obstacles:
        if r_obs == r_q:  # Mesma linha da rainha
            if c_obs < c_q:  # obstaculo a esquerda
                left = min(left, c_q - c_obs - 1)
            elif c_obs > c_q:  # obstaculo a direita
                right = min(right, c_obs - c_q - 1)
        elif c_obs == c_q:  # Mesma coluna da rainha
            if r_obs < r_q:  # obstaculo abaixo
                down = min(down, r_q - r_obs - 1)
            elif r_obs > r_q:  # obstaculo acima
                up = min(up, r_obs - r_q - 1)
        elif abs(r_obs - r_q) == abs(c_obs - c_q):  # obstaculo esta em uma diagonal
            if r_obs > r_q and c_obs < c_q:  # Diagonal superior esquerda
                up_left = min(up_left, r_obs - r_q - 1)
            elif r_obs > r_q and c_obs > c_q:  # Diagonal superior direita
                up_right = min(up_right, r_obs - r_q - 1)
            elif r_obs < r_q and c_obs < c_q:  # Diagonal inferior esquerda
                down_left = min(down_left, r_q - r_obs - 1)
            elif r_obs < r_q and c_obs > c_q:  # Diagonal inferior direita
                down_right = min(down_right, r_q - r_obs - 1)

    total_attackable_squares = left + right + up + down + up_left + up_right + down_left + down_right

    return total_attackable_squares

if __name__ == '__main__':
    first_multiple_input = input().rstrip().split()

    n = int(first_multiple_input[0])
    k = int(first_multiple_input[1])

    second_multiple_input = input().rstrip().split()
    r_q = int(second_multiple_input[0])
    c_q = int(second_multiple_input[1])

    obstacles = []
    for _ in range(k):
        obstacles.append(list(map(int, input().rstrip().split())))

    result = queensAttack(n, k, r_q, c_q, obstacles)

    print(result)