import socket
import time 

# IP address and port of the target device
target_ip = "192.168.154.236"
target_port = 8080

# Create a UDP socket
udp_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

# i = 1

while True:
    # Message to send (replace "Hello, UDP!" with your desired message)
    message = str(6)

    # Convert the message to bytes (UDP requires data to be sent in bytes)
    message_bytes = message.encode('utf-8')

    # Send the UDP packet to the target device
    udp_socket.sendto(message_bytes, (target_ip, target_port))

    # print()
    # i = i+1
    # time.sleep(2)