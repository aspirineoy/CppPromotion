#pragma once
#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

class BaseData {
public:
	virtual ~BaseData(){

	}
};

template<typename T>
class Data :public BaseData {
public:
	Data(T data):mdata(data){}
	T ReturnData() {
		return mdata;
	}
private:
	T mdata;
};

class StackInfo
{
public:
	template<class T>
	void push(T data) {
		datas.push_back(make_shared<Data<T>>(data));
	}

	template<class T>
	void pop(T& data) {
		auto index = dynamic_cast<Data<T>&>(*datas.back());
		data = index.ReturnData;
		datas.pop_back();
	}

private:
	vector<BaseData*> datas;
};

