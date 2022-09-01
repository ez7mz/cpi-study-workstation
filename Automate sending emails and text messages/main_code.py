'''
    Author : MESRAR Hamza - @ez7m.z - 🦂
    💬 : mesrarhamza48@gmail.com
'''

import smtplib
from fct import *

# content of mail message : ==============================================

str_msg = "My name is MESRAR HAMZA,  head of the EZ TEAM. I sent you this email to inform you that your project for this week is :  "

book_link = "https://bit.ly/3GQczXq"

# ================================================================

# enter the informations of "connection account" and verify your access to the program

admin_user, admin_pass = info_verf()

# =========================================================================

# Configuration of the SMTP server and connect to it

smtpObj = smtplib.SMTP("smtp.gmail.com", 587)
smtpObj.ehlo()
smtpObj.starttls()
smtpObj.login(admin_user, admin_pass)
ver_server_statu(smtpObj.login(admin_user, admin_pass)[0])

# ============================================================

# give the permission to the program to start send emails

command = input("type ' Start ' to give the program the order to send the emails: ")
while command.lower() != "start":
    print("Error! Try again")
    time.sleep(1.5)
    os.system("CLS")
    command = input("type ' Start ' to give the program the order to send the emails: ")

# =====================================================================

# The main function assign_Task :

emails = (
    email_list()
)  # extract the dictionary that contains emails.

# emails dictionary contains informations about members
# format : {"email1@gmail.com" : (LastName, FirstName)}


def assign_task():
    Tasks = tasks_list()  # extract the list of tasks
    for email in emails.keys():
        random_task = random.choice(
            Tasks
        )
        email_dict[email] = random_task
        Tasks.remove(random_task)
    for email in email_dict:
        message = str(
            "Subject: Week Project\n"
            + "Hi {} {},\n\n".format(
                emails[email][0], emails[email][1]
            )
            + str_msg
            + email_dict[email]
            + "\n\n\nBook Link : {}".format(book_link)
        )
        print(
            emails[email][0],
            emails[email][1]
            + " \t\tYour Project is : \t\t"
            + email_dict[email],
        )
        smtpObj.sendmail(
            admin_user, email, message
        )


email_dict = {}

# ======================================================================================================

# automate the program to send tasks to members every week up to a year

for i in range(52):
    assign_task()
    time.sleep(7 * 86400)

# Disconnect from the SMTP server
smtpObj.quit()
