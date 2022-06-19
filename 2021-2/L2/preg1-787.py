
import sys
#sys.stdin = open('p1in.txt')
while 1:
    try:#exception catch cuando el archivo termine
        lst = list(map(int, input().split())) #escaneo de datos
        mul = 1
        max = -sys.maxsize - 1
        i = 0
        while (i < len(lst) - 1):#se prueban todas las posibilidadse de subsecuencias
            mul = 1
            j = i
            while (j < len(lst) - 1):
                mul *= lst[j]
                if(mul >= max):#si la multiplicacion de alguna es mayor entonces se setea como la mayor multiplicacion
                    max = mul
                j += 1
            i += 1
        print(max)
    except EOFError:
        break

#Ejercicio No.1
#Tarea No.3
#UVA id: Nisp
#Online judge id: 1171308
#autor: Nicolas Parra Garcia.
#autoria: Solucion propia.

