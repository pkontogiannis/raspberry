import serial
from time import sleep
import sys
import psycopg2
import json 

#postgres conf
tableCreation = "CREATE TABLE IF NOT EXISTS sensorentry(id SERIAL PRIMARY KEY NOT NULL, num DECIMAL, data VARCHAR, timestamp TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP );"
#arduino conf
com = '/dev/ttyUSB0'
port = 9600
readTimeout = 3
readCycle = 10

#database conf
dbName = "raspdb"

ser = serial.Serial(com, port,  timeout = readTimeout)

print('Waiting for device');
sleep(3)
print(ser.name)

conn = psycopg2.connect('dbname='+dbName)
cur = conn.cursor()
cur.execute(tableCreation)

while True: 
	val = str(ser.readline().decode().strip('\r\n'))
	print(val)
	sleep(readCycle)
	j = json.loads(val)
	print(j['level'] +" " +j['value'])
	cur.execute("INSERT INTO sensorentry (num, data) VALUES (%s, %s)", (j['value'] , j['level']))
	conn.commit()
	
 

