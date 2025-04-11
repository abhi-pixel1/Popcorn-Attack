import socket

listener = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

host = ''
port = 5555
listener.bind((host, port))


while True:
    print("lis:")
    data, addr = listener.recvfrom(1024)

    d = data.decode('utf-8')
    print(addr[0],addr[1],d)
