# this program is used to test the weixin reward

import random


def get_reward_arr(sum_coin, n):
    det_coin = sum_coin / n
    coin_arr = [det_coin for i in range(n)]
    max_lose_coin = det_coin / 2
    for i in range(n):
        lose_coin = random.randint(0, max_lose_coin)
        win_index = random.randint(0, n - 1)
        coin_arr[i] -= lose_coin
        coin_arr[win_index] += lose_coin
    return coin_arr

arr = get_reward_arr(200, 10)
print(arr)