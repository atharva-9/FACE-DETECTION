import bluetooth
from time import sleep
host=""
port=1
server = bluetooth.BluetoothSocket(bluetooth.RFCOMM)
try:
    server.bind((host, port))
    print("Bluetooth Binding Completed")
except:
    print("Bluetooth Binding Failed")
server.listen(1)
client, address = server.accept()
print("Connected To", address)
print("Client:", client)
try:
    while True:
        # Receivng the data. 
        data = client.recv(1024) # 1024 is the buffer size.
        print(data)
        if data==1:
            print ("recieved")
    sleep(1)

except:
    pass