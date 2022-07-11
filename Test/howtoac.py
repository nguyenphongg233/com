import turtle
import math



def prepare():
  t= turtle.Turtle()
  t.speed(0.5)
  t.color("red")

return;


def doit():

a = 20
for n in range (5) :
    a += 10
    for i in range (5) :
        for i in range (5) :
            t.forward(a)
            t.right(72)
            t.right(360/5)

return;


prepare()
doit()