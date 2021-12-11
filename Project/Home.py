from tkinter import*
from tkinter import StringVar

######################### Definations ###################################

##################### Login Window ######################################
winMain = Tk()
#winMain.geometry('300x200+600+300')
winMain.title('Home Window ')
winMain.configure(bg='white'  )
winMain.resizable(0,0)
# Gets the requested values of the height and widht.
windowWidth = winMain.winfo_reqwidth()
windowHeight = winMain.winfo_reqheight()
 
# Gets both half the screen width/height and window width/height
positionRight = int(winMain.winfo_screenwidth()/2 - windowWidth/2)
positionDown = int(winMain.winfo_screenheight()/2 - windowHeight/2)
 
# Positions the window in the center of the page.
winMain.geometry("700x400+{}+{}".format(positionRight, positionDown))

###################################For Main window############################

im = PhotoImage(file='uni_ar.png')   # Add The photo here 
Lbim = Label(winMain , image=im , width = 300 ,height = 200)
Lbim.pack(fill = 'both' , expand = True)

#this part for programing
##################################################

######################################################
def Prepared_search():
    import PreparedScene

   
#####################################################
#This part for design
##################################################

####################################################

bPrapered=Button(winMain , text='Prepared search',
               font=('Times New Roman (Headings CS)',10,'bold'),
               bd=1 , bg='white', fg= 'black'
              , command=Prepared_search
               )
bPrapered.place(relx=0.4,rely=0.7)
#####################################################

winMain.mainloop()