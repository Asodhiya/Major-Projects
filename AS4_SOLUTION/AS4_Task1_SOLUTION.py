"""
AS4 Task 1:  All-Connected Graph via the Turtle

Create an all-connected graph of N points, where 3 <= N <= 64

Author:  C. Vessey, UPEI SMCS
Date:  24-NOV-2022
"""

# imports
import math
import turtle as t

# Create the function described in the instructions to change
# from Polar to Cartesian coordinates

def polar_to_cartesian(r,theta):
    x = int(r*math.cos(theta))
    y = int(r*math.sin(theta))
    return x,y

# Create a list of points, starting at (0,r) polar, which will be used in the graph.
# Each point should be a tuple, as the points won't change once calculated.
def make_point_list(num_points,radius):
    angle_increment = 2 * math.pi / num_points
    current_angle = math.pi / 2
    point_list = []
    for i in range(num_points):
        x,y = polar_to_cartesian(radius, current_angle)
        point_list.append((x,y)) # append the point as a tuple of ints
        current_angle += angle_increment

    return point_list

# Draw the figure on a 800x800 drawing area, with n points and radius r.
def draw_figure(n,r):
    with open(f"ACG_{n}.txt",'w') as f:
        point_list = make_point_list(n,r)
        t.setup(800,800)
        t.speed(0) # go as fast as possible
        t.hideturtle() # don't animate the turtle

        for i in range(len(point_list)-1): # for all points except the last
            for j in range(i+1,len(point_list)): # for all points after i
                t.penup() # don't draw
                f.write("PU\n") # write the equivalent LOGO command to file
                t.goto(point_list[i])
                f.write(f"GT {point_list[i]}\n")
                t.pendown() # draw
                f.write("PD\n")
                t.goto(point_list[j])
                f.write(f"GT {point_list[j]}\n")

# main code
# get number of points, and correct out of range values
if __name__ == "__main__":
    n_points = int(input("Number of points (3 to 31): "))

    if n_points < 3:
        n_points = 3
    elif n_points > 31:
        n_points = 31

    # set radius at 300
    radius = 300

    draw_figure(n_points, radius)
