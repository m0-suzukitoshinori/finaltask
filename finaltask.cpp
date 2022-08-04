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

	cout << "���z�n�̊e�f���\�ʂŁC���͂��ꂽ�����Œn�ʂ���45�x�̕����Ɏ��_�̕��̂𓊂����Ƃ��̉��������̍ō��_�Ƃ��̓��B���ԁC���������̂��n�ʂ̍����Ɠ����ɂȂ�Ƃ��̐����ړ������Ƃ��̓��B���Ԃ�\�����܂��D" << endl;
	cout << "�C�ӂ̕��̂̓������Ƃ��̑���[V(m/s)��0]����͂��āCENTER�������Ă��������D\n" << endl;

	float v;
	cin >> v;

	if (v >= 0) {
		cout << "\n���͂��ꂽ����:" << "V = " << v << "m/s\n" << endl;

		string P_name;
		float G_a;
		int i = 0;

		while (datafile >> P_name >> G_a) {
			vec.emplace_back(P_name, G_a, H(v, G_a), T_h(v, G_a), D(v, G_a), T_d(v, G_a));
			++i;
		}

		cout << "���z�n�̓�����\n";
		for (const auto& q : vec) {
			cout << "�f����:" << q.p_name << "\n�@�d�͉����x:" << q.g_a << "m/s^2" << "\n�@�ō��_:" << q.h << "m" << " ���B����;" << q.t_h << "s" << "\n�@�������B����:" << q.d << "m" << " ���B����;" << q.t_d << "s\n" << endl;
		}

		cout << "�����ړ����������������ɕ��ёւ���ꍇ��small�Ɠ��͂��CENTER�������Ă��������D\n";
		cout << "�s�v�ȏꍇ�͔C�ӂ̕ʂ̕��������͂��Ă��������D\n" << endl;

		string as;
		cin >> as;

		cout << endl;

		if (as == "small") {
			sort(vec.begin(), vec.end(), [](Star& x, Star& y) { return x.d < y.d; });

			size_t s = vec.size();

			cout << "�����ړ���������������\n";
			for (const auto& q : vec) {
				cout << "�f����:" << q.p_name << "\n�@�d�͉����x:" << q.g_a << "m/s^2" << "\n�@�ō��_:" << q.h << "m" << " ���B����;" << q.t_h << "s" << "\n�@�������B����:" << q.d << "m" << " ���B����;" << q.t_d << "s\n" << endl;
			}
		}
	}

	else cout << "\n�s�K���Ȑ����ł��D\n" << endl;

	cout << "�I��\n";
}