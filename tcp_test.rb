#!/usr/bin/env ruby

require 'socket'

nt = [ 0, 1, 0, 0, 1, 2, 4, 8, 4, 8, 1, 0, 0, 4, 4, 8, 0, 4, 4, 4 ]  #byte length of different datatypes
sock = TCPSocket.open 'localhost',5050

sock.send "username:password\x00", 0
header = sock.recv(1)
print '---got --- logged in'

message = [0,1,0,0] # I hope this is a byte array
message = message.pack("c*")
message+= [18].pack("i>")
message+= [10].pack("s")
message += [4].pack("i>")
message += ".z.T".bytes.pack("c*")
sock.send(message,0)
header = sock.recv 8
data_size = header[4..7].unpack("i<")[0].to_i
rest_of_data = sock.recv data_size #hard coded
p rest_of_data
data_type = rest_of_data[0].unpack("c")
p data_type

val = rest_of_data[1..4].unpack("i<")
p val
