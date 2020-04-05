# To add a new cell, type '# %%'
# To add a new markdown cell, type '# %% [markdown]'
# %%
import numpy as np
from numpy import sin, cos, tan, pi, random, sqrt
import matplotlib.pyplot as plt

def toExact(num):
    '''
    Find exact value in the form sqrt(a)*b/c
    '''
    bound = range(-30, 30)
    for numerator in bound:
        for denominator in bound:
            for root in bound:
                if abs(numerator * sqrt(root)/ denominator - num) < 1e-12:
                    if sqrt(root) - int(sqrt(root)) == 0:
                        numerator *= int(sqrt(root))
                        root = 0
                    gcd = np.gcd(numerator, denominator)
                    numerator //= gcd
                    denominator //= gcd
                    if numerator < 0 and denominator < 0:
                        return (-numerator, -denominator, root)
                    return (numerator, denominator, root)
    return None

def printExact(num, prompt):
    if (num != None):
        print(prompt + " =", 
            num[0] if num[0] != 1 else '', 
            'sqrt({})'.format(num[2]) if num[2] != 0 else '',
            '/{}'.format(num[1]) if num[1] != 1 else '')
    else:
        print(prompt + ' = undefined')


# %%
a = -11
b = 4
print(a, '*', chr(960), '/', b, '\n')
angle = a/b*pi
sine = toExact(sin(angle))
cosine = toExact(cos(angle))
tang = toExact(tan(angle))

# if (sine != None):
printExact(sine, "y (sin)")
printExact(cosine, "x (cos)")
printExact(tang, "(tan)")
print()

theta = np.linspace(0, 2*pi, 2000)
circleX = cos(theta)
circleY = sin(theta)
lineX = cos(angle)
lineY = sin(angle)
plt.figure(figsize=(5,5))
plt.grid(linestyle='--')
plt.xlim(-1.25, 1.25)
plt.ylim(-1.25, 1.25)

plt.plot([-100, 100], [0, 0], linestyle='-', color='black', alpha=0.5, linewidth=4)
plt.plot([0, 0], [-100, 100], linestyle='-', color='black', alpha=0.5, linewidth=4)

plt.plot(circleX, circleY)
plt.plot([0, lineX], [0, lineY])
plt.plot([lineX, lineX], [0, lineY], linestyle='--')
plt.plot([0, lineX], [lineY, lineY], linestyle='--')
plt.show()



# %%
