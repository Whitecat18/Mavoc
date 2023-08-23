# Server for Mavoc tool to pass payload to victim
# https://github.com/Whitecat18/Mavoc

import sys
from http.server import SimpleHTTPRequestHandler
from socketserver import TCPServer

if len(sys.argv) != 2:
    print("Usage: python3 server.py <IP>")
    sys.exit(1)

local_ip_address = sys.argv[1]

class CustomHandler(SimpleHTTPRequestHandler):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, directory="psw-scripts", **kwargs)

if __name__ == "__main__":
    host = local_ip_address
    port = 80

    server = TCPServer((host, port), CustomHandler)
    print(f"Started Server {host}:{port}")
    server.serve_forever()
