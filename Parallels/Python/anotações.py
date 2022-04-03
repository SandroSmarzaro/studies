'''
print('Hello world!')
print(77 + 33)
print('77 + 33')
print('77' + '33')
print('Hello', 7)

variable = input('W variable?')
print('test of variable', variable)
print('is... {}'.format(variable.isalnum()))

firstnum = int(input('1º ='))
secondnum = int(input('2º ='))
print('The sum of {} and {} is: {}'.format(firstnum, secondnum, firstnum + secondnum))

#print('text' {:<^>20.3f}.format(variable), end = '')

number = float(input('Number?'))
print('Sucessor: {:.3f} and Predecessor: {:.3f}'.format(number + 1, number -1))

real = float(input(''))
print('Quantity: {}'.format(real // 3.27))

print("""Print
Grande""")
frase = str(input('String'))
print(frase[começo:fim:pulo])

#.count('simbolo') .lower() .upper() len() .strip() .replace('escolhido', 'trocado') 'simbolo' in frase .find('simbolo') .split() 'simbolo'.join(frase)

frase = str(input('Name:')).strip()
print(frase.upper())
print(frase.lower())
print(len(''.join(frase.split()))) #ou len(frase) - frase.count(' ')
palavraQuebrada = frase.split()    
print(len(palavraQuebrada[0]))     #ou frase.find(' ')

frase = str(input('City:')).strip()
primeiroNome = frase.split()
print('santo' in primeiroNome[0].lower()) #ou frase[:5].lower == 'santo'

frase = str(input('Name:')).strip()
print('silva' in frase.lower())

for count in range(0,10,1): #(incio < fim, i++)
    print(count)
lista.append(valor)                 #adicicionar elementos nna última posição
lista.sort(reverse = True)          #organiza a lista, paraemtro inverso on
lista.insert(index,valor)           #adicionando valores numa posição exata
lista.pop(index)                    #removendo o ultimo indece
lista.remove(valor)                 #remove a posição da 1º ocorrência do valor
lista1 = lista2                     #atribuição de endereço de 2 em 1
lista1 = lista2[:]                  #atribuição de copia de 2 em 1
len(lista)

print(diconario.values())
print(dicionario.keys())
print(dicionario.items())
for key, value in dicionario.items():
del diconario['chave']
dicionario['chave'] = 'novoValor'
'''