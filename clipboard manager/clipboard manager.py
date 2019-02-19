#this programme uses pyperclip and openpyxl third party module
#make database.xlsx file to store data and add that path in wb variable
import pyperclip, os, time, openpyxl, datetime
current_text=""
previous_text=""
wb=openpyxl.load_workbook("/home/tomal/Desktop/c c++ problems/clipboard/database.xlsx") #path of database xlsx file
sheet=wb.get_sheet_by_name('Sheet1')
a_p=""
while True:
    time.sleep(5)
    current_text=pyperclip.paste()
    if (current_text!=previous_text and current_text!=""):
        if (int(datetime.datetime.now().strftime("%H"))>=0 and int(datetime.datetime.now().strftime("%H"))<12):
            a_p=" am"
        else:
            a_p=" pm"
        sheet.cell(row=len(sheet['A'])+1,column=1).value=datetime.datetime.now().strftime("%d %m %Y %I:%M:%S")+a_p
        sheet.cell(row=len(sheet['B']),column=2).value=current_text
        wb.save("/home/tomal/Desktop/c c++ problems/clipboard/database.xlsx") #same path of line 4
        previous_text=current_text
