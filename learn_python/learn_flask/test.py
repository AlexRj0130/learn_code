from flask import Flask
import time
import random

app = Flask(__name__)

@app.route('/')
def index():
    random_up = random.randint(85000, 88000)
    random_sec = random_up / 10000
    if (random_up != 0):
        time.sleep(random_sec)

    a = 1
    random_count = random.randint(1400, 1500)
    for i in range(random_count * 100):
        a = a * i

    print("random seconds = " + str(random_sec) + ", random for count = " + str(random_count))
        
    return 'Hello the Flask mini server!!!\n'

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=30001)
