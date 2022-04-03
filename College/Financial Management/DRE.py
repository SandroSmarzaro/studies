import os
from time import sleep
#gerar .exe pyinstaller --onefile .\

def initial_menu():
    #Função com o menu inicial que retorna a opção escolhida
    clear()
    print('\nSELECIONE UMA AÇÃO\n')
    print('-' * 20)
    print('\n1 - Novo Arquivo\n')
    print('2 - Abrir Arquivo\n')
    print('3 - Remover Arquivo\n')
    print('4 - Salvar Arquivo\n')
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
    #Função que abre o menu de ações sobre o arquivo
    clear()
    print('\n\n'+'-' * 40)
    print('\nDigite o nome do arquivo a ser aberto: ')
    print('\n'+'-' * 40 + '\n')
    file_name = str(input())
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
                initial_money = search_initial(file_name)
                show_option = show_items(initial_money)
        elif (item_option == 2):
            specificItem_option = 1
            insert_option = 1
            insert_option = insert_menu()
            if insert_option == 1:    
                while (insert_option != 0):        
                    while (specificItem_option != 0):
                        specificItem_option = specificItem_menu()
                        if (specificItem_option == 0):
                            print()
                        elif (specificItem_option == 1):
                            item_insert(specificItem_option)
                        elif (specificItem_option == 2):
                            item_insert(specificItem_option)
                        elif (specificItem_option == 3):
                            item_insert(specificItem_option)
                        elif (specificItem_option == 4):
                            item_insert(specificItem_option)
                        elif (specificItem_option == 5):
                            item_insert(specificItem_option)
                        elif (specificItem_option == 6):
                            initial_income = initial_venue(file_name)  
                        else:
                            invalid_option()
                    insert_option = insert_menu()
            elif insert_option == 0:
                print()
            elif insert_option == 2:
                insert_intellisense()
            else:
                invalid_option()
        elif (item_option == 3):
            specificItem_option = 1
            while (specificItem_option != 0):
                specificItem_option = specificItem_menu()
                clear()
                if specificItem_option != 0:
                    print('\n\n' + '-' * 45)
                    print('\nSELECIONE O ITEM\n')
                    print('-' * 45 + '\n')
                    if (specificItem_option == 0):
                        print()
                    elif (specificItem_option == 1):
                        for i in range(0, len(gross_income_name)):
                            print(f'[{i}] {gross_income_name[i]:<30}{gross_income_value[i]:>9}')
                    elif (specificItem_option == 2):
                        for i in range(0, len(net_income_name)):
                            print(f'[{i}] {net_income_name[i]:<30}{net_income_value[i]:>9}')
                    elif (specificItem_option == 3):
                        for i in range(0, len(gross_profit_name)):
                            print(f'[{i}] {gross_profit_name[i]:<30}{gross_profit_value[i]:>9}')
                    elif (specificItem_option == 4):
                        for i in range(0, len(operating_profit_name)):
                            print(f'[{i}] {operating_profit_name[i]:<30}{operating_profit_value[i]:>9}')
                    elif (specificItem_option == 5):
                        for i in range(0, len(pre_net_profit_name)):
                            print(f'[{i}] {pre_net_profit_name[i]:<30}{pre_net_profit_value[i]:>9}')
                    elif (specificItem_option == 6):
                        initial_venue(file_name)
                    else:
                        invalid_option()
                    if specificItem_option != 6:
                        print('\n'+ '-' * 40 + '\n')
                        index = int(input('ITEM: ')) 
                        change_item(specificItem_option, index)
        elif (item_option == 4):
            specificItem_option = 1
            while (specificItem_option != 0):
                specificItem_option = specificItem_menu()
                clear()
                if specificItem_option != 0:
                    print('\n\n' + '-' * 45)
                    print('\nSELECIONE O ITEM\n')
                    print('-' * 45 + '\n')
                    if (specificItem_option == 0):
                        print()
                    elif (specificItem_option == 1):
                        for i in range(0, len(gross_income_name)):
                            print(f'[{i}] {gross_income_name[i]:<30}{gross_income_value[i]:>9}')
                    elif (specificItem_option == 2):
                        for i in range(0, len(net_income_name)):
                            print(f'[{i}] {net_income_name[i]:<30}{net_income_value[i]:>9}')
                    elif (specificItem_option == 3):
                        for i in range(0, len(gross_profit_name)):
                            print(f'[{i}] {gross_profit_name[i]:<30}{gross_profit_value[i]:>9}')
                    elif (specificItem_option == 4):
                        for i in range(0, len(operating_profit_name)):
                            print(f'[{i}] {operating_profit_name[i]:<30}{operating_profit_value[i]:>9}')
                    elif (specificItem_option == 5):
                        for i in range(0, len(pre_net_profit_name)):
                            print(f'[{i}] {pre_net_profit_name[i]:<30}{pre_net_profit_value[i]:>9}')
                    elif (specificItem_option == 6):
                        initial_income = 0
                        initial.append(initial_income)
                        with open(file_name + '.txt', 'a') as file:
                            file.write(initial_code + str(initial_income) + '\n')
                    else:
                        invalid_option()
                    if specificItem_option != 6:
                        print('\n'+ '-' * 40 + '\n')
                        index = int(input('ITEM: ')) 
                        delete_item(specificItem_option, index)
        else:
            invalid_option()

def item_menu():
    #Função que printa as opções sobre os itens
    clear()
    print('\nSELECIONE UMA AÇÃO\n')
    print('-' * 20)
    print('\n1 - Mostar DRE\n')
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
    print('\n1 - Receita Operacional Bruta\n')
    print('2 - Receita Operacional Líquida\n')
    print('3 - Lucro Bruto\n')
    print('4 - Lucro Operacional\n')
    print('5 - Lucro Líquido Pré IR\n')
    print('6 - Receita Inicial\n')
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

def item_insert(id):
    #Função que inseri os dados no vetor
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
    if id == 1:
        gross_income_name.append(name)
        gross_income_value.append(value)
    elif id == 2:
        net_income_name.append(name)
        net_income_value.append(value)
    elif id == 3:
        gross_profit_name.append(name)
        gross_profit_value.append(value)
    elif id == 4:
        operating_profit_name.append(name)
        operating_profit_value.append(value)
    elif id == 5:
        pre_net_profit_name.append(name)
        pre_net_profit_value.append(value)
    clear()
    print('\n\n' + '-' * 40)
    print('\nITEM ADICIONADO!\n')
    print('-' * 40)
    sleep(0.7)

def show_items(initial_income):
    #Função para mostrar todo balanço patrimônial 
    deduction = float(initial_income)
    clear()
    print('\n\n'+'-' * 50)
    word = 'Receita Operacional Bruta'
    print(f'\n( = ) {word:<30} {deduction:<9}')
    print('\n'+'-' * 50 + '\n')
    for i in range(0, len(gross_income_name)):
        print(f'\t( - ) {gross_income_name[i]:<30} {gross_income_value[i]:<9}')
        deduction -= float(gross_income_value[i])
    print('\n\n'+'-' * 50)
    word = 'Receita Operacional Líquida'
    print(f'\n( = ) {word:<30} {deduction:.9}')
    print('\n'+'-' * 50 + '\n')
    for i in range(0, len(net_income_name)):
        print(f'\t( - ) {net_income_name[i]:<30} {net_income_value[i]:<9}')
        deduction -= float(net_income_value[i])
    print('\n\n'+'-' * 50)
    word = 'Lucro Bruto'
    print(f'\n( = ) {word:<30} {deduction:.9}')
    print('\n'+'-' * 50 + '\n')
    for i in range(0, len(gross_profit_name)):
        print(f'\t( - ) {gross_profit_name[i]:<30} {gross_profit_value[i]:<9}')
        deduction -= float(gross_profit_value[i])
    print('\n\n'+'-' * 50)
    word = 'Lucro Operacional'
    print(f'\n( = ) {word:<30} {deduction:.9}')
    print('\n'+'-' * 50 + '\n')
    for i in range(0, len(operating_profit_name)):
        print(f'\t( - ) {operating_profit_name[i]:<30} {operating_profit_value[i]:<9}')
        deduction -= float(operating_profit_value[i])
    print('\n\n'+'-' * 50)
    word = 'Lucro Líquido Antes do IR'
    print(f'\n( = ) {word:<30} {deduction:.9}')
    print('\n'+'-' * 50 + '\n')
    for i in range(0, len(pre_net_profit_name)):
        print(f'\t( - ) {pre_net_profit_name[i]:<30} {pre_net_profit_value[i]:<9}')
        deduction -= float(pre_net_profit_value[i])
    print('\n'+'-' * 50 + '\n')
    word = 'TOTAL'
    print(f'\n( = ) {word:<30} {deduction:.9}')
    print('\n'+'-' * 50 + '\n')
    print('\n\n0 - Sair\n\n')
    show_option = int(input('AÇÃO: '))
    if (show_option != 0):
        invalid_option()

    return show_option

def initial_venue(file_name):
    #Função que recebe o valor da receita a ser deduzida
    clear()
    print('\n\n'+'-' * 40)
    print('\nDigite o valor do item: ')
    print('\n'+'-' * 40+ '\n')
    initial_income = str(input())
    initial.append(initial_income)
    with open(file_name + '.txt', 'a') as file:
        file.write(initial_code + initial_income + '\n')

def search_initial(file_name):
    #Função que busca a receita a ser deduzida mais recente
    initial_money = 0
    if len(initial) < 1:
        with open(file_name + '.txt', 'r') as file:
            for line in file:
                if (initial_code in line):
                    initial_money = line[6:].replace('\n', ' ')
    else:    
        initial_money = initial[len(initial) - 1]
    
    return initial_money

def load_array(file_name):
    #Função que transfere os dados no txt em seu vetor correspondente 
    with open(file_name + '.txt', 'r') as file:
        for line in file:
            if (gross_income in line):
                name = line[6:].replace('\n', ' ')
                value = file.readline()[6:]
                gross_income_name.append(name)
                gross_income_value.append(value)
            elif (net_income in line):
                name = line[6:].replace('\n', ' ')
                value = file.readline()[6:]
                net_income_name.append(name)
                net_income_value.append(value)
            elif (gross_profit in line):
                name = line[6:].replace('\n', ' ')
                value = file.readline()[6:]
                gross_profit_name.append(name)
                gross_profit_value.append(value)
            elif (operating_profit in line):
                name = line[6:].replace('\n', ' ')
                value = file.readline()[6:]
                operating_profit_name.append(name)
                operating_profit_value.append(value)
            elif (pre_net_profit in line):
                name = line[6:].replace('\n', ' ')
                value = file.readline()[6:]
                pre_net_profit_name.append(name)
                pre_net_profit_value.append(value)
                
def reset_array():
    #Função que reseta os vetores com os dados txt para não duplicação de itens
    gross_income_name.clear()
    gross_income_value.clear()
    net_income_name.clear()
    net_income_value.clear()
    gross_profit_name.clear()
    gross_profit_value.clear()
    operating_profit_name.clear()
    operating_profit_value.clear()
    pre_net_profit_name.clear()
    pre_net_profit_value.clear()
    intellisense_name.clear()
    intellisense_id.clear()

def change_item(type, index):
    #Função para trocar os dados dos vetores
    clear()
    print('\n\n' + '-' * 40)
    print('\nDIGITE O NOVO NOME\n')
    print('-' * 40 + '\n')
    name = str(input('Nome: '))
    clear()
    print('\n\n' + '-' * 40)
    print('\nDIGITE O NOVO VALOR\n')
    print('-' * 40 + '\n')
    value = float(input('Valor: '))
    if (type == 0):
        print()
    elif type == 1:
        gross_income_value[index] = value
        gross_income_name[index] = name
    elif type == 2:
        net_income_name[index] = name
        net_income_value[index] = value
    elif type == 3:
        gross_profit_name[index] = name
        gross_profit_value[index] = value
    elif type == 4:
        operating_profit_name[index] = name
        operating_profit_value[index] = value
    elif type == 5:
        pre_net_profit_name[index] = name
        pre_net_profit_value[index] = value
    else: 
        print()
    clear()
    print('\n\n' + '-' * 40)
    print('\nITEM ALTERADO!\n')
    print('-' * 40)
    sleep(0.7)


def delete_item(type, index):
    #Função para excluir elementos do vetor
    if (type == 0):
        print()
    elif type == 1:
        gross_income_value.pop(index)
        gross_income_name.pop(index)
    elif type == 2:
        net_income_name.pop(index)
        net_income_value.pop(index)
    elif type == 3:
        gross_profit_name.pop(index)
        gross_profit_value.pop(index)
    elif type == 4:
        operating_profit_name.pop(index)
        operating_profit_value.pop(index)
    elif type == 5:
        pre_net_profit_name.pop(index)
        pre_net_profit_value.pop(index)
    else: 
        print()
    clear()
    print('\n\n' + '-' * 40)
    print('\nITEM DELETADO!\n')
    print('-' * 40 + '\n')
    sleep(0.7)
        
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
    print('\nARQUIVO DELETADO!\n')
    print('-' * 40 + '\n')
    sleep(0.7)

def save_file():
    #Função que faz as trabfêrencias dos dados do vetor pra armazenar no txt
    clear()
    print('\n\n' + '-' * 40)
    print('\nDIGITE O NOME DO ARQUIVO A SER SALVO\n')
    print('-' * 40)
    file_name = str(input('\nNOME: '))
    print('\n'+ '-' * 40)
    with open(file_name + '.txt', 'w') as file:    
        value_initial = str(search_initial(file_name))
        file.write(initial_code + value_initial + '\n')
        file.write('\n')
        for i in range(0, len(gross_income_name)):
            file.write(gross_income + gross_income_name[i] + '\n')
            file.write(gross_income + str(gross_income_value[i]) + '\n')
        for i in range(0, len(net_income_name)):
            file.write(net_income + net_income_name[i] + '\n')
            file.write(net_income + str(net_income_value[i]) + '\n')
        for i in range(0, len(gross_profit_name)):
            file.write(gross_profit + gross_profit_name[i] + '\n')
            file.write(gross_profit + str(gross_profit_value[i]) + '\n')
        for i in range(0, len(operating_profit_name)):
            file.write(operating_profit + operating_profit_name[i] + '\n')
            file.write(operating_profit + str(operating_profit_value[i]) + '\n')
        for i in range(0, len(pre_net_profit_name)):
            file.write(pre_net_profit + pre_net_profit_name[i] + '\n')
            file.write(pre_net_profit + str(pre_net_profit_value[i]) + '\n')
    clear()
    print('\n\n' + '-' * 40)
    print('\nARQUIVO SALVO!\n')
    print('-' * 40)
    sleep(0.7)       

def invalid_option():
    #Função para aviso inserção de opções inexistentes
    clear()
    print('\n\n'+ '-' * 30)
    print('\nOpção Inválida! Repita.\n')
    print('-' * 30)
    sleep(1)

def create_intellisense():
    #Função que cria o .txt inteligente
    file = open('intellisense' + '.txt', 'a+')
    file.close()

def save_intellisense():
    #Função que salva os nomes dos elementos no .txt inteligente
    with open('intellisense' + '.txt', 'a+') as file:
        for i in range(0, len(gross_income_name)):
            file.write(gross_income + gross_income_name[i] + '\n')
        for i in range(0, len(net_income_name)):
            file.write(net_income + net_income_name[i] + '\n')
        for i in range(0, len(gross_profit_name)):
            file.write(gross_profit + gross_profit_name[i] + '\n')
        for i in range(0, len(operating_profit_name)):
            file.write(operating_profit + operating_profit_name[i] + '\n')
        for i in range(0, len(pre_net_profit_name )):
            file.write(pre_net_profit + pre_net_profit_name [i] + '\n')

def load_intellisense():
    #Função que carrega todos dados no .txt inteligente para vetor
    with open('intellisense' + '.txt', 'r') as file:
        for line in file:
            if (gross_income in line):
                name = line[6:].replace('\n', ' ')
                intellisense_name.append(name)
                intellisense_id.append(gross_income)
            elif (net_income in line):
                name = line[6:].replace('\n', ' ')
                intellisense_name.append(name)
                intellisense_id.append(net_income)
            elif (gross_profit in line):
                name = line[6:].replace('\n', ' ')
                intellisense_name.append(name)
                intellisense_id.append(gross_profit)
            elif (operating_profit in line):
                name = line[6:].replace('\n', ' ')
                intellisense_name.append(name)
                intellisense_id.append(operating_profit)
            elif (pre_net_profit in line):
                name = line[6:].replace('\n', ' ')
                intellisense_name.append(name)
                intellisense_id.append(pre_net_profit)

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
            if (gross_income in intellisense_id[i]):
                gross_income_name.append(name)
                gross_income_value.append(value)
            elif (net_income in intellisense_id[i]):
                net_income_name.append(name)
                net_income_value.append(value)
            elif (gross_profit in intellisense_id[i]):
                gross_profit_name.append(name)
                gross_profit_value.append(value)
            elif (operating_profit in intellisense_id[i]):
                operating_profit_name.append(name)
                operating_profit_value.append(value)
            elif (pre_net_profit in intellisense_id[i]):
                pre_net_profit_name.append(name)
                pre_net_profit_value.append(value)
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

clear = lambda: os.system('cls' if os.name == 'nt' else 'clear')
option = 1
gross_income = '@R0b& '
net_income = '@R0l& '
gross_profit = '@LbT& '
operating_profit = '@L0l& '
pre_net_profit = '@L4r& '
initial_code = '@1nT& '
gross_income_name = []
gross_income_value = []
net_income_name = []
net_income_value = []
gross_profit_name = []
gross_profit_value = []
operating_profit_name = []
operating_profit_value = []
pre_net_profit_name = []
pre_net_profit_value = []
initial = []
intellisense_id = []
intellisense_name = []

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
        delete_file()
    elif (option == 4):
        save_intellisense()
        save_file()
    else:
        invalid_option() 