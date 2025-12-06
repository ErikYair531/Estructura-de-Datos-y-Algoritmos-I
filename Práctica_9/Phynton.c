cadena1 = "hola"
cadena2 = "Mundo"
print(cadena1)
print(cadena2)

concat_cadenas = cadena1 + cadena2
print(concat_cadenas)


####################################

num_cadena = concat_cadenas +''+ str(3)
print(num_cadena) 

####################################

num_cadena = "{}{}{}".format(cadena1, cadena2, 3)
print(num_cadena)

####################################
num_cadena = "Cambiando el orden: {1} {2} {0} #".format(cadena1, cadena2, 3)
print(num_cadena)

####################################

print(1 + 5)
print(6 * 3)
print(10 - 4)
print(100 / 50)
print(10 % 2)
print(((20 * 3) +(10 + 1))/10)
print(2**2)

####################################

print("""""")
False and True

print(7<5)
print(7>5)
print((11*3)+2 == 36 -1)
print((11*3)+2 >= 36)
print("curso" != "CuRso")

####################################

print("""""")
import collections

planeta = collections.namedtuple('planeta',['nombre', 'numero'])

planeta1 = planeta ('Mercurio', 1)
print(planeta1)

planeta2 = planeta ('venus', 2) 

print(planeta1.nombre, planeta1. numero)

print(planeta2[0] , planeta2[1])

print('Campos de la tupla: { }' , format(planeta1._fields))

####################################

print("""""")
print("""""")
elementos ={'hidrogeno': 1, 'helio':2 , 'carbon':6}

print(elementos)

print(elementos['hidrogeno'])

####################################

elementos['litio'] = 3
elementos['nitrogeno']= 8

print(elementos)

elementos2 ={}
elementos2['H'] = {'name': 'Hydrogen', 'number': 1 , 'weight': 1.00794}
elementos2['He'] = {'name': 'Helium', 'number': 2 , 'weight': 4.002602}

print(elementos2)

####################################

print(elementos2['H'])
print(elementos2['H']['name'])
print(elementos2['H']['number'])
elementos2['H']['weight'] = 4.30 

print(elementos2['H']['weight'])

elementos2['H']. update({'gas noble': True})
print(elementos2['H'])

print(elementos2.items())

print(elementos2.keys())

####################################

print("""""")
print("""""")

def imprime_nombre(nombre):
    print("hola"+ nombre)

imprime_nombre("JJ")

def cuadrado(x): 
    return x**2

x=5 

print("El cuadrado de {} es {}". format(x, cuadrado(x)))

def varios (x): 
    return x**2, x**3, x**4

val1, val2, val3 = varios (2)

print("{} {} {}". format(val1, val2, val3))

def cuadrado_default(x=3):
    return x**2

cuadrado_default()

####################################
print("""""")
print("""""")

val4, _ , val5 = varios (2)
print("{} {} ".format(val4, val5))

print("""""")
print("""""")

vg = 'Global'
def funcion_v1():
    print(vg)

funcion_v1()
print(vg)

print("""""")
print("""""")

def funcion_v2():
    vg = "Local"
    print(vg)

funcion_v2()

print(vg)


####################################

print("""""")
print("""""")

def obtenerMayor(param1, param2):
    if param1 < param2: 
        print('{} es mayo que {}.'. format(param2, param1))


    obtenerMayor(5, 7)
    obtenerMayor(7, 4)

    x = y =z = 3 
    if X == y == z: 
        print(true)


def obtenerMayor2(param1, param2):
    if param1 < param2: 
        return param2
    else: 
        return param1
    
print("El mayor es {}". format (obtenerMayor2(4,20)))
print("El mayor es {}", format (obtenerMayor2(11,6)))


def obtenerMayor_idiom(param1, param2): 
        valor = param2 if(param1 < param2) else param1
        return valor
print ("El mayor es {}" .format(obtenerMayor_idiom(11,6)))

####################################
print("""""")
print("""""")

def numeros(num): 
    if num == 1: 
        print("Tu numero es 1")
    elif num == 2:
        print("Tu numero es 2")
    elif num == 3:
        print("Tu numero es 3")
    elif num == 4:
        print("Tu numero es 4")
    else: 
        print("No hay opcion")


numeros(2)

numeros(5)

def numeros_idiom(num):
    if num in (1,2,3,4):
        print("Tu numero es {}". format(num))
    else:
        print("{} no es una opcion". format(num))
        
numeros_idiom(2)

numeros_idiom(5)

def obtenerMasGrande(a,b,c):
    if a>b: 
        if a>c: 
            return a
        else: 
            return c
    else: 
        if b>c: 
            return b
        else: 
            return c

print("El mas grande es {}".format(obtenerMasGrande(7,13,1)))


####################################
print("""""")
print("""""")

def cuenta (limite):
    i = limite
    while True: 
        print(i)
        i = i -1
        if i == 0:
            break

cuenta (10)

print("""""")

def factorial(n): 
    i = 2
    tmp = 1
    while i < n+1: 
        tmp = tmp * i
        i = i + 1
    return tmp

print (factorial(4))

print (factorial(6))


####################################
print("""""")
print("""""")

for x in [1,2,3,4,5]:
    print(x)
print("""""")
for x in range(5):
    print(x)
print("""""")
for x in range (-5,2): 
    print(x)
print("""""")
for num in ["uno", "dos", "tres", "cuatro"]:
    print(num)
print("""""")

####################################
print("""""")
print("""""")

elementos = {'hidrogeno': 1, 'helio': 2, 'carbon':6}

for llave, valor in elementos.items():
    print(llave, "=", valor)


for valor in elementos.values(): 
    print(llave)

for valor in elementos.values():
    print(valor)


def cuenta_idiom(limite): 
    for i in range(limite, 0 , -1):
        print(i)
    else:
        print("Cuenta finalizada")

cuenta_idiom(5)

def cuenta_idiomv2(limite):
    for i in range (limite, 0 , -1):
        print(i)
        if i ==3: 
            break
    else:
        print("cuenta finalizada")

cuenta_idiomv2(5)

####################################
print("""""")
print("""""")

import math

x= math.cos(math.pi)

print(x)

from math import * 

x = cos(pi)

print(x)

from math import cos, pi 

x = cos(pi)

print(x)

####################################

print(dir(math))

help(math.log)

import math as ma

x = ma.cos(ma.pi)

print(x)

####################################

