# this program is used to test the weixin reward

import random


def get_reward_arr1(coin_sum, n):
    det_coin = coin_sum / n
    coin_arr = [det_coin for i in range(n)]
    max_lose_coin = det_coin / 2

    for i in range(n):
        lose_coin = random.randint(0, max_lose_coin)
        win_index = random.randint(0, n - 1)
        coin_arr[i] -= lose_coin
        coin_arr[win_index] += lose_coin

    return coin_arr


def get_reward_arr2(coin_sum, n):
    rand_arr = [random.randint(n / 2, n) for i in range(n)]
    rand_sum = reduce(lambda x, y: x + y, rand_arr)

    coin_arr = [(rand_arr[i] * coin_sum) / rand_sum for i in range(n)]

    return coin_arr


def get_reward_arr3(coin_sum, n, seed, times):
    random.seed(seed)
    rand_num = 0
    rand_sum = 0

    for i in range(n):
        ret = random.randint(n / 2, n)
        rand_sum += ret
        if i == times:
            rand_num = ret

    return (rand_num * coin_sum) / rand_sum


def main():
    arr = get_reward_arr1(200, 10)
    print(arr)

    arr = get_reward_arr2(200, 10)
    print(arr)

    arr = [get_reward_arr3(200, 10, 10, i) for i in range(10)]
    print(arr)


if __name__ == "__main__":
    main()
