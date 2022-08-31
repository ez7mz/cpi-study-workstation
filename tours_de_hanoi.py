'''
    Author : MESRAR Hamza - @ez7m.z - 🦂
    💬 : mesrarhamza48@gmail.com
'''

# First call of the function for the second move : on move the n-1 discs from B to C
# Second call of the function for the First move : on move the n-1 discs from A to B

def hanoi(n, debut="A", inter="B", fin="C"):
    if n > 0:
        hanoi(n - 1, debut, fin, inter)
        print("Deplace ", debut, "sur", fin)
        hanoi(n - 1, inter, debut, fin)


print(hanoi(4))
