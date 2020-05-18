class Solution:
    def arrangeWords(self, text: str) -> str:
        #text = text.lower()
        strList = sorted(text.lower().split(), key=lambda x:len(x))
        ans = ' '.join(strList)
        return ans.capitalize()
            