import pyglet
from pyglet.gl import *
import time


width = 500
height = 500

window = pyglet.window.Window(width=width, height=height)

for i in range(100):
    #pyglet.clock.tick()
    #window.switch_to()
    window.dispatch_events()
    window.dispatch_event('on_close')
    window.clear()
    glBegin(GL_POLYGON)
    glVertex3f(0+i,0+i,0)
    glVertex3f(100+i,100+i,0)
    glVertex3f(100+i,0+i,0)
    glEnd()
    window.flip()
    time.sleep(.1)

window.close()
