1.  fd
    fd is a file descriptor

    permits is the *polymorphic* approach to IO
    read() / write() to device / file .. any device is a file.
    in the original design - read() from a scanner
                             write() to  a printer


2.  FIFO
    pipe

        (------------------)
    fd1 (                  ) fd2
        (------------------)

    unidirectional IPC
    queue .. FIFO

    flow control .. Pipe full vs empty
                    how reader handles vs writer handles

3. socket 

        (------ /\/ -------)
    fd1 (                  ) fd2
        (------ /\/ -------)
    server1                  server2

    bidirectional IPC
    interrupt driven
    makes heavy use of select()/poll()
    uses network stack .. layer2,3,4

    flow control .. buffer full/empty
                    how reader handles vs writer handles

3a. Local Socket   
    Unix Domain Socket
    Berkeley Sockets

        (------ /\/ -------)
    fd1 (                  ) fd2
        (------ /\/ -------)
    server1                  server1

    otherwise, almost everything else is same.
   
    
