#this programme used to find out server address of any ip and uses tkinter gui
#information will be accessed via ip-api.com
from tkinter import*
import requests
from requests import get
import socket
import xml.etree.ElementTree as ET
from tkinter import messagebox
count=0
myText=None
root=None
result=None
get_info=None
tags=None
entryBox=None
temp_lebel=None
#button2 was just testing purpose only and no need to use
def button2():
    global myText
    global count
    count+=1
    myText.set(count)
def addchlbl(root):
    global myText
    myText=StringVar()
    myText.set("")
    myLabel=Label(root,textvariable=myText)
    myLabel.pack()
def info(ip_address):
    global get_info
    get_info=requests.request("GET","http://ip-api.com/xml/"+ip_address)
    global tags
    tags=ET.fromstring(get_info.text)
    #messagebox.showinfo("incomeing info","information received")
def button_host():
    #global temp_lebel
    myText=""
    ip_address=get("http://ipapi.co/ip")
    ip_address=ip_address.text
    info(ip_address)
    temp_lebel=Label(root,text='\n'.join(''.join(i.text) for i in tags))
    #temp_lebel=Label(root,text=myText)
    temp_lebel.pack()
    #messagebox.showinfo("incomeing info",'\n'.join(i.tag.join('').join(i.text) for i in tags))
    '''for i in tags:
        print (i.tag,i.text)'''
def button_address():
    global entryBox
    #global temp_lebel
    text=entryBox.get()
    ip_address=socket.gethostbyname(text)
    info(ip_address)
    #temp_lebel=Label(root,text='\n'.join(''.join(i.text) for i in tags))
    for i in tags:
        temp_lebel=Label(root,text=i.text)
        temp_lebel.pack()
def input_box(x):
    global entryBox
    entryBox=Entry(x)
    entryBox.pack()
def main():
    root=Tk()
    root.title("Server information")
    w=Label(root,text="Input a web address or for finding network info input 'host' without quotes")
    host_button=Button(root,text="Host ip info",command=button_host)
    address_button=Button(root,text="Address info",command=button_address)
    w.pack()
    host_button.pack()
    w=Label(root,text="or").pack()
    input_box(root)
    address_button.pack()
    addchlbl(root)
    changed_button=Button(root,text="click",command=button2).pack()
    root.mainloop()
main()
