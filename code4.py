import RPi.GPIO as GPIO
import time


def setup():
    
        GPIO.setmode(GPIO.BOARD)
        
        i = 0
        while i < 6:
            GPIO.setup(pins[i], GPIO.OUT)
            GPIO.output(pins[i], GPIO.LOW)
            i += 1
                    
        time.sleep(5)


def loop():
    
    while True:
        
        i = 1
        while i <= 6:
            
            j = 0
            while j < i:
                GPIO.output(pins[j], GPIO.HIGH)
                j += 1 
            time.sleep(d)
            
            if i == 6:
                break
            
            k = 0
            while k < 5:
                GPIO.output(pins[k], GPIO.LOW)
                GPIO.output(pins[k + i], GPIO.HIGH)
                time.sleep(d)
                k += 1
            
            l = 0
            while l < 6:
                GPIO.output(pins[l], GPIO.LOW)
                l += 1
            
            i += 1
            
        m = 0
        while m < 6:
            GPIO.output(pins[m], GPIO.LOW)
            m += 1


def destroy():
    
    i = 0
    while i < 6:
        GPIO.output(pins[i], GPIO.LOW)
        i += 1
    
    GPIO.cleanup()


pins = [11, 29, 31, 33, 35, 37, 11, 29, 31, 33, 35, 37]
d = 4

setup()

try:
    print('start')
    loop()

except KeyboardInterrupt:
    print('finish')
    destroy()    

