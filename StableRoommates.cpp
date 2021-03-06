#include<iostream>
#include<set>
#include<map>
#include<cstring>
#include<string>
#include<vector>
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

int main(void) {
    StableRoommates S;
    S.Table["���ٿ�"] = vector <string>{ "������", "�̼���", "����", "�̼���", "�Ѱ���", "�缺��", "������", "������", "�ӱԹ�", "��â��", "���ϴ�", "��α�", "�����", "������", "������", "�ΰ�ȯ", "����ȣ", "�輭��", "�赿��", "�質��", "����ä" };
    S.Table["������"] = vector <string>{ "�赿��", "�̼���", "�ӱԹ�", "������", "�̼���", "������", "����ȣ", "�����", "�缺��", "��â��", "������", "�質��", "�輭��", "���ϴ�", "����", "�Ѱ���", "���ٿ�", "����ä", "��α�", "�ΰ�ȯ", "������" };
    S.Table["������"] = vector <string>{ "�̼���", "����", "������", "�缺��", "���ٿ�", "��α�", "�̼���", "��â��", "�����", "������", "�Ѱ���", "�ӱԹ�", "������", "�輭��", "�ΰ�ȯ", "������", "���ϴ�", "�質��", "�赿��", "����ȣ", "����ä" };
    S.Table["��â��"] = vector <string>{ "�缺��", "�̼���", "����", "�ӱԹ�", "������", "�̼���", "������", "�ΰ�ȯ", "���ٿ�", "���ϴ�", "�Ѱ���", "������", "������", "�����", "��α�", "�赿��", "������", "����ȣ", "�質��", "����ä", "�輭��" };
    S.Table["�̼���"] = vector <string>{ "������", "����", "�̼���", "������", "��α�", "�缺��", "���ٿ�", "��â��", "�Ѱ���", "�ӱԹ�", "�����", "������", "������", "������", "�ΰ�ȯ", "���ϴ�", "�質��", "�輭��", "�赿��", "����ȣ", "����ä" };
    S.Table["�赿��"] = vector <string>{ "������", "������", "������", "�ӱԹ�", "�̼���", "����ȣ", "����ä", "�����", "�質��", "�缺��", "��â��", "�̼���", "���ϴ�", "�Ѱ���", "���ٿ�", "������", "����", "������", "��α�", "�ΰ�ȯ", "�輭��" };
    S.Table["����"] = vector <string>{ "������", "�̼���", "���ٿ�", "������", "�̼���", "��â��", "�缺��", "�����", "�Ѱ���", "��α�", "�ΰ�ȯ", "������", "�ӱԹ�", "������", "���ϴ�", "������", "����ȣ", "�赿��", "�質��", "�輭��", "����ä" };
    S.Table["������"] = vector <string>{ "�����", "������", "������", "�赿��", "�̼���", "���ٿ�", "����", "�̼���", "����ȣ", "������", "��â��", "�Ѱ���", "�缺��", "�質��", "����ä", "������", "���ϴ�", "�ӱԹ�", "�輭��", "�ΰ�ȯ", "��α�" };
    S.Table["�ΰ�ȯ"] = vector <string>{ "��α�", "���ϴ�", "����", "������", "��â��", "�̼���", "�̼���", "����ȣ", "�質��", "�Ѱ���", "�����", "�缺��", "�ӱԹ�", "���ٿ�", "������", "������", "�輭��", "������", "����ä", "�赿��", "������" };
    S.Table["�Ѱ���"] = vector <string>{ "�̼���", "������", "���ٿ�", "�̼���", "����", "�����", "������", "��â��", "�ΰ�ȯ", "�缺��", "��α�", "�ӱԹ�", "������", "������", "���ϴ�", "�赿��", "������", "����ȣ", "�輭��", "�質��", "����ä" };
    S.Table["�����"] = vector <string>{ "������", "������", "����", "������", "�̼���", "�赿��", "�̼���", "�Ѱ���", "����ȣ", "������", "�質��", "���ٿ�", "��â��", "������", "�ΰ�ȯ", "�缺��", "����ä", "�ӱԹ�", "��α�", "���ϴ�", "�輭��" };
    S.Table["�ӱԹ�"] = vector <string>{ "�缺��", "�̼���", "��â��", "������", "�赿��", "�̼���", "���ٿ�", "���ϴ�", "����", "������", "������", "��α�", "�Ѱ���", "������", "����ȣ", "������", "�ΰ�ȯ", "�����", "�質��", "����ä", "�輭��" };
    S.Table["����ȣ"] = vector <string>{ "�質��", "����ä", "���ϴ�", "��α�", "�赿��", "������", "������", "������", "�̼���", "�ΰ�ȯ", "�����", "�輭��", "�ӱԹ�", "�̼���", "������", "�缺��", "���ٿ�", "����", "��â��", "�Ѱ���", "������" };
    S.Table["��α�"] = vector <string>{ "�ΰ�ȯ", "�̼���", "���ϴ�", "�質��", "����", "�̼���", "����ȣ", "������", "�缺��", "������", "�輭��", "���ٿ�", "��â��", "�Ѱ���", "�ӱԹ�", "�����", "������", "������", "����ä", "������", "�赿��" };
    S.Table["������"] = vector <string>{ "����", "���ٿ�", "�̼���", "�̼���", "�Ѱ���", "��â��", "�����", "������", "�缺��", "������", "�ΰ�ȯ", "��α�", "�ӱԹ�", "���ϴ�", "������", "������", "����ȣ", "�赿��", "�輭��", "�質��", "����ä" };
    S.Table["������"] = vector <string>{ "�赿��", "������", "������", "�質��", "�����", "�̼���", "����ȣ", "�̼���", "����ä", "�ӱԹ�", "�缺��", "������", "���ٿ�", "�輭��", "���ϴ�", "��â��", "����", "������", "�Ѱ���", "��α�", "�ΰ�ȯ" };
    S.Table["�質��"] = vector <string>{ "����ȣ", "��α�", "����ä", "������", "�赿��", "�ΰ�ȯ", "�����", "�輭��", "������", "���ϴ�", "������", "�̼���", "�̼���", "�ӱԹ�", "�缺��", "������", "����", "��â��", "������", "�Ѱ���", "���ٿ�" };
    S.Table["�缺��"] = vector <string>{ "�ӱԹ�", "��â��", "�̼���", "�̼���", "����", "���ٿ�", "������", "������", "��α�", "������", "������", "���ϴ�", "�ΰ�ȯ", "������", "�Ѱ���", "�����", "�赿��", "�質��", "����ȣ", "����ä", "�輭��" };
    S.Table["�̼���"] = vector <string>{ "�̼���", "�Ѱ���", "�ӱԹ�", "���ٿ�", "������", "�缺��", "������", "����", "��â��", "���ϴ�", "������", "�赿��", "��α�", "������", "�����", "������", "�ΰ�ȯ", "����ȣ", "�質��", "�輭��", "����ä" };
    S.Table["�輭��"] = vector <string>{ "��α�", "���ϴ�", "�質��", "������", "����ȣ", "�̼���", "������", "����ä", "������", "������", "�ΰ�ȯ", "�̼���", "�����", "���ٿ�", "����", "������", "�Ѱ���", "�缺��", "�赿��", "��â��", "�ӱԹ�" };
    S.Table["����ä"] = vector <string>{ "����ȣ", "���ϴ�", "�質��", "�赿��", "������", "������", "�輭��", "������", "�����", "�ӱԹ�", "��α�", "�ΰ�ȯ", "�̼���", "��â��", "�缺��", "�̼���", "���ٿ�", "������", "����", "������", "�Ѱ���" };
    S.Table["���ϴ�"] = vector <string>{ "�̼���", "��α�", "����ä", "�ΰ�ȯ", "����ȣ", "�ӱԹ�", "���ٿ�", "��â��", "�輭��", "������", "�缺��", "�̼���", "�質��", "������", "������", "����", "�Ѱ���", "������", "�赿��", "������", "�����" };
}