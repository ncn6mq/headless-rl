import gym
from rl import rendering
from gym import error, spaces, utils
from gym.utils import seeding
import time
import pyglet
from pyglet.gl import *
import glm

RAD2DEG = 57.29577951308232

class RLEnv(gym.Env):
    metadata = {'render.modes': ['human']}

    def __init__(self):
        self.isRendering = False
        self.time = 0
        self.rot_y = 0
        self.rot_z = 0
        self.scale = 1
        self.window = None
        self.dOffset = 0
        self.car = 0
        print("I was made")

    def step(self, action):
        #self.rot_y += 9
        #self.rot_z += 9
        time.sleep(.1)

    def reset(self):
        pass

    def render(self, mode='human', close=False, width=500, height=500):
        if self.window is None:
            self.window = pyglet.window.Window(width, height)
            @self.window.event
            def on_close():
                self.window.close()

            @self.window.event
            def on_key_press(key, mod):
                if key == pyglet.window.key.D:
                    self.rot_z += 5
                if key == pyglet.window.key.A:
                    self.rot_z -= 5

            self.car = box_Vertices(100, 200, 20)

            glLoad


        pyglet.clock.tick()
        self.window.clear()
        self.window.dispatch_events()

        vertex_list = pyglet.graphics.vertex_list(4,
            ('v3i', (0, 0, 0, 200, 0, 0, 200, 200, 0, 0, 200, 0))#,
            #('c3B', (0, 0, 255))
        )

        vertex_list2 = pyglet.graphics.vertex_list(4,
            ('v3i', (0, 0, 0, 200, 0, 0, 200, 200, 0, 0, 200, 0)),
            ('c3B', (0, 0, 255, 0, 255, 0, 255, 0, 0, 0, 255, 255))
        )

        #glRotatef(45, 0, 0, 1)
        #glTranslatef(50, 100, 0)
        #glRotatef(2, 0, 1, 0 )
        #glTranslatef(-50, -100, 0)
        rotateOnY(self.rot_z, [50, 100, 0])
        self.car.draw(GL_QUADS)
        #rotateOff()

        self.window.flip()




    def close(self):
        print(self.time)
        self.window.close()

def rotateOnY(degs, mid):
    glPushMatrix()
    glTranslatef(mid[0], mid[1], mid[2])
    glRotatef(degs, 0, 1, 0)
    glTranslatef(-mid[0], -mid[1], mid[2])


def rotateOff():
    glPopMatrix()

# def car(xLen, yLen, zLen):
#
#     # glMatrixMode(GL_PROJECTION)
#     # glLoadIdentity()
#     # gluPerspective(400, 400, 0.1, 400)
#     #
#     # glMatrixMode(GL_MODELVIEW)
#     # glLoadIdentity()
#     #
#     # glTranslatef(0, 0, -30)
#     #glRotatef(rot_y, 0, 1, 0)
#     #glRotatef(rot_z, 0, 0, 1)
#
#     glBegin(GL_QUADS)
#
#     #bottom
#
#     glColor3f(0,0,1)
#
#     glVertex3d(0, yLen, 0);
#     glVertex3d(xLen, yLen, 0);
#     glVertex3d(xLen, 0, 0);
#     glVertex3d(0, 0, 0);
#
#     #left side wall
#     # glColor3f(0,1,0)
#     # glVertex3d(0, 0, 0);
#     # glVertex3d(0, 0, zLen);
#     # glVertex3d(0, yLen, zLen);
#     # glVertex3d(0, yLen, 0);
#     #
#     # #top side wall
#     # glColor3f(1,0,0)
#     # glVertex3d(0, yLen, 0);
#     # glVertex3d(0, yLen, zLen);
#     # glVertex3d(xLen, yLen, zLen);
#     # glVertex3d(xLen, yLen, 0);
#
#     # #right side wall
#     # glVertex3d(xBL + xLen, yBL + yLen, zBL);
#     # glVertex3d(xBL + xLen, yBL + yLen, zBL + zLen);
#     # glVertex3d(xBL + xLen, yBL, zBL + zLen);
#     # glVertex3d(xBL + xLen, yBL, zBL);
#     #
#     # #bottom side wall
#     # glVertex3d(xBL + xLen, yBL, zBL);
#     # glVertex3d(xBL + xLen, yBL, zBL + zLen);
#     # glVertex3d(xBL, yBL, zBL + zLen);
#     # glVertex3d(xBL, yBL, zBL);
#     #
#     # #top
#     # glVertex3d(xBL, yBL, zBL + zLen);
#     # glVertex3d(xBL, yLen + yBL, zBL + zLen);
#     # glVertex3d(xLen + xBL, yLen + yBL, zBL + zLen);
#     # glVertex3d(xLen + xBL, yBL, zBL + zLen);
#
#     glEnd()


def box_Vertices(xLen, yLen, zLen):
    vertices = (0, 0, 0, # 0 bottom left below
      xLen, 0, 0,        # 1 bottom right below
      xLen, yLen, 0,     # 2 top right below
      0, yLen, 0,        # 3 top left below
      0, 0, zLen,        # 4 bottom left above
      xLen, 0, zLen,     # 5 bottom right above
      xLen, yLen, zLen,  # 6 top right above
      0, yLen, zLen)     # 7 top left above

    indices = [0, 1, 2, 3,
      0, 4, 7, 3,
      3, 7, 6, 2,
      2, 6, 5, 1,
      1, 5, 4, 0,
      4, 5, 6, 7]

    box = pyglet.graphics.vertex_list_indexed(8,
        indices,
        ('v3f', vertices)
    )
    return box
