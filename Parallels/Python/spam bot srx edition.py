from pynput.keyboard import Key, Controller 
import time

Keyboard = Controller()

time.sleep(0)

count=0

while count <2:
    for letter in "Hiroshima and Travazap":
        
        Keyboard.press(letter)
        Keyboard.release(letter)
        
    Keyboard.press(Key.enter)   
    count +=1