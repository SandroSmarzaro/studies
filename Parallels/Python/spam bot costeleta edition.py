from pynput.keyboard import Key, Controller
import time
import os

Keyboard = Controller()

time.sleep(10)

count = 1

while count <= 10:
    time.sleep(1)
    os.system('cls')
    Keyboard.press(Key.ctrl)
    Keyboard.press("v")
    Keyboard.release(Key.ctrl)
    Keyboard.release("v")
    print (count)


    Keyboard.press(Key.enter)
    Keyboard.release(Key.enter)
    count += 1

