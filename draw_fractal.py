import turtle

window = turtle.Screen()
window.bgcolor("white")
turtle.title("Check out this fractal!")
turtle.setup(width=.8, height=0.8)

def draw_triangle(some_turtle, edge):
    
    some_turtle.begin_fill() #start coloring
    
    steps = 0                   #draw triangle
    while steps < 3:
        some_turtle.fd(edge)
        some_turtle.right(120)
        steps = steps + 1
        
    some_turtle.end_fill()   #stop coloring


def fractal_triangle(some_turtle, edge_factor):
    edge = edge_factor*10
    if edge_factor > 1:
        fractal_triangle(some_turtle, edge_factor/2)
        some_turtle.fd(edge/2)
        fractal_triangle(some_turtle, edge_factor/2)
        some_turtle.fd(edge/2)
        some_turtle.right(120)
        some_turtle.fd(edge/2)
        fractal_triangle(some_turtle, edge_factor/2)
        some_turtle.bk(edge/2)
        some_turtle.left(120)
        some_turtle.bk(edge)
    else: draw_triangle(some_turtle, edge)


##   -> This assumes that the turtle is finishes a
##      triangle in its starting point and facing its original direction 
## start with larger size
## if edge is bigger than one
#### do for the first half
#### move edge/2
#### do for second hald
#### turn right 120 degrees
#### move edge/2
#### do last triangle - fractal (edge/2)       
#### move back (edge)       
#### turn left 120 degrees
#### move back (edge)   -> takes you to the starting
####                       point of the first fractal part     

tortuga = turtle.Turtle()
tortuga.penup()
tortuga.setpos(-300,300)
tortuga.pendown()
tortuga.color("black", "green")
tortuga.speed(0)

## Setting a higher number leads to more levels of the fractal being composed. Worth playing with!
Fractal_levels = 3

fractal_triangle(tortuga, Fractal_levels)

window.exitonclick()
