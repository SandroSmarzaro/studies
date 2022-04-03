'''
	Funções

'''
# Fatorial recursivo
def fat(n):
	if n == 0 or n == 1:
		return 1
	else:
		return n * fat(n -1)

print("Fatorial: ", fat(10))

#somar pares até n recursivo
'''
exemplo somaPar(8) 8 + 6 + 4 + 2

1. verificar se n é par
2. somar até 2 <<- critério de parada 
'''

def somaPar(n):
	'''soma Recursiva dos pares positivos até n
	'''
	if n % 2 != 0:
		n = n - 1
	if n == 0:
		return 0
	else:
		return n + somaPar(n -2)

def somaArb(*parametros):
	soma = 0
	for i in parametros: 
		soma += i
	return soma

def mediaArb(*parametros):
  return sum(parametros) / len(parametros)

def imc(peso, altura):
  return peso / (altura ** 2)

def area(lado = 10, altura = 20):
	return lado * altura

print("soma Recursiva :", somaPar(7))
print("Soma Arbritária:", somaArb(10,2,3,2,))
print("Media Arbitraria: ", mediaArb(8, 10, 14, 16))
print("Imc:", imc(altura = 1.9, peso = 89))
print("Area:", area(3))
print("Area:", area(5))
print("Area:", area(altura=35))