import socket

def start_udp_listener():
    # Create a UDP socket
    udp_listener_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

    # Bind the socket to a specific address and port
    host = ''  # Empty string means all available interfaces
    port = 5555
    udp_listener_socket.bind((host, port))

    print(f"UDP Listener started on port {port}...")

    try:
        while True:
            # Wait for data to be received
            data, addr = udp_listener_socket.recvfrom(1024)

            # Print the received data and the sender's address
            print(f"Received from {addr[0]}:{addr[1]}: {data.decode('utf-8')}")

    except KeyboardInterrupt:
        print("UDP Listener terminated by the user.")

    finally:
        # Close the socket
        udp_listener_socket.close()

if __name__ == "__main__":
    start_udp_listener()
