#!/usr/bin/env python3
import threading
import time
import copy

quantum_time = 2
time_current = 0
queue = []

tasks = [
 {"name": "t.1", "time_ingress": 0, "duration": 5, "exec": []},
 {"name": "t.2", "time_ingress": 0, "duration": 2, "exec": []},
 {"name": "t.3", "time_ingress": 1, "duration": 4, "exec": []},
 {"name": "t.4", "time_ingress": 3, "duration": 1, "exec": []},
 {"name": "t.5", "time_ingress": 5, "duration": 2, "exec": []},
]

def _processing(task):
    global tasks, time_current, queue
    # seleciona o proximo processo a ser executado
    while True:
        # busca o processo que chegou ao sistema no tempo atual
        if task['time_ingress'] < time_current or task['time_ingress'] == tasks[0]['time_ingress']:
            break
        else:
            # envia o processo para o fim da fila
            queue.append(task)
    # Verifica se e a primeira execucao
    if -1 not in task['exec']:
        task['exec'].append(-1) # indica que o processo ja foi executado uma vez
        
    # verifica se e a ultima execucao do processo
    if task['duration'] <= quantum_time:
        time_current += task['duration']
    else:
        task['duration'] -= quantum_time # reduz um quantum da duracao do processo
        time_current += quantum_time # atualiza o tempo atual
        # envia o processo para o fim da lista
        queue.append(task)

def get_tasks():
  global tasks, time_current, queue
  # Cria uma copia da lista de processos
  queue = copy.deepcopy(tasks)
  # Inicializa o tempo atual com o instante de chegada do primeiro processo
  time_current = tasks[0]['time_ingress']

def run_scheduler():
    global tasks, time_current, queue
    print(r"Scheduler running...")
    print(f"Getting the process list at the time t={time_current}")
    get_tasks()
    while True:
      if len(queue) == 0:
        print(f"There is no task done at the time t={time_current}")
        time.sleep(1)
        time_current += 1
        break
      else:
        while True:
          try:
            task = queue.pop(0)
            _processing(task=task)
          except IndexError:
            print(f"There is no item in the queue at the time t={time_current}")
            break

if __name__ == "__main__":
  scheduler = threading.Thread(target=run_scheduler)
  scheduler.start()
  scheduler.join()
