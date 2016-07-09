def loop_size(node):
    def find(node, dep):
        setattr(node, 'dfn', dep)
        if hasattr(node.next, 'dfn'):
            return node.dfn - node.next.dfn + 1
        return find(node.next, dep + 1)
    return find(node, 1)