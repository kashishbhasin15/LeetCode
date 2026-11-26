class Solution(object):
    def canAliceWin(self, n):
        x = 10
        moves = 0

        while n >= x:
            n -= x
            x -= 1
            moves += 1

        return moves % 2 == 1