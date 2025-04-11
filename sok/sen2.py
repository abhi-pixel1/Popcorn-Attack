import socket 
import time

target_ip = "192.168.172.215"
target_port = 8080

udp_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

i = 1
msg = 0
flag = 0

vals = ['0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','?','@','A','B','C','D','E','F','G','H']

while True:
    message = vals[msg]

    message_bytes = message.encode('utf-8')

    udp_socket.sendto(message_bytes, (target_ip, target_port))

    print(i,message)
    i = i+1

    if(flag == 0):
        msg = msg+1

    if(flag == 1):
        msg = msg-1

    if(msg == len(vals)-1):
        msg = len(vals)-2
        flag = 1
    
    if(msg == 0):
        msg = 1
        flag = 0
    time.sleep(2)