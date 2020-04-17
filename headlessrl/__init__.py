from gym.envs.registration import register

register(
    id='headless-rl-v0',
    entry_point='headlessrl.envs:RLEnv',
)
