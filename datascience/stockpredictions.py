import math

def printTransactions(m, k, d, name, owned, prices):
    transactions = []
    
    # Estratégia: vender ações com preço atual alto e comprar ações com preço baixo
    for i in range(k):
        current_price = prices[i][-1]  # Preço atual da ação (último valor)
        previous_price = prices[i][-2]  # Preço do dia anterior
        
        # Vender ação se o preço atual for maior que o anterior e possuímos ações
        if current_price > previous_price and owned[i] > 0:
            transactions.append(f"{name[i]} SELL {owned[i]}")  # Vender todas as ações que possuímos
        
        # Comprar ação se o preço atual for menor que o anterior e temos dinheiro suficiente
        elif current_price < previous_price and m >= current_price:
            # Determinar quantas ações podemos comprar
            max_buyable = int(m // current_price)
            if max_buyable > 0:
                transactions.append(f"{name[i]} BUY {max_buyable}")
                m -= max_buyable * current_price  # Atualiza o dinheiro restante
    
    # Imprime o número de transações e as transações
    print(len(transactions))
    for transaction in transactions:
        print(transaction)

# Exemplo de execução
m = 90.00
k = 2
d = 400
name = ["iStreet", "HR"]
owned = [10, 0]
prices = [
    [4.54, 5.53, 6.56, 5.54, 7.60],  # Preços de iStreet
    [30.54, 27.53, 24.42, 20.11, 17.50]  # Preços de HR
]

# Executa o algoritmo de transações
printTransactions(m, k, d, name, owned, prices)
