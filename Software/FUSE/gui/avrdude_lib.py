import subprocess

#controller [atmega8,atmega16,atmega32]
#programer  [usbprog, LUFA]
#lfuse      [8mhz,16mhz]
#hfuse      [8mhz,16mhz]

programer_list = (
               ("usbprog", "avrispv2"),
               ("ripping_board","avrispv2"),
             )

fuse_list =  (
              #atmega88[pv]
              ("atmega88", "8mhz_extern",  "lfuse", "hfuse"),
              ("atmega88", "16mhz_extern", "lfuse", "hfuse"),
              # (atmega88, 2mhz_intern,  lfuse, hfuse),
              # (atmega88, 4mhz_intern,  lfuse, hfuse),
              # (atmega88, 8mhz_intern,  lfuse, hfuse),
            )


def set_fuse(controller, programer, fuse_pam, port, debug):
   for i in range(len(fuse_list)):
      if fuse_list[i][0] == controller:
         if fuse_list[i][1] == fuse_pam:
            print fuse_list[i]
            set_fuse_pam(fuse_list[i][0], port, programer,fuse_list[i][2],
                         fuse_list[i][3],"none",1)
            return 

            


def set_fuse_pam(controller, port, programer, lfuse,hfuse, param, debug):
# TODO
# -set param
   if debug:
      print controller + port + programer + lfuse + hfuse + param
   
   subprocess.Popen(["avrdude","-p",controller,"-P",port,"-c",programer,
                    "-U",lfuse,"-U",hfuse])

   

#set_fuse("atmega88","usb","avrispv2","lfuse:w:0x7f:m","hfuse:w:0xdf:m","param ",0)

#set_fuse("atmega88","avrispv2" ,"usb","8mhz_extern",1)

#for i in range(len(fuse)):
#   print i
#   print fuse[i][i]


