import socket 

target_ip = "192.168.172.215"
target_port = 8080

udp_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

i = 1

while True:
    message = input("Imperio>>")

    message_bytes = message.encode('utf-8')

    udp_socket.sendto(message_bytes, (target_ip, target_port))

    print(i,message)
    i = i+1