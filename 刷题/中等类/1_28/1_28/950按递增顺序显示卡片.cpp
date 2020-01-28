#if 0
class Solution {
public:
	vector<int> deckRevealedIncreasing(vector<int>& deck) {
		vector<int> res(deck.size());
		queue<int> q;
		sort(deck.begin(), deck.end());
		q.push(deck[deck.size() - 1]);
		int temp = 0;
		for (int i = deck.size() - 2; i > 0; --i)
		{
			q.push(deck[i]);
			temp = q.front();
			q.pop();
			q.push(temp);
		}
		q.push(deck[0]);
		for (int i = deck.size() - 1; i >= 0; --i)
		{
			res.push_back(q.front());
			q.pop();
		}
		reverse(res.begin(), res.end());
		return res;
	}
};
#endif

#if 0
class Solution {
public:
	vector<int> deckRevealedIncreasing(vector<int>& deck) {
		vector<int> res(deck.size());
		queue<int> q;
		sort(deck.begin(), deck.end());
		q.push(deck[deck.size() - 1]);
		int temp = 0;
		for (int i = deck.size() - 2; i > 0; --i)
		{
			q.push(deck[i]);
			temp = q.front();
			q.pop();
			q.push(temp);
		}
		q.push(deck[0]);
		for (int i = deck.size() - 1; i >= 0; --i)
		{
			// res.push_back(q.front());
			res[i] = q.front();
			q.pop();
		}
		//reverse(res.begin(),res.end());
		return res;
	}
};
#endif