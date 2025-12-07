prev2 = 0
prev1 = 1

print(prev2)
print(prev1)
for fibo in range(18):
    newFibo = prev1 + prev2
    print(newFibo)
    prev2 = prev1
    prev1 = newFibo

#######################################
print("""""")
prev2 = 0
prev1 = 1
count = 2

def fibonacci(prev1, prev2):
    global count
    if count <= 19:
        newFibo = prev1 + prev2 
        print(newFibo)
        prev2 = prev1
        prev1 = newFibo
        count += 1
        fibonacci(prev1, prev2)
    else:
        return
    
fibonacci(1,0)


#######################################
print("""""")

def F(n):
    if n <= 1:
        return n
    else:
        return F(n - 1) + F(n - 2)
print("""""")
print("Implementando para conocer la posicion: 7")
print(F(7))
print("""""")
print("Implementando para conocer la posicion: 21")
print(F(21))
print("""""")
print("Implementando para conocer la posicion: 40")
print(F(40))
print("""""")


print("""""""""""")
print ("Dado a la cantidad masiva de tiempo para 71 y 95")
print("Usaremos O(n)")

def F(n):
    a,b = 0,1 
    for _ in range (n):
        a, b = b, a+ b
    return a
    
print(F(71))
print(F(95))

