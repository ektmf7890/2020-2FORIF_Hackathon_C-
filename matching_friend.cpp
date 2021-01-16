#include<iostream>
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<cstring>
#include<string>
using namespace std;

class StableRoommates
{
	void deleteFromTable(string x, string y);
	void deleteFrom(int st, int en, string x);
public:
	//Vertex stores all the names, Table stores the preference table, and Rank store the rank of person b in a's Preference List
	set<string> Vertex;
	map<string, vector<string> > Table;
	map< pair <string, string>, long long> Rank;
	set<pair<string, string>> mates;
	map<pair<string, string>, bool> Exist;

	void phase1();
	void phase2();
};

inline void StableRoommates::deleteFromTable(string x, string y)
{
	Table[x][Rank[make_pair(x, y)] - 1] = "";
	Exist[make_pair(x, y)] = false;
}
void StableRoommates::deleteFrom(int st, int end, string y) {
	for (int i = st; i < end; i++)
	{
		if (Table[y][i] != "")   //if has not been deleted
		{
			string z = Table[y][i];
			if (Exist[make_pair(z, y)]) deleteFromTable(z, y);
			deleteFromTable(y, z);
		}
	}
}
void StableRoommates::phase1()
{

}
void StableRoommates::phase2()
{

}


map<int, string> dict;
int N;
vector<int>* V;

int main()
{
	/*dict[0] = "Charlie";
	dict[1] = "Peter";
	dict[2] = "Elise";
	dict[3] = "Paul";
	dict[4] = "Kelly";
	dict[5] = "Sam";

	N = dict.size();
	V = new vector<int>[N];

	V[0].push_back(1);
	V[0].push_back(3);
	V[0].push_back(5);
	V[0].push_back(4);
	V[0].push_back(2);

	V[1].push_back(4);
	V[1].push_back(2);
	V[1].push_back(5);
	V[1].push_back(3);
	V[1].push_back(0);

	V[2].push_back(1);
	V[2].push_back(5);
	V[2].push_back(4);
	V[2].push_back(0);
	V[2].push_back(3);

	V[3].push_back(2);
	V[3].push_back(0);
	V[3].push_back(5);
	V[3].push_back(1);
	V[3].push_back(4);

	V[4].push_back(1);
	V[4].push_back(0);
	V[4].push_back(5);
	V[4].push_back(2);
	V[4].push_back(3);

	V[5].push_back(0);
	V[5].push_back(3);
	V[5].push_back(4);
	V[5].push_back(2);
	V[5].push_back(1);

	bool received[6]{0, };
	int proposer[6]{ -1, -1, -1, -1, -1, -1};
	stack<int> fr;

	for (int i = N - 1; i >= 0; i--)
		fr.push(i);*/

	string Table_keys[] = { "윤다영", "강미주", "고병찬", "이창모" ,"이성우",
	"김동현", "예링","김정은", "민경환", "한가희", "강희원", "임규민",
	"김은호", "김민기","오지영","이혜림", "김나영", "양성민", "이수빈",
	"김서영", "김은채", "이하늘"};

	StableRoommates S;
	S.Table["윤다영"] = vector <string>{ "오지영", "이수빈", "예링", "이성우", "한가희", "양성민", "김정은", "고병찬", "임규민", "이창모", "이하늘", "김민기", "강희원", "이혜림", "강미주", "민경환", "김은호", "김서영", "김동현", "김나영", "김은채" };
	S.Table["강미주"] = vector <string>{ "김동현", "이수빈", "임규민", "이혜림", "이성우", "김정은", "김은호", "강희원", "양성민", "이창모", "오지영", "김나영", "김서영", "이하늘", "예링", "한가희", "윤다영", "김은채", "김민기", "민경환", "고병찬" };
	S.Table["고병찬"] = vector <string>{ "이성우", "예링", "오지영", "양성민", "윤다영", "김민기", "이수빈", "이창모", "강희원", "김정은", "한가희", "임규민", "이혜림", "김서영", "민경환", "강미주", "이하늘", "김나영", "김동현", "김은호", "김은채" };
	S.Table["이창모"] = vector <string>{ "양성민", "이수빈", "예링", "임규민", "오지영", "이성우", "김정은", "민경환", "윤다영", "이하늘", "한가희", "고병찬", "강미주", "강희원", "김민기", "김동현", "이혜림", "김은호", "김나영", "김은채", "김서영" };
	S.Table["이성우"] = vector <string>{ "고병찬", "예링", "이수빈", "오지영", "김민기", "양성민", "윤다영", "이창모", "한가희", "임규민", "강희원", "김정은", "이혜림", "강미주", "민경환", "이하늘", "김나영", "김서영", "김동현", "김은호", "김은채" };
	S.Table["김동현"] = vector <string>{ "이혜림", "강미주", "김정은", "임규민", "이수빈", "김은호", "김은채", "강희원", "김나영", "양성민", "이창모", "이성우", "이하늘", "한가희", "윤다영", "오지영", "예링", "고병찬", "김민기", "민경환", "김서영" };
	S.Table["예링"] = vector <string>{ "오지영", "이성우", "윤다영", "고병찬", "이수빈", "이창모", "양성민", "강희원", "한가희", "김민기", "민경환", "김정은", "임규민", "강미주", "이하늘", "이혜림", "김은호", "김동현", "김나영", "김서영", "김은채" };
	S.Table["김정은"] = vector <string>{ "강희원", "이혜림", "오지영", "김동현", "이수빈", "윤다영", "예링", "이성우", "김은호", "강미주", "이창모", "한가희", "양성민", "김나영", "김은채", "고병찬", "이하늘", "임규민", "김서영", "민경환", "김민기" };
	S.Table["민경환"] = vector <string>{ "김민기", "이하늘", "예링", "오지영", "이창모", "이성우", "이수빈", "김은호", "김나영", "한가희", "강희원", "양성민", "임규민", "윤다영", "고병찬", "김정은", "김서영", "강미주", "김은채", "김동현", "이혜림" };
	S.Table["한가희"] = vector <string>{ "이수빈", "오지영", "윤다영", "이성우", "예링", "강희원", "김정은", "이창모", "민경환", "양성민", "김민기", "임규민", "고병찬", "강미주", "이하늘", "김동현", "이혜림", "김은호", "김서영", "김나영", "김은채" };
	S.Table["강희원"] = vector <string>{ "김정은", "오지영", "예링", "이혜림", "이성우", "김동현", "이수빈", "한가희", "김은호", "강미주", "김나영", "윤다영", "이창모", "고병찬", "민경환", "양성민", "김은채", "임규민", "김민기", "이하늘", "김서영" };
	S.Table["임규민"] = vector <string>{ "양성민", "이수빈", "이창모", "강미주", "김동현", "이성우", "윤다영", "이하늘", "예링", "오지영", "이혜림", "김민기", "한가희", "고병찬", "김은호", "김정은", "민경환", "강희원", "김나영", "김은채", "김서영" };
	S.Table["김은호"] = vector <string>{ "김나영", "김은채", "이하늘", "김민기", "김동현", "이혜림", "김정은", "강미주", "이수빈", "민경환", "강희원", "김서영", "임규민", "이성우", "오지영", "양성민", "윤다영", "예링", "이창모", "한가희", "고병찬" };
	S.Table["김민기"] = vector <string>{ "민경환", "이성우", "이하늘", "김나영", "예링", "이수빈", "김은호", "오지영", "양성민", "고병찬", "김서영", "윤다영", "이창모", "한가희", "임규민", "강희원", "강미주", "김정은", "김은채", "이혜림", "김동현" };
	S.Table["오지영"] = vector <string>{ "예링", "윤다영", "이성우", "이수빈", "한가희", "이창모", "강희원", "김정은", "양성민", "고병찬", "민경환", "김민기", "임규민", "이하늘", "강미주", "이혜림", "김은호", "김동현", "김서영", "김나영", "김은채" };
	S.Table["이혜림"] = vector <string>{ "김동현", "김정은", "강미주", "김나영", "강희원", "이수빈", "김은호", "이성우", "김은채", "임규민", "양성민", "고병찬", "윤다영", "김서영", "이하늘", "이창모", "예링", "오지영", "한가희", "김민기", "민경환" };
	S.Table["김나영"] = vector <string>{ "김은호", "김민기", "김은채", "이혜림", "김동현", "민경환", "강희원", "김서영", "김정은", "이하늘", "강미주", "이성우", "이수빈", "임규민", "양성민", "고병찬", "예링", "이창모", "오지영", "한가희", "윤다영" };
	S.Table["양성민"] = vector <string>{ "임규민", "이창모", "이성우", "이수빈", "예링", "윤다영", "오지영", "고병찬", "김민기", "강미주", "김정은", "이하늘", "민경환", "이혜림", "한가희", "강희원", "김동현", "김나영", "김은호", "김은채", "김서영" };
	S.Table["이수빈"] = vector <string>{ "이성우", "한가희", "임규민", "윤다영", "오지영", "양성민", "강미주", "예링", "이창모", "이하늘", "김정은", "김동현", "김민기", "이혜림", "강희원", "고병찬", "민경환", "김은호", "김나영", "김서영", "김은채" };
	S.Table["김서영"] = vector <string>{ "김민기", "이하늘", "김나영", "강미주", "김은호", "이성우", "이혜림", "김은채", "고병찬", "김정은", "민경환", "이수빈", "강희원", "윤다영", "예링", "오지영", "한가희", "양성민", "김동현", "이창모", "임규민" };
	S.Table["김은채"] = vector <string>{ "김은호", "이하늘", "김나영", "김동현", "이혜림", "김정은", "김서영", "강미주", "강희원", "임규민", "김민기", "민경환", "이수빈", "이창모", "양성민", "이성우", "윤다영", "오지영", "예링", "고병찬", "한가희" };
	S.Table["이하늘"] = vector <string>{ "이수빈", "김민기", "김은채", "민경환", "김은호", "임규민", "윤다영", "이창모", "김서영", "오지영", "양성민", "이성우", "김나영", "김정은", "강미주", "예링", "한가희", "이혜림", "김동현", "고병찬", "강희원" };
	
	dict[0] = "윤다영";
	dict[1] = "강미주";
	dict[2] = "고병찬";
	dict[3] = "이창모";
	dict[4] = "이성우";
	dict[5] = "김동현";
	dict[6] = "예링";
	dict[7] = "김정은";
	dict[8] = "민경환";
	dict[9] = "한가희";
	dict[10] = "강희원";
	dict[11] = "임규민";
	dict[12] = "김은호";
	dict[13] = "김민기";
	dict[14] = "오지영";
	dict[15] = "이혜림";
	dict[16] = "김나영";
	dict[17] = "양성민";
	dict[18] = "이수빈";
	dict[19] = "김서영";
	dict[20] = "김은채";	
	dict[21] = "이하늘";


	N = dict.size();
	V = new vector<int>[N];

	map<string, bool> received; //vs라 22 하드코딩함
	map<string, string> proposer;
	
	stack<string> fr;

	for (int i = N - 1; i >= 0; i--) //initialize
		fr.push(Table_keys[i]);


	while (!fr.empty())
	{
		string s_top = fr.top();
		//cout << "s_top: " << s_top << endl;
		string receiver = S.Table[s_top][0];
		bool flag = false;

		fr.pop();

		if (received[receiver] == false)
		{//선호가 겹치지 않을 때
			received[receiver] = true;
			proposer[receiver] = s_top;
		}
		else
		{//선호가 겹칠 때, 프로포즈 받은 상대에게서 더 높은 선호를 가진 사람을 결정
			int count = 0;
			string to_be_deleted = "";
			string store_string = "";


			for (auto iter = S.Table[receiver].begin(); iter != S.Table[receiver].end();)
			{
				if (count != 2)
				{//더 높은 선호를 가진 사람을 못 찾음
					if (*iter == proposer[receiver] || *iter == s_top)
					{
						count++;
						//cout << "receiver: " << receiver << " and count : " << count << endl;

						//cout << *iter << endl;

						if (count == 1)//receiver의 선호 중 더 높게 선호되는 사람
							store_string = *iter;
						
						if (count == 2)//receiver의 선호 중 더 낮게 선호되는 사람
							to_be_deleted = *iter;
						
					}
					++iter;
					if (iter == S.Table[receiver].end())
						--iter;
				}
				else
				{
					proposer[receiver] = store_string;
					fr.push(to_be_deleted);

					for (auto iter = S.Table[to_be_deleted].begin(); iter != S.Table[to_be_deleted].end(); iter++)
					{
						if (*iter == receiver)
						{
							S.Table[to_be_deleted].erase(iter);
							break;
						}
					}

					for (auto iter = S.Table[receiver].begin(); iter != S.Table[receiver].end(); iter++)
					{
						if (*iter == to_be_deleted)
						{
							S.Table[receiver].erase(iter);
							break;
						}
					}

					flag = true;
				}
				if (flag == true)
					break;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		string str = Table_keys[i];
		cout << str << ": ";

		for (auto iter = S.Table[str].begin(); iter != S.Table[str].end(); iter++)
		{
			cout << *iter << " ";
		}
		cout << endl;
	}


	return 0;
}