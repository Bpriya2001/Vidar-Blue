import serial.tools.list_ports
import re
import json

import numpy as np
import paho.mqtt.client as mqtt
import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.neighbors import KNeighborsClassifier
from sklearn import metrics

# MQTT broker details
host = "mqtt.tago.io"
port = 1883
username = "Token"
password = "9692158f-a08d-46d4-85b1-47f71e483c40"
topic = "tago/A"

import datetime
current_time = datetime.datetime.utcnow().isoformat() + "Z"

def on_connect(client, userdata, flags, rc):
    if rc == 0:
        print("Connected to MQTT broker")
        client.publish(topic, json.dumps(payload))
    else:
        print("Connection failed. RC:", rc)

def on_publish(client, userdata, mid):
    print("Message published")

# Define the TagoIO API payload
payload = {
    "variable": "sensor_data",
    "unit": "",
    "value": 0,
    "time": "",
    "location": {},
    "metadata": {}
}

client = mqtt.Client()
client.on_connect = on_connect
client.on_publish = on_publish

# Set username and password
client.username_pw_set(username, password)

# Connect to the broker
client.connect(host, port, keepalive=60)

ports = list(serial.tools.list_ports.comports())

ser = serial.Serial('/dev/ttyUSB0', 115200)  # open serial port at 9600 baud rate

feature_names = ["Temperature", "Humidity", "CO2", "TVOC"]
df = pd.read_csv("sample.txt", delimiter=',')
X = df.iloc[:, 1:5]
Y = df.iloc[:, 5]

# Split data into 70% train and 30% test subsets
X_train, X_test, y_train, y_test = train_test_split(X, Y, test_size=0.3, random_state=123)
clf = KNeighborsClassifier(3)
# Learn the train subset
clf.fit(X_train, y_train)

def prediction(values):
    # Preprocess the input string of sensor values
    input_values = [int(val) for val in values.split(",")[1:]]
    # Make predictions using the trained classifier
    prediction = clf.predict([input_values])
    result = str(prediction[0])
    return result

while True:
    value = ser.readline().decode().rstrip()
    #text = "some text 170, 123, 456, 789, 012\n some more text 170, 111, 222, 333, 444\n"
    pattern = r'170,\s*\d+,\s*\d+,\s*\d+,\s*\d+\s*'
    matches = re.findall(pattern, value)

    #Payload sensor values
    strings = matches[0].split(",")

    #Payload ml result 
    mlp_result = prediction(matches[0])
    mlp = ""
    
    if mlp_result == "0":
        mlp = "good"
    elif mlp_result  == "1":
        mlp = "bad"
    
    # Payload
    payload = [
        {
            "variable": "temperature",
            "value": strings[1],
            "unit": "C",
            "metadata": {
                "mqtt_topic": "topic"
            }
        },
        {
            "variable": "humidity",
            "value": strings[2],
            "unit": "%",
            "metadata": {
                "mqtt_topic": "topic"
            }
        },
        {
            "variable": "CO2",
            "value": strings[3],
            "unit": "ppm",
            "metadata": {
                "mqtt_topic": "topic"
            }
        },
        {
            "variable": "TVOC",
            "value": strings[4],
            "unit": "ppb",
            "metadata": {
                "mqtt_topic": "topic"
            }
        },
          
        {
            "variable": "ml",
            "value": mlp,
            "unit": " ",
            "metadata": {
                "mqtt_topic": "topic"
            }
        } 
    ]
    client.publish(topic, json.dumps(payload))



ser.close()
