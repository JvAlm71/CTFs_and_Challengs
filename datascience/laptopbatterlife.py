from numpy import double

def tempoBateria():
    n = float(input(""))
    
    
    if n < 4:
        total = n * 2
        return f'{total:.2f}'
    else:
        return '8.00'

resultado = tempoBateria()
print(resultado)

