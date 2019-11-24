#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;
double evaluate(int degree, vector<int> coefficient, double val){
	vector<double> powers;
	double ans = 0;
	powers.push_back(1);
	for (int i = 0; i < degree; i++) {
		powers.push_back(val*powers.back());
	}
	for (int i = 0; i <= degree; i++) {
		ans += coefficient[i] * powers[degree-i];
	}
	return ans;

}
vector<int> factors(int num){
	vector<int> ans;
	if (num < 0) {
		num*=-1;
	}
	for (int i = 1; i <= num; i++) {
		if (num % i == 0) {
			ans.push_back(i);
		}
	}
	return ans;
}
int main(int argc, char const *argv[]) {
	int degree = 0;
	double temp;
	vector<int> coefficient;
	vector<pair<int,int>> final;

	vector<int> p;
	vector<int> q;
	map<double, pair<int,int>> pdivq;
	cout<<"enter degree:" << endl;
	cin>>degree;
	while (degree <= 0){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout<<"enter degree:" << endl;
		cin>>degree;
	}

	cout<<"enter coefficients:" << endl;
	for (int i = 0; i <= degree; i++) {
		cin>>temp;
		coefficient.push_back(temp);
	}
	p = factors(coefficient.back());
	q = factors(coefficient.front());

	cout<<"p: ±";
	for (int i = 0; i < p.size(); i++) {
		cout<<p[i] << ' ';
	}
	cout<< endl;
	cout<<"q: ±";
	for (int i = 0; i < q.size(); i++) {
		cout<<q[i] << ' ';
	}
	cout<< endl;

	for (int i = 0; i < p.size(); i++) {
		for (int j = 0; j < q.size(); j++) {
			double quo = (double)p[i]/(double)q[j];
			if (pdivq.count(quo) == 0) {
				pdivq[quo] = make_pair(p[i],q[j]);
			}
		}
	}

	cout<<"p/q: ±";
	for (map<double, pair<int,int>>::iterator it = pdivq.begin(); it != pdivq.end(); it++) {
		if (it->second.second==1) {
			cout<<it->second.first<< ' ';
		}else{
			cout<<it->second.first<<'/'<<it->second.second << ' ';
		}
	}
	cout << endl;

	// for (map<double, pair<int,int>>::iterator it = pdivq.begin(); it != pdivq.end(); it++) {
	// 	cout<<it->first<< ':'<< evaluate(degree,coefficient,it->first) << ' '
	// 	<< evaluate(degree,coefficient,it->first *-1)<< endl;
	// }
	for (map<double, pair<int,int>>::iterator it = pdivq.begin(); it != pdivq.end(); it++) {
		//improve by storing evaluate
		if (evaluate(degree,coefficient,it->first) <= 0.001 &&
		evaluate(degree,coefficient,it->first) >= -0.001) {
			final.push_back(it->second);
		}
		if (evaluate(degree,coefficient,it->first*-1) <= 0.01 &&
		evaluate(degree,coefficient,it->first*-1) >= -0.01) {
			final.push_back(make_pair(it->second.first *-1, it->second.second));
		}
	}
	cout << endl;
	if (final.empty()) {
		cout<<"no rational solutions!";
	}else{
		cout<<"rational solutions: ";
	}
	for (int i = 0; i < final.size(); i++) {
		if (final[i].second == 1) {
			cout<< final[i].first << ' ';
		}else{
			cout<< final[i].first << '/' << final[i].second << ' ';
		}
	}
	cout << endl;
	// system("pause");
	return 0;
}
/*
1 7 -9 -63
6 -38 12 -15 95 -30
*/
