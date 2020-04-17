from rl_env import RLEnv

env = RLEnv()
print("Sup")
env.reset()
for _ in range(100):
    env.render()
    env.step(1) # take a random action
env.close()


#
# class Env:
#     init...
#     def render():
#         if self.window is None:
#             self.window = pyglet.window.Window()
#             def update(dt):
#                 print("updating, last update: " + str(dt))
#             pyglet.clock.schedule_interval(update, 1)
#             pyglet.app.run()
#
#         print("if this line runs then success")


# for _ in range(100):
#     env.step()
#     env.render()
