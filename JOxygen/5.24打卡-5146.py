class Solution:
    def isPrefixOfWord(self, sentence: str, searchWord: str) -> int:
        for i, s in enumerate(sentence.split()):
            if s[:len(searchWord)] == searchWord:
                return i+1
        return -1