class Solution:
    def minMovesToSeat(self, seats: List[int], students: List[int]) -> int:
        seats = sorted(seats)
        students = sorted(students)
        steps = 0

        for i, j in zip(seats, students):
            if i is not j:
                steps += abs(i - j)
                j = i

        return steps
