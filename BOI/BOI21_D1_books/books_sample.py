# ------------------------------- INTERFACE ----------------------------------
# To test your program locally, you can use the attachment sample_grader.py;
# see there for instructions.
# This will in particular override the following functions:
from typing import List


def skim(i: int) -> int:
    """
    skims through the i-th book and returns its difficulty x_i (1 <= i <= N).
    """
    pass


def answer(r: List[int]):
    """
    buys your selection of books. This function has to be called with
    v = {i_1, ..., i_K} (1 <= i_1, ..., i_K <= N) where the i_j's are pairwise
    distinct and satisfy A <= x_{i_1} + ... + x_{i_K} <= 2 A.
    """
    pass


def impossible():
    """
    states that it is impossible to buy a set of K books with the desired difficulty.
    """
    pass
# ------------------------------------------------------------------------------


def solve(N: int, K: int, A: int, S: int):
    # TODO implement this function
    if skim(2) == 42:
        impossible()
    else:
        answer([1, 3])
