import math

def printTransactions(m, k, d, name, owned, prices):
    transactions = []
    
    for i in range(k):
        current_price = prices[i][-1]  
        previous_price = prices[i][-2] 
        
        if current_price > previous_price and owned[i] > 0:
            transactions.append(f"{name[i]} SELL {owned[i]}")  
        
        
        elif current_price < previous_price and m >= current_price:
            
            max_buyable = int(m // current_price)
            if max_buyable > 0:
                transactions.append(f"{name[i]} BUY {max_buyable}")
                m -= max_buyable * current_price  
    
  
    print(len(transactions))
    for transaction in transactions:
        print(transaction)


m = 90.00
k = 2
d = 400
name = ["iStreet", "HR"]
owned = [10, 0]
prices = [
    [4.54, 5.53, 6.56, 5.54, 7.60],  
    [30.54, 27.53, 24.42, 20.11, 17.50]  
]


printTransactions(m, k, d, name, owned, prices)
