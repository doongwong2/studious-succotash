class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        freq = {}
        for i in arr1:
            if i in freq:
                freq[i] += 1

            else:
                freq[i] = 1

        result = []

        for i in arr2:
            if i in freq:
                result.extend([i] * freq[i])
                del freq[i]

        for i in sorted(freq.keys()):
            result.extend([i] * freq[i])

        return result
        
