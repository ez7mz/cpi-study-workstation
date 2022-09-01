'''
    Author : MESRAR Hamza - @ez7m.z - 🦂
    💬 : mesrarhamza48@gmail.com
'''

import time
import smtplib
import os
from getpass import getpass
from sys import stdout
import random


def header():
    print("\n\n")
    print("\t\t\t\tWelcome!\n")
    print("\t\t\tFill the information's bellow please :\n")


def info_verf():
    pin = "@ez7mz"
    header()
    x = str(input("\t\t\t\t email :  "))
    y = getpass("\t\t\t\t password :  ")
    z = getpass("\t\t\t\t Pin to continue :  ")
    while z != pin:
        print("\t\t\t\tIncorrect PIN ! Try again...")
        time.sleep(1)
        os.system("CLS")
        header()
        x = str(input("\t\t\t\t email :  "))
        y = getpass("\t\t\t\t password :  ")
        z = getpass("\t\t\t\t Pin to continue :  ")
    else:
        print("login has been successfully!")
        print("\tLoading", end="")

    for i in range(0, 15):
        print(". ", end="")
        stdout.flush()
        if i >= 5:
            time.sleep(0.2)
        else:
            time.sleep(0.5)

    os.system("CLS")
    return x, y


def ver_server_statu(a):
    while True:
        if a == 503:
            print("login successfully to the server!")
            break


# add emails here :
def email_list():
    L = {
        "mesrarhamza48@gmail.com": ("Mesrar", "Hamza"),
        # "emailexample@gmail.com": ("LastName", "FirstName"),
    }
    return L


# Add Tasks here :
def tasks_list():
    L = [
        "CH7  : ' Strong Password Detection '",
        "CH8  : ' Regex Search '",
        "CH9  : ' Deleting Unneeded Files '",
        "CH10 : ' Debugging Coin Toss '",
        "CH11 : ' Link Verification '",
        "CH12 : ' Text Files to Spread Sheet '",
        "CH13 : ' PDF Paranoia '",
        "CH14 : ' Excel to CSV Converter '",
        "CH15 : ' Scheduled Web Comic Downloader '",
        "CH16 : ' Auto Unsubscribed '",
        "CH17 : ' Custom Seating Cards '",
        "CH18 : ' Game-Playing Bot Tutorial '",
    ]
    return L
