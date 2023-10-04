
# imports
import turtle as t

# Interpret a given command and execute it
def execute_command(command, turtle_object):
    operation = command[:2] # operation code
    if operation == "GT": # goto has a point parameter
        remainder = command[2:].strip() # get remainder
        # the eval function evaluates a string as an expression
        point = eval(remainder) # make a tuple out of the extracted data
        turtle_object.goto(point)
    elif operation == "PU":
        turtle_object.penup()
    elif operation == "PD":
        turtle_object.pendown()

# Process the commands in a command file
def load_command_file(filename):
    command_list = []
    with open(filename) as f:
        for line in f:
            line = line.strip()
            command_list.append(line)
    return command_list
      

# Draw the figure on a 800x800 drawing area
def draw_figure(filename):
    commands = load_command_file(filename)
    t.setup(800,800)
    t.speed(0) # go as fast as possible
    t.hideturtle() # don't animate the turtle
    for command in commands:
        execute_command(command, t)

# main code
# get number of points, and correct out of range values
if __name__ == "__main__":
    filename = input("Command File: ")
    draw_figure(filename)
