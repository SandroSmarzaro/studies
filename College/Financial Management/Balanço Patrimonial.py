import os
from time import sleep
#pyinstaller --onefile .\
clear = lambda: os.system('cls' if os.name == 'nt' else 'clear')

def initial_menu():
    #Função que printa o menu inicial
    clear()
    print('\nSELECIONE UMA AÇÃO\n')
    print('-' * 20)
    print('\n1 - Novo Arquivo\n')
    print('2 - Abrir Arquivo\n')
    print('3 - Salvar Arquivo\n')
    print('4 - Remover Arquivo\n')
    print('0 - Sair\n')
    print('-' * 20)
    initial_option = int(input('\nAÇÃO: '))
    
    return initial_option

def exit_system():
    #Função de print de aviso de saída do sistema
    clear()
    print('\n\n'+ '-' * 30)
    print('\nSaindo do sistema...\n')
    print('-' * 30 + '\n\n')
    sleep(0.7)

def create_file():
    #Função que cria o arquivo .txt nomeado como usuário deseja
    clear()
    print('\n\n' + '-' * 40)
    print('\nDIGITE O NOME DO ARQUIVO\n')
    print('-' * 40)
    file_name = str(input('\nNOME: '))
    print('\n'+ '-' * 40)
    file = open(file_name + '.txt', 'w+')
    file.close()
    clear()
    print('\n\n' + '-' * 40)
    print('\nARQUIVO CRIADO!\n')
    print('-' * 40)
    sleep(0.7)

def open_file():
    #Função que printa o menu de ações sobre o arquivo
    clear()
    print('\n\n'+'-' * 40)
    print('\nDigite o nome do arquivo a ser aberto: ')
    print('\n'+'-' * 40 + '\n')
    file_name = str(input())
    clear()
    print('\n\n' + '-' * 40)
    print('\nARQUIVO ABERTO!\n')
    print('-' * 40)
    sleep(0.7)
    reset_array()
    load_array(file_name)
    load_intellisense()
    item_option = 1
    while (item_option != 0):
        item_option = item_menu()   
        if (item_option == 0):
            print()
        elif (item_option == 1):
            show_option = 1
            while show_option != 0:
                show_option = show_items()
        elif (item_option == 2):
            specificItem_option = 1
            insert_option = 1
            while insert_option != 0:
                insert_option = insert_menu()
                if insert_option == 1: 
                    while (specificItem_option != 0):
                        specificItem_option = specificItem_menu()
                        if (specificItem_option == 0):
                            print()
                        elif (specificItem_option == 1):
                            item_insert(currentActive)
                        elif (specificItem_option == 2):
                            item_insert(active)
                        elif (specificItem_option == 3):
                            item_insert(currentPassive)
                        elif (specificItem_option == 4):
                            item_insert(passive)
                        elif (specificItem_option == 5):
                            item_insert(líquid)
                        else:
                            invalid_option()
                elif insert_option == 2:
                    insert_intellisense()
                elif insert_option == 0:
                    print()
                else:
                    invalid_option()
        elif (item_option == 3):
            specificItem_option = 1
            while (specificItem_option != 0):
                specificItem_option = specificItem_menu()
                if (specificItem_option == 0):
                    print()
                elif (specificItem_option == 1):
                    item_change(currentActive)
                elif (specificItem_option == 2):
                    item_change(active)
                elif (specificItem_option == 3):
                    item_change(currentPassive)
                elif (specificItem_option == 4):
                    item_change(passive)
                elif (specificItem_option == 5):
                    item_change(líquid)
                else:
                    invalid_option()
        elif (item_option == 4):
            specificItem_option = 1
            while (specificItem_option != 0):
                specificItem_option = specificItem_menu()
                if (specificItem_option == 0):
                    print()
                elif (specificItem_option == 1):
                    item_delete(currentActive)
                elif (specificItem_option == 2):
                    item_delete(active)
                elif (specificItem_option == 3):
                    item_delete(currentPassive)
                elif (specificItem_option == 4):
                    item_delete(passive)
                elif (specificItem_option == 5):
                    item_delete(líquid)
                else:
                    invalid_option()
        else:
            invalid_option()
        

def item_menu():
    #Função que printa as opções sobre os itens
    clear()
    print('\nSELECIONE UMA AÇÃO\n')
    print('-' * 20)
    print('\n1 - Mostar Balanço\n')
    print('2 - Inserir Item\n')
    print('3 - Alterar Item\n')
    print('4 - Remover Item\n')
    print('0 - Sair\n')
    print('-' * 20)
    item_option = int(input('\nAÇÃO: '))
    
    return item_option

def specificItem_menu():
    #Função que printa as opções especificas de cada item
    clear()
    print('\nSELECIONE UMA AÇÃO\n')
    print('-' * 30)
    print('\n1 - Ativo Circulante\n')
    print('2 - Ativo Não Circulante\n')
    print('3 - Passivo Circulante\n')
    print('4 - Passivo Não Circulante\n')
    print('5 - Patrimônio Líquido\n')
    print('0 - Sair\n')
    print('-' * 30)
    specificItem_option = int(input('\nAÇÃO: '))
    
    return specificItem_option

def insert_menu():
    #Função que printa o menu de tipos de inserção
    clear()
    print('\nSELECIONE UMA AÇÃO\n')
    print('-' * 30)
    print('\n1 - Inserção Manual')
    print('\n2 - Inserção Inteligente')
    print('\n0 - Sair\n')
    print('-' * 30)
    insert_option = int(input('\nAÇÂO: '))
    
    return insert_option

def load_array(file_name):
    #Função que transferi todos os dados no .txt para os vetores
    with open(file_name + '.txt', 'r') as file:
        for line in file:
            if (currentActive in line):
                name = line[6:].replace('\n', ' ')
                value = file.readline()[6:]
                currentActive_name.append(name)
                currentActive_value.append(value)
            elif (active in line):
                name = line[6:].replace('\n', ' ')
                value = file.readline()[6:]
                active_name.append(name)
                active_value.append(value)
            elif (currentPassive in line):
                name = line[6:].replace('\n', ' ')
                value = file.readline()[6:]
                currentPassive_name.append(name)
                currentPassive_value.append(value)
            elif (passive in line):
                name = line[6:].replace('\n', ' ')
                value = file.readline()[6:]
                passive_name.append(name)
                passive_value.append(value)
            elif (líquid in line):
                name = line[6:].replace('\n', ' ')
                value = file.readline()[6:]
                líquid_name.append(name)
                líquid_value.append(value)

def reset_array():
    #Função que remove todos os itens já existentes no vetor
    currentActive_name.clear()
    currentActive_value.clear()
    active_name.clear()
    active_value.clear()
    currentPassive_name.clear()
    currentPassive_value.clear()
    passive_name.clear()
    passive_value.clear()
    líquid_name.clear()
    líquid_value.clear()
    intellisense_name.clear()
    intellisense_id.clear()

def item_insert(code):
    #Função que inseri os dados no .txt
    clear()
    print('\n\n'+'-' * 30)
    print('\nDigite o nome do item: ')
    print('\n'+'-' * 30+ '\n')
    name = str(input())
    clear()
    print('\n\n'+'-' * 30)
    print('\nDigite o valor do item: ')
    print('\n'+'-' * 30 + '\n')
    value = str(input())
    if (currentActive == code):
        currentActive_name.append(name)
        currentActive_value.append(value)
    elif (active == code):
        active_name.append(name)
        active_value.append(value)
    elif (currentPassive == code):
        currentPassive_name.append(name)
        currentPassive_value.append(value)
    elif (passive == code):
        passive_name.append(name)
        passive_value.append(value)
    elif (líquid == code):
        líquid_name.append(name)
        líquid_value.append(value)
    clear()
    print('\n\n' + '-' * 40)
    print('\nITEM ADICIONADO!\n')
    print('-' * 40)
    sleep(0.7)

def show_items():
    #Função para mostrar todo balanço patrimônial 
    clear()
    active_currentSum = 0
    active_sum = 0
    passive_currentSum = 0
    passive_sum = 0
    líquid_sum = 0
    show_option = 1
    sum_totalActive = 0
    sum_totalPassive = 0
    print('\n\n'+'-' * 50)
    print('\n\tATIVO CIRCULANTE')
    print('\n'+'-' * 50 + '\n')
    for i in range(0, len(currentActive_name)):
        print(f'{currentActive_name[i]:<29}{currentActive_value[i]:>9}')
        active_currentSum += float(currentActive_value[i])
    print('\n' + '-' * 50)
    print(f'SOMA ATIVO CIRCULANTE: {active_currentSum:.2f}')
    print('-' * 50) 
    print('\n\n' + '-' * 50) 
    print('\n\tATIVO NÂO CIRCULANTE')
    print('\n'+'-' * 50 + '\n')
    for i in range(0, len(active_name)):
        print(f'{active_name[i]:<29}\t{active_value[i]:>9}')
        active_sum += float(active_value[i])
    print('\n' + '-' * 50)
    print(f'SOMA ATIVO NÂO CIRCULANTE: {active_sum:.2f}')
    sum_totalActive = active_currentSum + active_sum
    print('-' * 50)
    print('\n\n' + '-' * 50)
    print('\n\tPASSIVO CIRCULANTE')
    print('\n'+'-' * 50 +'\n')
    for i in range(0, len(currentPassive_name)):
        print(f'{currentPassive_name[i]:<29}\t{currentPassive_value[i]:>9}')
        passive_currentSum += float(currentPassive_value[i])
    print('\n' + '-' * 50)
    print(f'SOMA PASSIVO CIRCULANTE: {passive_currentSum:.2f}')
    print('-' * 50)
    print('\n\n' + '-' * 50)
    print('\n\tPASSIVO NÂO CIRCULANTE')
    print('\n'+'-' * 50 + '\n')
    for i in range(0, len(passive_name)):
        print(f'{passive_name[i]:<29}\t{passive_value[i]:>9}')
        passive_sum += float(passive_value[i])
    print('\n' + '-' * 50)
    print(f'SOMA PASSIVO NÂO CIRCULANTE: {passive_sum:.2f}')
    print('-' * 50)
    print('\n\n' + '-' * 50)
    print('\n\tPATRIMÔNIO LÍQUIDO')
    print('-' * 50 + '\n')
    for i in range(0, len(líquid_name)):
        print(f'{líquid_name[i]:<29}\t{líquid_value[i]:>9}')
        líquid_sum += float(líquid_value[i])
    print('\n' + '-' * 50)
    print(f'SOMA PATRIMÔNIO LÍQUIDO: {líquid_sum:.2f}')
    sum_totalPassive = líquid_sum + passive_sum +passive_currentSum
    print('-' * 50)
    print('\n\n' + '-' * 50)
    print(f'SOMA DOS ATIVOS: \t{sum_totalActive:.2f}')
    print('-' * 50)
    print(f'SOMA DOS PASSIVOS: \t{sum_totalPassive:.2f}')
    print('-' * 50)
    print('\n\n0 - Sair\n\n')
    show_option = int(input('AÇÃO: '))
    if (show_option != 0):
        invalid_option()

    return show_option

def item_change(code):
    #Função de mudar os dados de um elemento no vetor
    if (currentActive == code):
        item_change_menu()
        for i in range(0, len(currentActive_name)):
            print(f'[{i}] {currentActive_name[i]:<29} {currentActive_value[i]:>9}')
    elif (active == code):
        item_change_menu()
        for i in range(0, len(active_name)):
            print(f'[{i}] {active_name[i]:<29} {active_value[i]:>9}')
    elif (currentPassive == code):
        item_change_menu()
        for i in range(0, len(currentPassive_name)):
            print(f'[{i}] {currentPassive_name[i]:<29} {currentPassive_value[i]:>9}')
    elif (passive == code):
        item_change_menu()
        for i in range(0, len(passive_name)):
            print(f'[{i}] {passive_name[i]:<29} {passive_value[i]:>9}')
    elif (líquid == code):
        item_change_menu()
        for i in range(0, len(líquid_name)):
            print(f'[{i}] {líquid_name[i]:<29} {líquid_value[i]:>9}')
    print('\n\n' + '-' * 40 + '\n')
    change_option = int(input('Nº: '))
    change_specificItem(change_option, code)

def item_change_menu():
    #Função que printa o menu de trocar elemento
    clear()
    print('\n\n' + '-' * 40)
    print('\nDIGITE O NOME DO NÚMERO ESCOLHIDO\n')
    print('-' * 40 + '\n')

def change_specificItem(index, code):
    #Função que efetivamente trocará os dados
    clear()
    print('\n\n' + '-' * 40)
    print('\nDIGITE O NOME NOVO\n')
    print('-' * 40 + '\n')
    name = str(input())
    clear()
    print('\n\n' + '-' * 40)
    print('\nDIGITE O VALOR NOVO\n')
    print('-' * 40 + '\n')
    value = input()
    value += '\n'
    if (currentActive == code):
        currentActive_name[index] = name
        currentActive_value[index] = value
    elif (active == code):
        active_name[index] = name
        active_value[index] = value
    elif (currentPassive == code):
        currentPassive_name[index] = name
        currentPassive_value[index] = value
    elif (passive == code):
        passive_name[index] = name
        passive_value[index] = value
    elif (líquid == code):
        líquid_name[index] = name
        líquid_value[index] = value
    clear()
    print('\n\n' + '-' * 40)
    print('\nITEM ALTERADO!\n')
    print('-' * 40)
    sleep(0.7)

def item_delete(code):
    #Função que deleta dados no vetor
    if (currentActive == code):
        item_change_menu()
        for i in range(0, len(currentActive_name)):
            print(f'[{i}] {currentActive_name[i]:<29} {currentActive_value[i]:>9}')
    elif (active == code):
        item_change_menu()
        for i in range(0, len(active_name)):
            print(f'[{i}] {active_name[i]:<29} {active_value[i]:>9}')
    elif (currentPassive == code):
        item_change_menu()
        for i in range(0, len(currentPassive_name)):
            print(f'[{i}] {currentPassive_name[i]:<29} {currentPassive_value[i]:>9}')
    elif (passive == code):
        item_change_menu()
        for i in range(0, len(passive_name)):
            print(f'[{i}] {passive_name[i]:<29} {passive_value[i]:>9}')
    elif (líquid == code):
        item_change_menu()
        for i in range(0, len(líquid_name)):
            print(f'[{i}] {líquid_name[i]:<29} {líquid_value[i]:>9}')
    print('\n\n' + '-' * 40 + '\n')
    change_option = int(input('Nº: '))
    delete_specificItem(change_option, code)

def delete_specificItem(index, code):
    #Função que efetivamente deletará os dados
    clear()
    if (currentActive == code):
        currentActive_name.pop(index)
        currentActive_value.pop(index)
    elif (active == code):
        active_name.pop(index)
        active_value.pop(index)
    elif (currentPassive == code):
        currentPassive_name.pop(index)
        currentPassive_value.pop(index)
    elif (passive == code):
        passive_name.pop(index)
        passive_value.pop(index)
    elif (líquid == code):
        líquid_name.pop(index)
        líquid_value.pop(index)
    print('\n\n' + '-' * 40)
    print('\nITEM DELETADO!\n')
    print('-' * 40 + '\n')
    sleep(0.7)

def save_file():
    #Função para transferir os dados do vetor para o .txt
    clear()
    print('\n\n' + '-' * 40)
    print('\nDIGITE O NOME DO ARQUIVO A SER SALVO\n')
    print('-' * 40)
    file_name = str(input('\nNOME: '))
    print('\n'+ '-' * 40)
    with open(file_name + '.txt', 'w') as file:
        print(f'len = {len(currentActive_name)}')
        for i in range(0, len(currentActive_name)):
            file.write(currentActive + currentActive_name[i] + '\n')
            file.write(currentActive + currentActive_value[i] + '\n')
        for i in range(0, len(active_name)):
            file.write(active + active_name[i] + '\n')
            file.write(active + active_value[i] + '\n')
        for i in range(0, len(currentPassive_name)):
            file.write(currentPassive + currentPassive_name[i] + '\n')
            file.write(currentPassive + currentPassive_value[i] + '\n')
        for i in range(0, len(passive_name)):
            file.write(passive + passive_name[i] + '\n')
            file.write(passive + passive_value[i] + '\n')
        for i in range(0, len(líquid_name)):
            file.write(líquid + líquid_name[i] + '\n')
            file.write(líquid + líquid_value[i] + '\n')
    clear()
    print('\n\n' + '-' * 40)
    print('\nARQUIVO SALVO!\n')
    print('-' * 40)
    sleep(0.7)

def save_intellisense():
    #Função que salva os nomes dos elementos no .txt inteligente
    with open('intellisense' + '.txt', 'a+') as file:
        for i in range(0, len(currentActive_name)):
            file.write(currentActive + currentActive_name[i] + '\n')
        for i in range(0, len(active_name)):
            file.write(active + active_name[i] + '\n')
        for i in range(0, len(currentPassive_name)):
            file.write(currentPassive + currentPassive_name[i] + '\n')
        for i in range(0, len(passive_name)):
            file.write(passive + passive_name[i] + '\n')
        for i in range(0, len(líquid_name)):
            file.write(líquid + líquid_name[i] + '\n')

def load_intellisense():
    #Função que carrega todos dados no .txt inteligente para vetor
    with open('intellisense' + '.txt', 'r') as file:
        for line in file:
            if (currentActive in line):
                name = line[6:].replace('\n', ' ')
                intellisense_name.append(name)
                intellisense_id.append(currentActive)
            elif (active in line):
                name = line[6:].replace('\n', ' ')
                intellisense_name.append(name)
                intellisense_id.append(active)
            elif (currentPassive in line):
                name = line[6:].replace('\n', ' ')
                intellisense_name.append(name)
                intellisense_id.append(currentPassive)
            elif (passive in line):
                name = line[6:].replace('\n', ' ')
                intellisense_name.append(name)
                intellisense_id.append(passive)
            elif (líquid in line):
                name = line[6:].replace('\n', ' ')
                intellisense_name.append(name)
                intellisense_id.append(líquid)

def insert_intellisense():
    #Função que inseri no vetor elementos de outros .txt
    clear()
    print('\n\n' + '-' * 40)
    print('\nDIGITE O NOME DO ITEM\n')
    print('-' * 40)
    name = str(input('\nNOME: '))
    count = 0
    for i in range(0, len(intellisense_name)):
        if intellisense_name[i].split() == name.split():
            clear()
            count += 1
            print('\n\n' + '-' * 40)
            print('\nDIGITE O VALOR DO ITEM\n')
            print('-' * 40)
            value = float(input('\nVALOR: '))
            if (currentActive in intellisense_id[i]):
                currentActive_name.append(name)
                currentActive_value.append(value)
            elif (active in intellisense_id[i]):
                active_name.append(name)
                active_value.append(active)
            elif (currentPassive in intellisense_id[i]):
                currentPassive_name.append(name)
                currentPassive_value.append(value)
            elif (passive in intellisense_id[i]):
                passive_name.append(name)
                passive_value.append(value)
            elif (líquid in intellisense_id[i]):
                líquid_name.append(name)
                líquid_value.append(value)
            clear()
            print('\n\n' + '-' * 40)
            print('\nITEM ADICIONADO!\n')
            print('-' * 40)
            sleep(0.7)
    if count == 0:
        clear()
        print('\n\n' + '-' * 40)
        print('\nNOME NÂO ENCONTRADO!\n')
        print('-' * 40)
        sleep(0.7)
                
def create_intellisense():
  file = open('intellisense' + '.txt', 'a+')
  file.close()

def delete_file():
    #Função para excluir arquivos .txt gerados
    clear()
    print('\n\n' + '-' * 40)
    print('\nDIGITE O NOME DO ARQUIVO A SER DELETADO\n')
    print('-' * 40)
    file_name = str(input('\nNOME: '))
    print('\n'+ '-' * 40)
    os.remove(file_name + '.txt')
    clear()
    print('\n\n' + '-' * 40)
    print('\nARQUIVO EXCLUÍDO!\n')
    print('-' * 40)
    sleep(0.7)

def invalid_option():
    #Função para aviso inserção de opções inexistentes
    clear()
    print('\n\n'+ '-' * 30)
    print('\nOpção Inválida! Repita.\n')
    print('-' * 30)
    sleep(2)

option = 1
currentActive = '@4tC& '
active = '@4nC& '
currentPassive = '@p4C& '
passive = '@Pnc& '
líquid = '@p7L& '
currentActive_name = []
currentActive_value = []
active_name = []
active_value = []
currentPassive_name = []
currentPassive_value = []
passive_name = []
passive_value = []
líquid_name = []
líquid_value = []
intellisense_name = []
intellisense_id = []
while (option != 0):
    create_intellisense()
    option = initial_menu()
    if (option == 0):
        exit_system()
    elif (option == 1):
        create_file()
    elif (option ==2):
        open_file()
    elif (option == 3):
        save_file()
        save_intellisense()
    elif (option == 4):
        delete_file()
    else:
        invalid_option()       