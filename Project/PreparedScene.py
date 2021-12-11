from tkinter import*
from tkinter import StringVar

######################### Definations ###################################

##################### Login Window ######################################
PreparedScene = Tk()
#PreparedScene.geometry('300x200+600+300')
PreparedScene.title('Prepared Scene')
PreparedScene.configure(bg='white'  )
PreparedScene.resizable(0,0)
# Gets the requested values of the height and widht.
windowWidth = PreparedScene.winfo_reqwidth()
windowHeight = PreparedScene.winfo_reqheight()
 
# Gets both half the screen width/height and window width/height
positionRight = int(PreparedScene.winfo_screenwidth()/2 - windowWidth/2)
positionDown = int(PreparedScene.winfo_screenheight()/2 - windowHeight/2)
 
# Positions the window in the center of the page.
PreparedScene.geometry("500x200+{}+{}".format(positionRight, positionDown))
PreparedScene.state('normal')

###################################For Main window############################



#this part for programing
##################################################




######################################################
def returnHome():
    PreparedScene.state('withdrawn')


#def drawPath():
#	import 
	
   
#####################################################
#This part for design
##################################################

lbSource=Label(PreparedScene,text='Select source',bg = 'white' ,fg= 'black',
             font=('Times New Roman (Headings CS)',10,'bold')
             )
lbSource.place(relx=0.1 , rely=0.15)

vSource = StringVar(PreparedScene)
vSource.set("Cairo") # default value

wSource = OptionMenu(PreparedScene, vSource, "Alexandria", "Assiut", "Aswan", "Beheira", "Bani Suef", "Cairo", "Daqahliya", "Damietta", "Fayyoum", "Gharbiya", "Giza", "Helwan", "Ismailia", "Kafr El Sheikh")
wSource.place(relx=0.12 , rely=0.3)

##############################################################

lbDestination=Label(PreparedScene,text='Select destination',bg = 'white' ,fg= 'black',
             font=('Times New Roman (Headings CS)',10,'bold')
             )
lbDestination.place(relx=0.35 , rely=0.15)


vDestination = StringVar(PreparedScene)
vDestination.set("Cairo") # default value

wDestination = OptionMenu(PreparedScene, vDestination, "Alexandria", "Assiut", "Aswan", "Beheira", "Bani Suef", "Cairo", "Daqahliya", "Damietta", "Fayyoum", "Gharbiya", "Giza", "Helwan", "Ismailia", "Kafr El Sheikh")
wDestination.place(relx=0.37 , rely=0.3)
##############################################################

lbAlgorithm=Label(PreparedScene,text='Select algorithm',bg = 'white' ,fg= 'black',
             font=('Times New Roman (Headings CS)',10,'bold')
             )
lbAlgorithm.place(relx=0.65 , rely=0.15)


vAlgorithm = StringVar(PreparedScene)
vAlgorithm.set("Depthe") # default value

wAlgorithm = OptionMenu(PreparedScene, vAlgorithm, "Depthe", "Brith", "A*")
wAlgorithm.place(relx=0.67 , rely=0.3)



##############################################################
bdrawPath=Button(PreparedScene , text='Draw Path',
               font=('Times New Roman (Headings CS)',10,'bold'),
               bd=1 , bg='white', fg= 'black'
               #,command=drawPath
               )
bdrawPath.place(relx=0.6,rely=0.7)
####################################################
breturnHome=Button(PreparedScene , text='Return  home',
               font=('Times New Roman (Headings CS)',10,'bold'),
               bd=1 , bg='white', fg= 'black',
               command=returnHome
               )
breturnHome.place(relx=0.25,rely=0.7)
#####################################################

PreparedScene.mainloop()