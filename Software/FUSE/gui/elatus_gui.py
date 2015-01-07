import sys 
from avrdude_lib import *
from PyQt4 import QtGui, QtCore 
from hauptdialog import Ui_Dialog as Dlg

class MeinDialog(QtGui.QDialog, Dlg): 
   def __init__(self): 
      QtGui.QDialog.__init__(self) 
      self.setupUi(self)
   
      #create slots
      self.connect(self.B_Setfuse,
                   QtCore.SIGNAL("clicked()"), self.setfuse)


      #set listview
      #self.listView.setText("test")
               
   def setfuse(self):
      set_fuse("atmega88", "avrispv2", "8mhz_extern", "usb", "none")
   
   

app = QtGui.QApplication(sys.argv) 
dialog = MeinDialog() 
dialog.show() 
sys.exit(app.exec_())
