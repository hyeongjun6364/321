from tkinter import *
import tkinter
import tkinter as tk
from os import system
from tkinter import Toplevel, filedialog
from PIL import ImageTk, Image
import PIL
a=1
win = tk.Tk()
win.geometry('500x550')


text1 = tk.Entry(win)
text2 = tk.Entry(win)
text3=tk.Text(win,width=30,height=20)

text1.place(x=100,y=400)#x,y에의한 배치
text2.place(x=300,y=400)#x,y에의한 배치
text3.place(x=100,y=30)#x,y에의한 배치

#파일탐색기 열기
def open():
    global my_image # 함수에서 이미지를 기억하도록 전역변수 선언 (안하면 사진이 안보임)
    win.filename = filedialog.askopenfilename(initialdir='', title='파일선택', filetypes=(
    ('png files', '*.png'), ('jpg files', '*.jpg'), ('all files', '*.*')))
 
    #label=tk.Label(win, text=win.filename).pack() # 파일경로 view
    my_image = ImageTk.PhotoImage(Image.open(win.filename))
    
    label=tk.Label(image=my_image).place(x=100,y=40) #사진 view
   
button1 = tk.Button(win, text='파일열기', command=open).place(x=100,y=350)


button2 = tk.Button(win, text="계산")
button2.place(x=250,y=400)

win.mainloop()


