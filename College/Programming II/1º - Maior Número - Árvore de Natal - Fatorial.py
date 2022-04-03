'''
Python básico 

'''
# Maior entre dois números
a = int(input("Valor de A: "))
b = int(input("Valor de B: "))

if a > b:
	print('a é maior')
elif a == b:
	print('a e b são iguais')
else:
	print('b é maior')

# Maior entre três números
a = int(input("Valor de A: "))
b = int(input("Valor de B: "))
c = int(input("Valor de C: "))
maior = a
if b > maior:
  maior = b
if c > maior:
  maior = c
print(maior)

#Programa asterisco
'''
*
* *
* * *
* * * *
'''

asterisco = int(input("Quantidade de asteriscos: "))

for i in range(1, asterisco + 1):
  print('* ' * i)

#Programa asterisco
'''
   *
  * *
 * * *
* * * *
'''

for i in range(1, asterisco + 1):
  print(' ' * (asterisco - i) + '* ' * i)

#Fatorial
numero = int(input("Numero: "))
#n! = 1 . ...... (n – 2) . (n – 1) . n
fatorial = 1

if numero > 0:
  for i in range(1, numero + 1):
    fatorial *= i
print(fatorial)