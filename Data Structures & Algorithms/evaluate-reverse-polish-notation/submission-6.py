class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        op_set = {"*", "+", "-", "/"}
        stack = []

        if len(tokens) == 1 and tokens[0] not in op_set:
            return int(tokens[0])

        if tokens[0] in op_set:
            return

        for t in tokens:
            if t in op_set:
                elem2, elem1 = int(stack.pop()), int(stack.pop())
                if t == "*":
                    stack.append(elem1 * elem2)
                    continue
                elif t == "-":
                    stack.append(elem1 - elem2)
                    continue
                elif t == "/":
                    stack.append(elem1 / elem2)
                    continue
                elif t == "+":
                    stack.append(elem1 + elem2)
                    continue
            stack.append(t)
        return int(stack.pop())
                
        