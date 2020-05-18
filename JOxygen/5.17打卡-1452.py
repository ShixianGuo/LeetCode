class Solution:
    def peopleIndexes(self, favoriteCompanies: List[List[str]]) -> List[int]:
        n = len(favoriteCompanies)
        ans = []
        for i, fc in enumerate(favoriteCompanies):
            flag = True
            for j , fc2 in enumerate(favoriteCompanies):
                if i != j and set(fc) < set(fc2):
                    flag = False
                    break
            if flag:
                ans.append(i)
        return ans