import collections

class Queue:
    def __init__(self):
        self.elements = collections.deque()

    def empty(self):
        return len(self.elements) == 0

    def put(self, x):
        self.elements.append(x)

    def get(self):
        return self.elements.popleft()


class SquareGrid:
    def __init__(self, width, height):
        self.width = width
        self.height = height
        self.walls = {}

    def in_bounds(self, id):
        (x, y) = id
        return 0 <= x < self.width and 0 <= y < self.height

    def passable(self, id):
        return id not in self.walls

    def neighbors(self, id):
        (x, y) = id
        results = [(x + 1, y), (x, y -1), (x - 1, y), (x, y + 1)]
        results = filter(self.in_bounds, results)
        results = filter(self.passable, results)
        return results


def draw_grid(grid, specil_grid, dot):
    for i in range(grid.width):
        str = ' '
        for j in range(grid.height):
            if (i, j) in grid.walls:
                node = '# '
            elif (i, j) in specil_grid:
                node = dot + ' '
            else:
                node = '. '
            str = str + node
        print str


g = SquareGrid(20, 20)
g.walls = {(13, 10), (11, 8), (13, 9), (11, 9), (12, 9)}

draw_grid(g, g.neighbors((0, 0)), '*')

start = (0, 0)

