# Inclusão de bibliotecas
import threading
import time

# Variaveis Globais
NUMBER_OF_TASKS = 3
turn = 1
saldo = 0

def _enter(task_number):
    global turn

    print(f'\nTask [{task_number}]: try entering critical area...')
    ''' Enquanto a task em execução for diferente da task em request
    Permanecer a thread em loop infinito até a em execução no momento finalizar e passar para seu turno'''
    while turn != task_number: 
        print(f'\nTask [{task_number}] await...')
    print(f'\nTask [{task_number}]: processing...')

def _leave(task_number):
    global turn

    print(f'\nTask [{task_number}] ending...')
    # Ao final da execução de uma thread, passa o turno para o próximo processo
    turn += 1
    # Tratamento de casos onde o turno é inexistente
    if turn > NUMBER_OF_TASKS:
        turn = 1
    time.sleep(1) 


def run_proc(task_number):
    global saldo
    
    while True:
        _enter(task_number)
        # ---------- INICIO ----------
        # Para cada thread específica executando no momento, faça o acrésimo correspondente
        if task_number == 1:
            saldo += 2
        elif task_number == 2:
            saldo += 100
        else:
            saldo += 52
        # Demonstração do resultado da operação
        print(f'\nTask [{task_number}]: modified to {saldo}')
        # ----------  FIM  -----------
        _leave(task_number)


if __name__ == "__main__":
    #Criação das váriavéis de threads, setando a função que ira executar e seus parametros
    thread1 = threading.Thread(target=run_proc, args=(1,))
    thread2 = threading.Thread(target=run_proc, args=(2,))
    thread3 = threading.Thread(target=run_proc, args=(3,))

    #Inicialização das threads
    thread1.start()
    thread2.start()
    thread3.start()

    #Paraleleizando as threads
    thread1.join()
    thread2.join()
    thread3.join()