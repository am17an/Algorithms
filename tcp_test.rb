#!/usr/bin/env ruby

require 'socket'

=begin
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
=end
SYNC = true
ASYNC = false

NT = [ 0, 1, 0, 0, 1, 2, 4, 8, 4, 8, 1, 0, 0, 4, 4, 8, 0, 4, 4, 4 ]  #byte length of different datatypes

class Flip

  def initialize(d)
    @x = Array.new
    @y = Array.new

    d.each do |k,v|
      @x.push(k)
      @y.push(v)
    end
    
    @length = @y[0].to_s.length
    @index = 0
  end
end 

class Qkdb

  def initialize(host, port, login)
    @host = host
    @port = port
    @login = login
    connect(host, port, login)
  end

  def connect(host,port,login)
    @sock = TCPSocket.open(host, port)
    begin
      @sock.send(login+"\x00", 0)
      result = @sock.recv(1) 
      if not result
        raise "Access Denied"
      end
    rescue 
      raise "Unable to connect to host"
    end
     
  end

  def k(query,args = nil)

    if query.class==String and args.nil?
      _send(SYNC, query)
    end
    #TODO : Do the writing part,i.e. args is nil 
    _recv_from_server
  end 

  def _send(sync, query)
    n = _nx(query) + 8
    print n
    if sync
      message = [0,1,0,0].pack("c*") 
    else
      message = [0,0,0,0].pack("c*") 
    end
    message += [n].pack("N")
    message += _write(query)
    print message.bytes
    @sock.send(message, 0)
  end
  
  def _recv_from_server
   header = @sock.recv(8)
   data_size = header[4..7].unpack("i<")[0]
   inputBytes = @sock.recv data_size 
   p inputBytes.bytes
  end 

  def _nx(x)
    qtype = 10
    #TODO!
    j = 6

    sn = n(x)
    j += sn* NT[qtype]
    j
  end

  def n(x)
    x.length
  end 

  def _qtype(x)
   10
  end 
  def _write(x)
   #just writing chars for now
    size = n(x)
    message = [_qtype(x)].pack('s')
    message += [size].pack("N")
    message += _wc(x,message)
    message
  end

  def _wc(x, message)
    x.bytes.pack("c*")
  end

end
