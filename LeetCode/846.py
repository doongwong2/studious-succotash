class Solution:
    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        if len(hand) % groupSize is not 0:
            return False

        hand.sort()
        for i in range(len(hand)):
            if hand[i] >= 0:
                next_val = hand[i] + 1
                hand[i] = -1
                count = 1
                i += 1
                
                while i < len(hand) and count < groupSize:
                    if hand[i] == next_val:
                        next_val = hand[i] + 1
                        hand[i] = -1
                        count += 1
                    i += 1
                
                if not count == groupSize:
                    return False


        return True
        
        
