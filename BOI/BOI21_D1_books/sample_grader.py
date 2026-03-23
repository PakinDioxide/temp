"""
SAMPLE GRADER for task BOOKS

USAGE:
place together with your solution in the same directory, then:
python3 sample_grader.py <solutionFile>
e.g.:
python3 sample_grader.py books.py

INPUT/OUTPUT:
The sample grader expects on standard input two lines. The first line should
contain the four integers N, K, A and S. The second line should contain a list
of N integers, the sequence of difficulties x_1 x_2 ... x_N which has to be
strictly increasing. Then, the grader writes to standard output a protocol of
all grader functions called by your program.
At the end, the grader prints your verdict.
"""

import sys
from typing import List


def result(msg):
    print(msg, file=sys.stderr)
    sys.exit(0)


N, K, S, sUsed, A = 0, 0, 0, 0, 0
seq = []


def impossible():
    result(f"Impossible (not checked): {sUsed} book(s) skimmed")


def skim(pos: int) -> int:
    global sUsed
    print(f"skim({pos}):", end="")
    if pos < 1 or pos > N:
        result("Invalid skim")
    print(f" {seq[pos]}")
    sUsed += 1
    if sUsed > S:
        result("Out of books to skim")
    return seq[pos]


def answer(v: List[int]):
    print(f"answer({{{', '.join(map(str, v))}}})", flush=True)

    if len(v) != K:
        result("Invalid answer")
    sum = 0
    for x in v:
        if x < 1 or x > N:
            result("Invalid answer")
        sum += seq[x]
    if sum < A or 2*A < sum:
        result("Wrong answer")
    result(f"Correct: {sUsed} book(s) skimmed")


if __name__ == "__main__":
    #import task as solution
    filename = sys.argv[1] if len(sys.argv) > 1 else "books.py"
    if filename.endswith(".py"):
        filename = filename[:-3]
    try:
        solution = __import__(filename)
    except Exception as e:
        print("USAGE: python3 sample_grader.py <solutionFile>\nError:",
              e, file=sys.stderr)
        sys.exit(1)
    solution.impossible = impossible
    solution.skim = skim
    solution.answer = answer

    N, K, A, S = list(map(int, input().split()))

    seq = list(map(int, input().split()))
    seq.insert(0, 0)
    for i in range(2, N+1):
        if seq[i] <= seq[i-1]:
            result("Invalid input")

    solution.solve(N, K, A, S)
    result("No answer")
