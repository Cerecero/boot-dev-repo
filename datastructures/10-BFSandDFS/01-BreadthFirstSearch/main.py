class Graph:
    def breadth_first_search(self, v):
        visited = []
        to_visit = [v]

        while to_visit:
            vertex = to_visit.pop(0)
            if vertex not in visited:
                visited.append(vertex)

                for neighbor in sorted(self.graph.get(vertex, [])):
                    if neighbor not in visited and neighbor not in to_visit:
                        to_visit.append(neighbor)
        
        return visited            

    # don't touch below this line

    def __init__(self):
        self.graph = {}

    def add_edge(self, u, v):
        if u in self.graph.keys():
            self.graph[u].add(v)
        else:
            self.graph[u] = set([v])
        if v in self.graph.keys():
            self.graph[v].add(u)
        else:
            self.graph[v] = set([u])

    def __repr__(self):
        result = ""
        for key in self.graph.keys():
            result += f"Vertex: '{key}'\n"
            for v in sorted(self.graph[key]):
                result += f"has an edge leading to --> {v} \n"
        return result
