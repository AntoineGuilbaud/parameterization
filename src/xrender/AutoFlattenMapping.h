/*
###############################################################
Created on Sat May 11 16:07:02 2015
:author: Er Li {lier198631@126.com}
###############################################################
*/

#ifndef __AUTOFLATTENMAPPING_H__
#define __AUTOFLATTENMAPPING_H__

#define DDF_DEBUG 1

#include <assert.h>
#include "declare.h"
#include <vector>
#include <map>
#include "vector.h"

using namespace std;

struct CFace
{
	int v[3];
};

class VEC2
{
public:
	union
	{
		struct 
		{
			float x, y;//!<������Real���ͱ�������ʾһ����ά������  
		};
		struct 
		{
			float u, v;//!<������Real���ͱ�������ʾһ����ά������
		};
		float m[2];//!<��һ����������ʾһ����ά������
	};

	VEC2 (const float x, const float y)
	{
		this->x = x;
		this->y = y;
	}
};

typedef BasicVector::Vector3Dim<float> VEC3;



class  DEVICE_API UVfun
{
public:
	UVfun();
	~UVfun();

	/* �Զ�չUV���� AutoMapping
	 * pVertices�����붥�����ꣻ pFaces��������Ƭ��Ϣ�� pUVs:���UV���ꣻUVIndex�����meshÿ�����Ӧ��UV������angle��չƽ�Ƕȣ�Ĭ�� 45��,���90�ȣ��Ƕ�ԽС���ָ�Խ���飻 margin:������ֵ����Χ0.0 ��1.0,Ĭ��0.02��
	 */

	static void AutoMapping(vector <VEC3>  &pVertices, vector<CFace> &pFaces, vector<VEC2> &pUVs,vector<CFace>& UVIndex, bool use_LSCM = false, float angle = 45.0,float margin = 0.02);


	/* �Զ�չUV���� BoxMapping
	 * pVertices�����붥�����ꣻ pFaces��������Ƭ��Ϣ�� pUVs:���UV���ꣻUVIndex�����meshÿ�����Ӧ��UV������margin:������ֵ����Χ0.0 ��1.0,Ĭ��0.02��
	 */

	static void BoxMapping(vector <VEC3>  &pVertices, vector<CFace> &pFaces, vector<VEC2> &pUVs,vector<CFace>& UVIndex, bool use_LSCM = false, float margin = 0.02);
	


};



#endif
