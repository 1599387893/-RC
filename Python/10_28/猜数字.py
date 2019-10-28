#------------------------------------实现猜数字游戏-----------------------------------
import random
ra = random.randint(0,100)
n = int(input("Please Guess The number :"))
while True:
    if n==ra:
        print("You're Lucky!That's "+str(ra))
        break
    elif n<ra:
        n = int(input("Sorry Guess Bigger :"))
        #continue
    elif n > ra:
        n = int(input("Sorry Guess Smarller:"))
        #continue
    else:
        n = int(input("Excause me ! Please Enter lawful number:"))
        #continue
