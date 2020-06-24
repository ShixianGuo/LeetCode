class Solution {
public:
	bool connect(const string& word1,const string &word2)//判断两个单词是否仅一个字母不同
	{
		int dif=0; //不同的字母数量
		for(int i=0;i<word1.length();i++)
		{
			if(word1[i]!=word2[i]) 
				dif++;
			if(dif>1)
				return false;
		}
		return dif==1;
	 } 
	//构建图,graph必须为引用 
	void construct_graph(string &beginWord,vector<string> &wordList,unordered_map<string,vector<string> > &graph)
	{
		wordList.push_back(beginWord);
		for(int i=0;i<wordList.size();i++)
		for(int j=i+1;j<wordList.size();j++)//避免重复
		{
			if(connect(wordList[i],wordList[j])==true)
			{
				graph[wordList[i]].push_back(wordList[j]);
				graph[wordList[j]].push_back(wordList[i]);
			}
		} 	
	} 
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
    	unordered_map<string,vector<string> > graph;
    	construct_graph(beginWord,wordList,graph);
        queue<string> Q;
        unordered_set<string> visit;//记录已经访问过的元素
		Q.push(beginWord); 
		visit.insert(beginWord);
		int result=1;
		while(!Q.empty())
		{
			int size=Q.size();
			for(int i=0;i<size;i++) //每一次循环代表宽度增1 
			{
				string tmp=Q.front();
				Q.pop();
                visit.insert(tmp);
				vector<string> neighbors=graph[tmp]; //邻居们
				for(int i=0;i<neighbors.size();i++)
				{
					if(visit.find(neighbors[i])==visit.end())  //还没加入 
					{
						Q.push(neighbors[i]);
						visit.insert(neighbors[i]);
					}
                    if(neighbors[i]==endWord) return result+1;
				 }			
			} 
            result++;  //遍历一层则+1		
		} 
		return 0;
		 
    }
};