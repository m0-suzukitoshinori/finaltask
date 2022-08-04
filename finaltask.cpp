#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct Star {
	string p_name;
	float g_a;
	float h;
	float t_h;
	float d;
	float t_d;

	Star(const string& newP_name, float newG_a, float newH, float newT_h, float newD, float newT_d) : p_name(newP_name), g_a(newG_a), h(newH), t_h(newT_h), d(newD), t_d(newT_d) {}
};

float sr2 = 1.414;

float H(float a1, float b1) {
	float s1 = a1 * a1 / (4 * b1);
	return round(s1 * 100) / 100;
}

float T_h(float a2, float b2) {
	float s2 = a2 / (sr2 * b2);
	return round(s2 * 100) / 100;
}

float D(float a3, float b3) {
	float s3 = a3 * a3 / b3;
	return round(s3 * 100) / 100;
}

float T_d(float a4, float b4) {
	float s4 = sr2 * a4 / b4;
	return round(s4 * 100) / 100;
}

int main() {
	ifstream datafile("Planets'data.txt");

	vector<Star> vec;

	cout << "太陽系の各惑星表面で，入力された速さで地面から45度の方向に質点の物体を投げたときの鉛直方向の最高点とその到達時間，投げた物体が地面の高さと同じになるときの水平移動距離とその到達時間を表示します．" << endl;
	cout << "任意の物体の投げたときの速さ[V(m/s)≧0]を入力して，ENTERを押してください．\n" << endl;

	float v;
	cin >> v;

	if (v >= 0) {
		cout << "\n入力された速さ:" << "V = " << v << "m/s\n" << endl;

		string P_name;
		float G_a;
		int i = 0;

		while (datafile >> P_name >> G_a) {
			vec.emplace_back(P_name, G_a, H(v, G_a), T_h(v, G_a), D(v, G_a), T_d(v, G_a));
			++i;
		}

		cout << "太陽系の内側順\n";
		for (const auto& q : vec) {
			cout << "惑星名:" << q.p_name << "\n　重力加速度:" << q.g_a << "m/s^2" << "\n　最高点:" << q.h << "m" << " 到達時刻;" << q.t_h << "s" << "\n　水平到達距離:" << q.d << "m" << " 到達時刻;" << q.t_d << "s\n" << endl;
		}

		cout << "水平移動距離が小さい順に並び替える場合はsmallと入力し，ENTERを押してください．\n";
		cout << "不要な場合は任意の別の文字列を入力してください．\n" << endl;

		string as;
		cin >> as;

		cout << endl;

		if (as == "small") {
			sort(vec.begin(), vec.end(), [](Star& x, Star& y) { return x.d < y.d; });

			size_t s = vec.size();

			cout << "水平移動距離が小さい順\n";
			for (const auto& q : vec) {
				cout << "惑星名:" << q.p_name << "\n　重力加速度:" << q.g_a << "m/s^2" << "\n　最高点:" << q.h << "m" << " 到達時刻;" << q.t_h << "s" << "\n　水平到達距離:" << q.d << "m" << " 到達時刻;" << q.t_d << "s\n" << endl;
			}
		}
	}

	else cout << "\n不適当な数字です．\n" << endl;

	cout << "終了\n";
}