from string import ascii_letters, digits
from itertools import product
from time import time

caracteres = ascii_letters + digits   

def buscador(contrasena):
   
    if not (3 <= len(contrasena) <= 4):
        print("Ingresa una contraseña que contenga de 3 a 4 caracteres.")
        return

   
    archivo = open("combinaciones.txt", "w")

    print("Buscando...\n")
    intentos = 0

   
    for longitud in range(3, 5):
        for combinacion in product(caracteres, repeat=longitud):
            prueba = "".join(combinacion)
            intentos += 1

            archivo.write(prueba + "\n") 

            if prueba == contrasena:
                archivo.close()
                print(f"Tu contraseña es: {prueba}")
                print(f"Intentos realizados: {intentos}")
                return

    archivo.close()
    print("No se encontró la contraseña (algo raro pasó).")


t0 = time()
buscador("Erik")
print("Tiempo de ejecución:", round(time() - t0, 6), "segundos")





  
