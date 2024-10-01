from numpy import double

def tempoBateria():
    n = float(input(""))
    
    # Verifica se o número é menor que 4
    if n < 4:
        total = n * 2
        return f'{total:.2f}'
    else:
        return '8.00'

# Chama a funcao e imprime o resultado
resultado = tempoBateria()
print(resultado)

