class Solution:
    def findMaximumNumber_iter(self, k: int, x: int) -> int:
        remain_k = k
        current = 1
        while True:
            char = list(reversed(bin(current)[2:]))
            score = sum([1 if i == '1' else 0 for i in char[x-1:len(char):x]])
            remain_k -= score

            # print(current, score)

            # if remain_k == 0:
            #     return current
            if remain_k < 0:
                return current - 1
            current += 1

    def findMaximumNumber_DP(self, k: int, x: int) -> int:
        dp = [0]
        current_max = 0
        while True:
            current_max += 1
            last_num = dp[-1]

            if current_max % x == 0:
                current_num = 2*last_num + 2**(current_max-1)
            else:
                current_num = 2*last_num
            
            if current_num > k:
                break
            dp.append(current_num)

        remain = k - dp[-1]
        start = 2**(current_max-1)
        for current in range(start, start*2):
            char = list(reversed(bin(current)[2:]))
            score = sum([1 if i == '1' else 0 for i in char[x-1:len(char):x]])
            remain -= score

            # print(current, score)

            # if remain_k == 0:
            #     return current
            if remain < 0:
                return current - 1

if __name__ == "__main__":
    k = 3278539330613
    x = 5
    ans = Solution().findMaximumNumber_DP(k, x)
    print(ans)