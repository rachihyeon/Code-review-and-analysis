from z3 import *
import time

def queens(n):
    Q = [Int('Q_%i' % (i + 1)) for i in range(n)]

    val_c  = [And(1 <= Q[i], Q[i] <= n) for i in range(n)]
    col_c  = [Distinct(Q)]
    diag_c = [If(i == j, True, And(Q[i] - Q[j] != i - j, Q[i] - Q[j] != j - i)) for i in range(n) for j in range(i)]

    sol = Solver()
    sol.add(val_c + col_c + diag_c)

    num_solutions = 0

    while sol.check() == sat:
        mod = sol.model()
        ss = [mod.evaluate(Q[i]) for i in range(n)]
        # print(ss)
        num_solutions += 1
        sol.add(Or([Q[i] != ss[i] for i in range(n)]))

    # print("num_solutions:", num_solutions)

n = int(input("N : "))
total = 0.0

for i in range(10):
    start = time.time()
    queens(n)
    end = time.time()
    total += end - start

print("10회 실행 평균 시간 : ", total/10)


