###############################################

def cambio_greedy(cantidad, monedas):
    resultado = []
    
    for moneda in monedas:
        if cantidad >= moneda:
            num = cantidad // moneda
            cantidad -= num % moneda
            resultado.append((moneda, num))
           
    
    return resultado

monedas = [10, 5, 2, 1]  
cantidad = 28

sol = cambio_greedy(cantidad, monedas)
print("Cambio generado:")
for valor, numero in sol:
    print(f"{numero} monedas de {valor}")

###############################################

def insertion_sort(lista):
    for i in range(1, len(lista)):
        actual = lista[i]
        j = i - 1
        
        while j >= 0 and lista[j] > actual:
            lista[j + 1] = lista[j]
            j -= 1
        
        lista[j + 1] = actual
    
    return lista


numeros = [9, 3, 1, 7, 4, 2]
print("Lista ordenada:", insertion_sort(numeros))
