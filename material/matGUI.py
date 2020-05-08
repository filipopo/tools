#!/usr/bin/python
# GUI wrapper for material.py
from os import system
from sys import argv, exit
from PyQt5.QtWidgets import QApplication, QMainWindow, QPlainTextEdit, QLabel, QPushButton, QFileDialog
from PyQt5.QtCore import QSize

class MainWindow(QMainWindow):
    def __init__(self):
        # Makes a window
        QMainWindow.__init__(self)

        # Set's window properties
        self.setMinimumSize(QSize(580, 250))
        self.title = 'Texture swapper'
        self.setWindowTitle('Texture swapper')

        # The input to be sent to material.py
        self.list1 = self.addTextAndInput('Old textures: ', 60)
        self.list2 = self.addTextAndInput('New textures: ', 320)

        # Makes a file reader and the button that wil call it
        self.dialog = QFileDialog(self)
        button = QPushButton('Choose map', self)
        button.clicked.connect(self.Clicked)
        button.resize(100, 32)
        button.move(240, 198)

    # Function that will be called when the button is clicked
    def Clicked(self):
        map_f = self.dialog.getOpenFileName()[0]
        if map_f != '':
            src = self.list1.toPlainText().replace('\n', ',')
            dest = self.list2.toPlainText().replace('\n', ',')

            # Exec?
            system('./material.py ' + map_f + ' ' + src + ' ' + dest)

    # Makes input fields with labels
    def addTextAndInput(self, text, x):   
        lab = QLabel(self)
        lab.setText(text)
        inp = QPlainTextEdit(self)

        inp.move(x, 45)
        inp.resize(200, 128)
        lab.move(x, 10)

        return inp

# Run the application
app = QApplication(argv)
main = MainWindow()
main.show()
exit(app.exec_())
