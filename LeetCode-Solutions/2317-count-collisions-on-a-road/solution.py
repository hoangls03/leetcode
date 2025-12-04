class Solution:
    def countCollisions(self, directions: str) -> int:
        q = deque()
        ans = 0
        for x in directions:
            if ( x == 'R' ):
                q.append(x)
            if ( x == 'S' ):
                while ( len(q) > 0 and q[-1] == 'R'):
                    q.pop()
                    ans += 1
                q.append(x)
            if ( x == 'L' ):
                if ( len(q) > 0 ):
                    if ( q[-1] == 'R' ):
                        ans += 2
                        q.pop()
                        while ( len(q) > 0 and q[-1] == 'R'):
                            q.pop()
                            ans += 1
                        q.append('S')
                    elif ( q[-1] == 'S' ):
                        ans += 1
        return ans

