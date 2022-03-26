import turtle
import time

def draw(A):
    turtle.reset()
    A=list(map(int,input().split()))
    turtle.up()
    turtle.goto(A[0],A[1])
    turtle.down()
    for i in range(1,4):
        turtle.goto(A[2*i],A[2*i+1])
    time.sleep(1)

for x in range(100):
    draw()