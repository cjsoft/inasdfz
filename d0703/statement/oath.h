#ifndef __EXPR_H__
#define __EXPR_H__

#ifdef __cplusplus
extern "C" {
#endif
struct Data
{
	int x;
	Data(){}
	Data(const int &_x):x(_x){}
};

Data F(const Data &a,const Data &b);
void Init();
void Add_element(int id,Data x);
void Del_element(int id);
Data Query_range(int id,int l,int r);
#ifdef __cplusplus
}
#endif

#endif
