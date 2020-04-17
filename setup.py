from setuptools import setup

setup(name='headlessrl',
      version='0.1',
      description='Headless imitation of rocket league for training reinforcement learning bots (Follows OpenAI Gym Environment API)',
      url='http://github.com/ncn6mq/headless-rl',
      author='Nick Newton',
      author_email='ncnewton@gmail.com',
      license='NONE',
      packages=['headlessrl'],
      zip_safe=False,
      install_requires=['gym'])
