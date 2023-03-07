from typing import List

class Solution:
    def braceExpansion(self, expression: str) -> List[str]:
        def dfs(exp):
            j = exp.find('}')
            if j == -1:
                s.add(exp)
                return
            i = exp.rfind('{', 0, j - 1)
            a, c = exp[:i], exp[j + 1:]
            for b in exp[i + 1: j].split(','):
                dfs(a + b + c)

        s = set()
        dfs(expression)
        return sorted(s)

    def braceExpansionII(self, expression: str) -> List[str]:
        expression = self.downstream(expression)
        print(expression)
        while expression.count(")") > 1:
            first_back = expression.index(")")
            pair_front = 0
            for i in range(first_back, -1, -1):
                if expression[i] == "(" :
                    pair_front = i
                    break
            if expression[first_back+1] is not ",":
                # 乘法
                block1 = expression[pair_front+1:first_back].split(",")
                if expression[first_back+1] is "(":
                    back_point = expression.index(")", first_back+1)
                    block2 = expression[first_back+2:back_point].split(",")
                    tmp = []
                    for ch in block1:
                        for sh in block2:
                            tmp.append(ch+sh)
                else:
                    back_point = -1
                    if expression.count(",", first_back):
                        back_point = expression.index(",", first_back)
                    block2 = expression[first_back+1:back_point]
                    tmp = [i+block2 for i in block1]
                expression = expression[:pair_front+1] + ",".join(tmp) + expression[back_point:]
            elif expression[first_back+1] is ",":
                expression = expression[:pair_front] + expression[pair_front+1:first_back] + expression[first_back+1:]
        print(expression)


        multi = []
        tmp = []
        last_back = 0
        for i in range(len(expression)):
            if expression[i] == ")":
                cut = expression[last_back:i]
                cut = cut.replace("(", "")
                tmp = cut.split(",")
                multi.append(tmp)
                last_back = i+1
        if expression[-1] is not ")":
            cut = expression[last_back:]
            cut = cut.replace("(", "")
            tmp = cut.split(",")
            multi.append(tmp)

        # print(multi)
        result = multi[0]
        for i in range(len(multi)-1):
            result_new = []
            for ch in multi[1+i]:
                for sh in result:
                    result_new.append(sh+ch)
            result = result_new
        # print(result)
        result = list(set(result))
        result.sort()
        return result
        # print()

    def downstream(self, expression: str) -> str:
        while expression.count("}") > 0:
            print(expression)
            first_back = expression.index("}")
            pair_front = 0
            expand = False
            for i in range(first_back, -1, -1):
                if expression[i] == "{" and pair_front is not 0:
                    i += 1
                    break
                if expression[i] == "{":
                    pair_front = i
                if expression[i] == "," and pair_front is not 0:
                    i += 1
                    break
                if expression[i] == ")" and pair_front is not 0:
                    i += 1
                    break
            if first_back != len(expression)-1 and expression[first_back+1] in [",", "}"]:
                expand = True
            if i > 1 and expression[i-1] == ")":
                expand = False

            substr = self.simplify(expression[i:first_back+1], expand=expand)
            expression = expression[:i] + substr + expression[first_back+1:]
        return expression

    
    def simplify(self, expression: str, expand: bool) -> str:
        """
            abc{a, b, c}
        """
        
        result = ""
        print("simplify", expression)
        if expression[0] == "{":
            result = expression[1:-1]
        else:
            divide = expression.index("{")
            block1 = expression[0:divide]
            if "(" not in expression[divide+1:-1]:
                block2 = expression[divide+1:-1].split(",")
            for j in block2:
                result += block1+j+","
            result = result[:-1]
        
        if not expand:
            result = "(" + result + ")"
        print("get", result)
        return result




if __name__ == "__main__":
    # expression = "{a{x,ia,o}w,{n,{g,{u,o}},{a,{x,ia,o},w}},er}"
    # expression = "{a,{x,ia,o},w}er{n,{g,{u,o}},{a,{x,ia,o},w}}"
    # expression = "{{{c,g},{h,j},l}{a,{x,ia,o},w}{x,ia,o},{x,ia,o},a}"
    # expression = "{a,b}{c,{d,e}}"
    # expression = "{{a,z},a{b,c},{ab,z}}"
    # expression = "{a,b}c{d,e}f"
    # expression = "{a,b}{c,d{e,{f,g}}}"
    # expression = "a{b,c}{d,e}f{g,h}"
    expression = "n{{c,g},{h,j},l}a{{a,{x,ia,o},w},er,a{x,ia,o}w}n"
    a = Solution()
    print(a.braceExpansion(expression))
